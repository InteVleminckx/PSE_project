/*
 * korte beschrijving:
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date:
 * @version:
*/

#include "FileParser.h"
#include "DesignByContract.h"

int FileParser::parseFile(string &file) {

    if(!doc.LoadFile(file.c_str())) {
        std::cerr << doc.ErrorDesc() << std::endl;
        return 1;
    }

    root = doc.FirstChildElement();

    if(root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
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
            HUBcounter++;
            hubVaccins = 0;

            REQUIRE((HUBcounter == 1), "Het aantal hubs mag niet meer zijn dan 1.");

            TiXmlNode* attr1 = elem->FirstChild("levering")->FirstChild();
            TiXmlNode* attr2 = elem->FirstChild("interval")->FirstChild();
            TiXmlNode* attr3 = elem->FirstChild("Transport")->FirstChild();

            if(attr1 != NULL && attr2 != NULL && attr3 != NULL){
                leveringen = atoi(attr1->Value());
                interval = atoi(attr2->Value());
                transport = atoi(attr3->Value());
            }

            for (TiXmlNode* element = elem->FirstChildElement("CENTRA")->FirstChild(); element != NULL;
                element = element->NextSiblingElement()){

                REQUIRE((isAlpha(element->FirstChild()->Value()) == true), "Naam van een centrum moet een string zijn.");

                string naam = element->FirstChild()->Value();
                Vaccinatiecentrum CENTRUM;
                CENTRUM.setNaam(naam);
                centra.push_back(CENTRUM);
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

            string adres = attr2->Value();
            int inwoners = atoi(attr3->Value());
            int capaciteit = atoi(attr4->Value());

            if(attr1 != NULL && attr2 != NULL && attr3 != NULL && attr4 != NULL){
                for (unsigned int i = 0; i < centra.size(); i++) {
                    if (centra[i].getNaam() == attr1->Value()) {
                        centra[i].setAdres(adres);
                        centra[i].setInwoners(inwoners);
                        centra[i].setCapaciteit(capaciteit);
                        centra[i].setVaccins(0);
                        centra[i].setVaccinated(0);
                    }
                }
            }
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
        Output << "Hub (" << hubVaccins << " vaccins)\n";
        //lopen over alle centra
        for (unsigned int i = 0; i < centra.size(); i++) {
            //schrijven een string weg in het uitvoer bestand
            Output << "\t-> " << centra[i].getNaam() << "(" << centra[i].getVaccins() << " vaccins)""\n";
        }
        //wit regel in het bestand
        Output << "\n";
        //lopen terug over de centra
        for (unsigned int i = 0; i < centra.size(); i++) {
            //berekenen het aantal niet gevaccineerden
            int aantalNietGevaccineerden = centra[i].getInwoners() - centra[i].getVaccinated();
            //schrijven dit weg in het output bestand
            Output << centra[i].getNaam() << ": " << centra[i].getVaccinated() << " gevaccineerd, nog " <<
                aantalNietGevaccineerden << " niet gevaccineerd\n";
        }
        //we sluiten de file
        Output.close();
    }
    else cerr << "Unable to open file";
}

bool FileParser::properlyInitialized() {

    return _initCheck == this;
}


bool FileParser::isDigit(const string &str) {
    for (unsigned int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool FileParser::isAlpha(const string &str) {
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
    for (unsigned int i = 0; i < str.size(); ++i) {
        if (str[i] != 32 && str[i] != 44 && str[i] != 45) {
            if (!isalnum(str[i])) {
                return false;
            }
        }
    }
    return true;
}
