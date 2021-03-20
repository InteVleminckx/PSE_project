/*
 * korte beschrijving:
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date:
 * @version:
*/

#include "FileParser.h"

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
    return 0;
}

void FileParser::parseXML() {
//    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling parseXML");

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();

        if(elemName == "HUB") {

            Hub newHub;


            HUBcounter++;
            fHubVaccins = 0;

            REQUIRE((HUBcounter == 1), "Het aantal hubs mag niet meer zijn dan 1.");

            if (!isTag("levering", elem)) return 1;
            if (!isTag("fInterval", elem)) return 1;
            if (!isTag("Transport", elem)) return 1;
            if (!isTag("CENTRA", elem)) return 1;
            TiXmlNode* CENTRA = elem->FirstChildElement("CENTRA");

//            REQUIRE((isDigit(levering->Value()) == true), "Leveringen moet een positieve integer zijn.");
//            REQUIRE((isDigit(intervalNode->Value()) == true), "Interval moet een positieve integer zijn.");
//            REQUIRE((isDigit(Transport->Value()) == true), "Transport moet een positieve integer zijn.");

            for (TiXmlNode* element = CENTRA->FirstChild(); element != NULL;
                element = element->NextSiblingElement()){

//             REQUIRE((isAlpha(element->FirstChild()->Value()) == true), "Naam van een centrum moet een string zijn.");
                if (!isAlpha(element->FirstChild()->Value())){
                    cout << endl;
                    cerr << "Naam van een centrum moet een string zijn." << endl;
                    cout << endl;
                    return 1;
                }

                string naam = element->FirstChild()->Value();
                Vaccinatiecentrum CENTRUM;
                CENTRUM.setNaam(naam);
                fCentra.push_back(CENTRUM);
            }

            REQUIRE((centra.size() >= 1), "Er moet minstens 1 of meer vaccininatiecentra zijn.");

        }

        else if (elemName == "VACCINATIECENTRUM"){
            TiXmlNode* attr1 = elem->FirstChild("naam")->FirstChild();
            TiXmlNode* attr2 = elem->FirstChild("adres")->FirstChild();
            TiXmlNode* attr3 = elem->FirstChild("inwoners")->FirstChild();
            TiXmlNode* attr4 = elem->FirstChild("capaciteit")->FirstChild();

            REQUIRE((isAlpha(attr1->Value()) == true), "Naam van een centum moet een string zijn.");
            REQUIRE((isAlphaNum(attr2->Value()) == true), "Adres moet bestaan uit een string en integers.");
            REQUIRE((isDigit(attr3->Value()) == true), "Inwoners moet een integer zijn.");
            REQUIRE((isDigit(attr4->Value()) == true), "Capaciteit moet een integer zijn.");

            string adresString = adres->Value();
            int inwonersInt = atoi(inwoners->Value());
            int capaciteitInt = atoi(capaciteit->Value());

            for (unsigned int i = 0; i < fCentra.size(); i++) {
                if (fCentra[i].getNaam() == naam->Value()) {
                    fCentra[i].setAdres(adresString);
                    fCentra[i].setInwoners(inwonersInt);
                    fCentra[i].setCapaciteit(capaciteitInt);
                    fCentra[i].setVaccins(0);
                    fCentra[i].setVaccinated(0);
                }
            }
        }

        else{
            cout << endl;
            cerr << "Geen correcte input voor de tag." << endl;
            cout << endl;
            return 1;
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
        Output << "Hub (" << fHubVaccins << " fVaccinsInCentrum)\n";
        //lopen over alle fCentra
        for (unsigned int i = 0; i < fCentra.size(); i++) {
            //schrijven een string weg in het uitvoer bestand
            Output << "\t-> " << fCentra[i].getNaam() << "(" << fCentra[i].getVaccins() << " fVaccinsInCentrum)""\n";
        }
        //wit regel in het bestand
        Output << "\n";
        //lopen terug over de fCentra
        for (unsigned int i = 0; i < fCentra.size(); i++) {
            //berekenen het aantal niet gevaccineerden
            int aantalNietGevaccineerden = fCentra[i].getInwoners() - fCentra[i].getVaccinated();
            //schrijven dit weg in het output bestand
            Output << fCentra[i].getNaam() << ": " << fCentra[i].getVaccinated() << " gevaccineerd, nog " <<
                   aantalNietGevaccineerden << " niet gevaccineerd\n";
        }
        //we sluiten de file
        Output.close();
    }
    else cerr << "Unable to open file";
}

bool FileParser::isDigit(const string &str) {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling uitvoer");

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool FileParser::isAlpha(const string &str) {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isAlpha");

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != 32 ){
            if (!(isalpha(str[i]))) {
                return false;
            }
        }
    }
    return true;
}

bool FileParser::isAlphaNum(const string &str) {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isAlphaNum");

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != 32 && str[i] != 44 && str[i] != 45) {
            if (!isalnum(str[i])) {
                return false;
            }
        }
    }
    return true;
}

bool FileParser::isTag(const string &tag, TiXmlElement *elem) {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isTag");
    const char *tagString = tag.c_str();

    if (elem->FirstChildElement(tagString) == NULL){
        cout << endl;
        cerr << "De tag " + tag + " is niet gevonden." << endl;
        cout << endl;
        return false;
    }
    return true;
}

bool FileParser::isLittleAlpha(const string &str) {
    REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling isLittleAlpha");

    for (unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != 32 ){
            if (str[i] < 'a' || 'z' < str[i]) {
                return false;
            }
        }
    }
    return true;
}

bool FileParser::properlyInitialized() {

    return _initCheck == this;
}