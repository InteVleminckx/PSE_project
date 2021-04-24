/*
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "../Header_files/FileParser.h"
//#include "../Header_files/Hub.h"

int FileParser::parseFile(string &file) {
    _initCheck = this;
    testOutput.open("../test-bestanden/testOutput.txt"); // openen bestand waar we errors naar gaan schrijven.

    if(!fDoc.LoadFile(file.c_str())) {
        testOutput << fDoc.ErrorDesc() << std::endl;
        return 1;
    }

    fRoot = fDoc.FirstChildElement();

    if(fRoot == NULL) {
        testOutput << "Failed to load file: No fRoot element." << std::endl;
        fDoc.Clear();
        return 1;
    }

    parseXML();
    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
    testOutput.close();
    return 0;
}

void FileParser::parseXML() {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling parseXML");

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

                    vector<bool> isTags = Utils::checkTags(elem, true, testOutput, elem1); // checkt of de tags aanwezig zijn
                    TiXmlNode* type = NULL;
                    TiXmlNode* levering = NULL;
                    TiXmlNode* interval = NULL;
                    TiXmlNode* transport = NULL;
                    TiXmlNode* hernieuwing = NULL;
                    TiXmlNode* temperatuur = NULL;

                    if (isTags[0])
                    {
                        type = elem1->FirstChild("type")->FirstChild();
                    }
                    if (isTags[1])
                    {
                        levering = elem1->FirstChild("levering")->FirstChild();
                    }
                    if (isTags[2])
                    {
                        interval = elem1->FirstChild("interval")->FirstChild();
                    }
                    if (isTags[3])
                    {
                        transport = elem1->FirstChild("transport")->FirstChild();
                    }
                    if (isTags[4])
                    {
                        hernieuwing = elem1->FirstChild("hernieuwing")->FirstChild();
                    }
                    if (isTags[5])
                    {
                        temperatuur = elem1->FirstChild("temperatuur")->FirstChild();
                    }

                    vector<bool> isValue = Utils::checkValues(elem, elem1, true, testOutput, isTags);

                    // default
                    string typeString = "type";
                    int leveringInt = 1;
                    int intervalInt = 1;
                    int transportInt = 1;
                    int hernieuwingInt = 0;
                    int temperatuurInt = 0;

                    if (isValue[0])
                    {
                        typeString = type->Value();
                    }
                    if (isValue[1])
                    {
                        leveringInt = atoi(levering->Value());
                    }
                    if (isValue[2])
                    {
                        intervalInt = atoi(interval->Value());
                    }
                    if (isValue[3])
                    {
                        transportInt = atoi(transport->Value());
                    }
                    if (isValue[4])
                    {
                        hernieuwingInt = atoi(hernieuwing->Value());
                    }
                    if (isValue[5])
                    {
                        temperatuurInt = atoi(temperatuur->Value());
                    }

                    Vaccin* newVaccin = new Vaccin(typeString, leveringInt, intervalInt,
                        transportInt, hernieuwingInt, temperatuurInt);

                    newHub->fVaccins.push_back(newVaccin);
                    newHub->setAantalGeleverdeVaccins(typeString, leveringInt);

                }
                else if(element == "CENTRA"){

                    TiXmlNode* CENTRA = elem->FirstChildElement("CENTRA");

                    for (TiXmlNode* elementCentra = CENTRA->FirstChild(); elementCentra != NULL;
                         elementCentra = elementCentra->NextSiblingElement()){

                        if (!Utils::isAlpha(elementCentra->FirstChild()->Value())){
                            testOutput << "Naam van een centrum moet een string zijn.\n";
                        }
                        else{
                            string naam = elementCentra->FirstChild()->Value();
                            Vaccinatiecentrum* CENTRUM = new Vaccinatiecentrum;
                            CENTRUM->setNaam(naam);
                            newHub->fHubCentra.push_back(CENTRUM);
                        }
                    }
                }

                else {
                    testOutput << "Geen correcte input voor de tag.\n";
                    vector<bool> isTags = Utils::checkTags(elem, true, testOutput, NULL); ////
                    Utils::checkValues(elem, elem1, true, testOutput, isTags);
                }
            }
            if (newHub->fHubCentra.empty()) {
                testOutput << "Er moet minstens 1 vaccinatiecentrum zijn.\n";
            }
//            REQUIRE((!newHub->fHubCentra.empty()), "Er moet minstens 1 vaccininatiecentrum zijn.");
            fHubs.push_back(newHub);
        }
        else if (elemName == "VACCINATIECENTRUM"){

            vector<bool> isTags = Utils::checkTags(elem, false, testOutput, NULL);

            TiXmlNode* naam = NULL;
            TiXmlNode* adres = NULL;
            TiXmlNode* inwoners = NULL;
            TiXmlNode* capaciteit = NULL;

            for (TiXmlNode* element = elem->FirstChild(); element != NULL;
                 element = element->NextSiblingElement()){

                if (!Utils::isLittleAlpha(element->Value())){
                    testOutput << "Childtags moeten in kleine letters.\n";
                }
            }

            if (isTags[0])
            {
                naam = elem->FirstChild("naam")->FirstChild();
            }
            if (isTags[1])
            {
                adres = elem->FirstChild("adres")->FirstChild();
            }
            if (isTags[2])
            {
                inwoners = elem->FirstChild("inwoners")->FirstChild();
            }
            if (isTags[3])
            {
                capaciteit = elem->FirstChild("capaciteit")->FirstChild();
            }

            vector<bool> isValue = Utils::checkValues(elem, NULL, false, testOutput, isTags);

            string naam1 = "naam";
            string adresString = "adres";
            int inwonersInt = 1;
            int capaciteitInt = 1;

            if (isValue[0]) {
                naam1 = naam->Value();
            }
            if (isValue[1]) {
                adresString = adres->Value();
            }
            if (isValue[2]) {
                inwonersInt = atoi(inwoners->Value());
            }
            if (isValue[3]) {
                capaciteitInt = atoi(capaciteit->Value());
            }

            for (unsigned int i = 0; i < fHubs.size(); i++) {
                fHubs[i]->VCcounter++;
                setCentrumInformation(i, naam1, adresString, inwonersInt, capaciteitInt);
            }
        }

        else{

            testOutput << "Geen correcte input voor de tag.\n";

            for (TiXmlNode* elem1 = elem->FirstChild(); elem1 != NULL; elem1 = elem1->NextSiblingElement()) {
                string element = elem1->Value();
                vector<bool> isTags;
                if (element != "CENTRA") {
                    if (elem->FirstChildElement()->FirstChild() != NULL) {
                        isTags = Utils::checkTags(elem, true, testOutput, elem1);
                        Utils::checkValues(elem, elem->FirstChildElement(), true, testOutput, isTags);
                    }
                    else {
                        isTags = Utils::checkTags(elem, false, testOutput, NULL);
                        Utils::checkValues(elem, NULL, false, testOutput, isTags);
                    }
                }
            }

            //Utils::checkValues(elem, NULL, true, testOutput, isTags);
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

void FileParser::setCentrumInformation(unsigned int i, string &naam, string &adresString, int inwonersInt, int capaciteitInt) {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling setCentrumInformation");

    for (unsigned int j = 0; j < fHubs[i]->fHubCentra.size(); j++) {
        if (fHubs[i]->fHubCentra[j]->getNaam() == naam) {
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
        //we sluiten de file
        Output.close();
    }
    else cerr << "Unable to open file";
}

bool FileParser::properlyInitialized() {

    return _initCheck == this;
}
