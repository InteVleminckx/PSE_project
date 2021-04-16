/*
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "../Header_files/FileParser.h"
//#include "../Header_files/Hub.h"

int FileParser::parseFile(string &file) {

    if(!fDoc.LoadFile(file.c_str())) {
        cout << endl;
        std::cerr << fDoc.ErrorDesc() << std::endl;
        cout << endl;
        return 1;
    }

    fRoot = fDoc.FirstChildElement();

    if(fRoot == NULL) {
        std::cerr << "Failed to load file: No fRoot element." << std::endl;
        fDoc.Clear();
        return 1;
    }
    _initCheck = this;
    parseXML();
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    return 0;
}

void FileParser::parseXML() {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling parseXML");

    testOutput.open("../test-bestanden/testOutput.txt"); // openen bestand waar we errors naar gaan schrijven.


    vector<Hub> test;

    int HUBcounter = 0; // count het aantal HUB's
    for (TiXmlElement *elem = fRoot->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {

        string elemName = elem->Value();

        if(elemName == "HUB") {

            Hub* newHub = new Hub;

            HUBcounter++;

//            REQUIRE((HUBcounter == 1), "Het aantal hubs mag niet meer zijn dan 1.");

            for (TiXmlNode* elem1 = elem->FirstChild(); elem1 != NULL; elem1 = elem1->NextSiblingElement()) {

                string element = elem1->Value();

                if (element == "VACCIN"){

                    Utils::checkTags(elem, true, testOutput);

                    TiXmlNode* type = elem1->FirstChild("type")->FirstChild();
                    TiXmlNode* levering = elem1->FirstChild("levering")->FirstChild();
                    TiXmlNode* interval = elem1->FirstChild("interval")->FirstChild();
                    TiXmlNode* transport = elem1->FirstChild("transport")->FirstChild();
                    TiXmlNode* hernieuwing = elem1->FirstChild("hernieuwing")->FirstChild();
                    TiXmlNode* temperatuur = elem1->FirstChild("temperatuur")->FirstChild();

                    Utils::checkValues(elem, elem1, true, testOutput);

                    string typeString = type->Value();
                    int leveringInt = atoi(levering->Value());
                    int intervalInt = atoi(interval->Value());
                    int transportInt = atoi(transport->Value());
                    int hernieuwingInt = atoi(hernieuwing->Value());
                    int temperatuurInt = atoi(temperatuur->Value());

                    Vaccin* newVaccin = new Vaccin(typeString, leveringInt, intervalInt,
                        transportInt, hernieuwingInt, temperatuurInt);

                    newHub->fVaccins.push_back(newVaccin);

                }
                else if(element == "CENTRA"){

                    TiXmlNode* CENTRA = elem->FirstChildElement("CENTRA");

                    for (TiXmlNode* elementCentra = CENTRA->FirstChild(); elementCentra != NULL;
                         elementCentra = elementCentra->NextSiblingElement()){

                        if (!Utils::isAlpha(elementCentra->FirstChild()->Value())){
                            testOutput << "Naam van een centrum moet een string zijn.\n";
                        }

                        string naam = elementCentra->FirstChild()->Value();
                        Vaccinatiecentrum* CENTRUM = new Vaccinatiecentrum;
                        CENTRUM->setNaam(naam);
                        newHub->fHubCentra.push_back(CENTRUM);
                    }
                }

                else {
                    testOutput << "Geen correcte input voor de tag.\n";
                    Utils::checkTags(elem, true, testOutput);
                    Utils::checkValues(elem, elem1, true, testOutput);
                }
            }

            REQUIRE((!newHub->fHubCentra.empty()), "Er moet minstens 1 vaccininatiecentrum zijn.");
            fHubs.push_back(newHub);
        }
        else if (elemName == "VACCINATIECENTRUM"){

            Utils::checkTags(elem, false, testOutput);

            for (TiXmlNode* element = elem->FirstChild(); element != NULL;
                 element = element->NextSiblingElement()){

                if (!Utils::isLittleAlpha(element->Value())){
                    testOutput << "Childtags moeten in kleine letters.\n";
                }
            }

            TiXmlNode* naam = elem->FirstChild("naam")->FirstChild();
            TiXmlNode* adres = elem->FirstChild("adres")->FirstChild();
            TiXmlNode* inwoners = elem->FirstChild("inwoners")->FirstChild();
            TiXmlNode* capaciteit = elem->FirstChild("capaciteit")->FirstChild();

            Utils::checkValues(elem, NULL, false, testOutput);

            string adresString = adres->Value();
            int inwonersInt = atoi(inwoners->Value());
            int capaciteitInt = atoi(capaciteit->Value());

            for (unsigned int i = 0; i < fHubs.size(); i++) {
                fHubs[i]->VCcounter++;
                setCentrumInformation(i, naam, adresString, inwonersInt, capaciteitInt);
            }
        }

        else{
            testOutput << "Geen correcte input voor de tag.\n";
            Utils::checkTags(elem, false, testOutput);
            Utils::checkValues(elem, NULL, false, testOutput);
        }
    }

//    ENSURE((HUBcounter == 1), "Er moet precies 1 HUB zijn.");
//    ENSURE((VCcounter == fCentra.size()), "Het aantal vaccinatiecentra komt niet overeen met het aantal opgegeven fCentra in het begin.");
    for (unsigned int i = 0; i < fHubs.size(); i++) {
        if (fHubs[i]->VCcounter != (int) fHubs[i]->fHubCentra.size()) {
            testOutput << "Het aantal vaccinatiecentra komt niet overeen met het aantal opgegeven centra in het begin.\n";
        }
    }

}

void FileParser::setCentrumInformation(unsigned int i, TiXmlNode* naam, string &adresString, int inwonersInt, int capaciteitInt) {

    for (unsigned int j = 0; j < fHubs[i]->fHubCentra.size(); j++) {
        if (fHubs[i]->fHubCentra[j]->getNaam() == naam->Value()) {
            fHubs[i]->fHubCentra[j]->setAdres(adresString);
            fHubs[i]->fHubCentra[j]->setInwoners(inwonersInt);
            fHubs[i]->fHubCentra[j]->setCapaciteit(capaciteitInt);
            for (unsigned int k = 0; k < fHubs[i]->fVaccins.size(); ++k) {
                string type = fHubs[i]->fVaccins[k]->getType();
                fHubs[i]->fHubCentra[j]->setVaccins(0, type);
            }
            fHubs[i]->fHubCentra[j]->setVaccinatedFirstTime(0);
            fHubs[i]->fHubCentra[j]->setVaccinatedSecondTime(0);
        }
    }

}

void FileParser::uitvoer(bool begin) {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling uitvoer");

    //aanmaken uitvoer bestand
    ofstream Output;

    if (begin){
        //openen van het uitvoerbestand
        Output.open("../simulatieOutput/uitvoerBegin.txt");
    }

    else {
        //openen van het uitvoerbestand
        Output.open("../simulatieOutput/uitvoerEinde.txt");
    }

    //zolang de file open is
    if (Output.is_open())
    {
        //schrijven een string weg in het uitvoer bestand
        for (unsigned int i = 0; i < fHubs.size(); i++) {

            Output << "Hub " << i << ": Vaccins ( ";
            for (unsigned int j = 0; j < fHubs[i]->fVaccins.size(); j++){
                Output << fHubs[i]->fVaccins[j]->getType() << ": [" << fHubs[i]->fVaccins[j]->getAantalVaccins() << "] ";
            }

            Output << ")\n";

            for (unsigned int j = 0; j < fHubs[i]->fHubCentra.size(); j++) {
                //schrijven een string weg in het uitvoer bestand

                map<string, int> vaccinsInCentrum = fHubs[i]->fHubCentra[j]->getVaccinsInCentrum();

//                Output << "\t-> " << fHubs[i]->fHubCentra[j]->getNaam() << " (" << fHubs[i]->fHubCentra[j]->getVaccins(type) << " vaccins)""\n";
                Output << "\t-> " << fHubs[i]->fHubCentra[j]->getNaam() << ": Vaccins ( ";
                for (map<string, int>::iterator it = vaccinsInCentrum.begin(); it != vaccinsInCentrum.end(); it++){
                    Output << it->first << ": [" << it->second << "] ";
                }
                Output << ")\n";

            }
            //wit regel in het bestand
            Output << "\n";
            //lopen terug over de fCentra
            for (unsigned int j = 0; j < fHubs[i]->fHubCentra.size(); j++) {
                //berekenen het aantal niet gevaccineerden
                int aantalNietGevaccineerden = fHubs[i]->fHubCentra[j]->getInwoners() -
                        fHubs[i]->fHubCentra[j]->getVaccinatedFirstTime();
                //schrijven dit weg in het output bestand
                Output << fHubs[i]->fHubCentra[j]->getNaam() << ": " << fHubs[i]->fHubCentra[j]->getVaccinatedFirstTime() << " gevaccineerd, nog " <<
                       aantalNietGevaccineerden << " niet gevaccineerd\n";
            }

            Output << "\n";

        }
        //lopen over alle fCentra

        //we sluiten de file
        Output.close();
    }
    else cerr << "Unable to open file";
}

bool FileParser::properlyInitialized() {

    return _initCheck == this;
}


//bool FileParser::isDigit(const string &str) {
//    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isDigit");
//
//    for (unsigned int i = 0; i < str.size(); ++i) {
//        if (!isdigit(str[i])) {
//            return false;
//        }
//    }
//    return true;
//}
//
//bool FileParser::isAlpha(const string &str) {
//    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isAlpha");
//
//    for (unsigned int i = 0; i < str.size(); ++i) {
//        if (str[i] != 32 ){
//            if (!(isalpha(str[i]))) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool FileParser::isAlphaNum(const string &str) {
//    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isAlphaNum");
//
//    for (unsigned int i = 0; i < str.size(); ++i) {
//        if (str[i] != 32 && str[i] != 44 && str[i] != 45) {
//            if (!isalnum(str[i])) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool FileParser::isTag(const string &tag, TiXmlElement *elem, bool isFirstchildElement) {
//    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isTag");
//    const char *tagString = tag.c_str();
//
//    if (elem->FirstChildElement()->FirstChild(tagString) == NULL && isFirstchildElement == true){
//        return false;
//    }
//    if (elem->FirstChild(tagString) == NULL && isFirstchildElement == false){
//        return false;
//    }
//    return true;
//}
//
//bool FileParser::isLittleAlpha(const string &str) {
//    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isLittleAlpha");
//
//    for (unsigned int i = 0; i < str.size(); ++i) {
//        if (str[i] != 32 ){
//            if (str[i] < 'a' || 'z' < str[i]) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//bool FileParser::isCorrectTemperature(const string &str) {
//    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isCorrectTemperature");
//
//    //negatief
//    if (str[0] == '-'){
//        string strN;
//        for (int i = 1; i < str.size(); ++i) strN.push_back(str[i]);
//        return Utils::isDigit(strN);
//    }
//
//    //positief
//    else return Utils::isDigit(str);
//
//}


//void FileParser::checkTags(TiXmlElement *elem, bool isFirstchildElement) {
//    if (isFirstchildElement) {
//
//        if (!Utils::isTag("type", elem, true)) {
//            testOutput << "Tag \"type\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("levering", elem, true)) {
//            testOutput << "Tag \"levering\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("interval", elem, true)) {
//            testOutput << "Tag \"interval\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("transport", elem, true)) {
//            testOutput << "Tag \"transport\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("hernieuwing", elem, true)) {
//            testOutput << "Tag \"hernieuwing\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("temperatuur", elem, true)) {
//            testOutput << "Tag \"temperatuur\" niet gevonden.\n";
//        }
//
//    }
//
//    else{
//        if (!Utils::isTag("naam", elem, false)) {
//            testOutput << "Tag \"naam\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("adres", elem, false)) {
//            testOutput << "Tag \"adres\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("inwoners", elem, false)) {
//            testOutput << "Tag \"inwoners\" niet gevonden.\n";
//        }
//        if (!Utils::isTag("capaciteit", elem, false)) {
//            testOutput << "Tag \"capaciteit\" niet gevonden.\n";
//        }
//    }
//}
//
//void FileParser::checkValues(TiXmlElement *elem, TiXmlNode *elem1, bool isVaccins) {
//
//    if (isVaccins){
//
//        TiXmlNode* type = elem1->FirstChild("type")->FirstChild();
//        TiXmlNode* levering = elem1->FirstChild("levering")->FirstChild();
//        TiXmlNode* interval = elem1->FirstChild("interval")->FirstChild();
//        TiXmlNode* transport = elem1->FirstChild("transport")->FirstChild();
//        TiXmlNode* hernieuwing = elem1->FirstChild("hernieuwing")->FirstChild();
//        TiXmlNode* temperatuur = elem1->FirstChild("temperatuur")->FirstChild();
//
//        if (!Utils::isAlpha(type->Value())){
//            testOutput << "Type van een vaccin moet een string zijn.\n";
//        }
//
//        if (!Utils::isDigit(levering->Value())){
//            testOutput << "Levering moet een positieve integer zijn.\n";
//        }
//
//        if (!Utils::isDigit(interval->Value())){
//            testOutput << "Interval moet een positieve integer zijn.\n";
//        }
//
//        if (!Utils::isDigit(transport->Value())){
//            testOutput << "Transport moet een positieve integer zijn.\n";
//        }
//
//        if (!Utils::isDigit(hernieuwing->Value())){
//            testOutput << "Hernieuwing moet een positieve integer zijn.\n";
//        }
//
//        if (!Utils::isCorrectTemperature(temperatuur->Value())){
//            testOutput << "Temperatuur moet een positieve of negatief integer zijn.\n";
//        }
//
//    }
//
//    else{
//
//        TiXmlNode* naam = elem->FirstChild("naam")->FirstChild();
//        TiXmlNode* adres = elem->FirstChild("adres")->FirstChild();
//        TiXmlNode* inwoners = elem->FirstChild("inwoners")->FirstChild();
//        TiXmlNode* capaciteit = elem->FirstChild("capaciteit")->FirstChild();
//
//        if (!Utils::isAlpha(naam->Value())){
//            testOutput << "Naam van een centrum moet een string zijn.\n";
//        }
//        if (!Utils::isAlphaNum(adres->Value())){
//            testOutput << "Adres moet bestaan uit een string (en integers).\n";
//        }
//        if (!Utils::isDigit(inwoners->Value())){
//            testOutput << "Inwoners moet een positieve integer zijn.\n";
//        }
//        if (!Utils::isDigit(capaciteit->Value())){
//            testOutput << "Capaciteit moet een positieve integer zijn.\n";
//        }
//    }
//
//
//}




