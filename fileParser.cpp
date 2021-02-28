
//
// Created by inte on 25.02.21.
//

#include "fileParser.h"




int fileParser::parseFile(string &file) {

    if(!doc.LoadFile(file.c_str())) {std::cerr << doc.ErrorDesc() << std::endl; return 1;}

    root = doc.FirstChildElement();

    if(root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }

    parseXML();
    return 0;
}

void fileParser::parseXML() {

    for (TiXmlElement *elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        string elemName = elem->Value();


        if(elemName == "HUB") {
            TiXmlNode* attr1 = elem->FirstChild("levering")->FirstChild();
            TiXmlNode* attr2 = elem->FirstChild("interval")->FirstChild();
            TiXmlNode* attr3 = elem->FirstChild("transport")->FirstChild();

            if(attr1 != NULL && attr2 != NULL && attr3 != NULL){
                leveringen = atoi(attr1->Value());
                interval = atoi(attr2->Value());
                transport = atoi(attr3->Value());
            }


            for (TiXmlNode* element = elem->FirstChildElement("CENTRA")->FirstChild(); element != NULL; element = element->NextSiblingElement()){
//                cout << element->FirstChild()->Value() <<endl;
                string naam = element->FirstChild()->Value();
                vaccinatiecentrum CENTRUM;
                CENTRUM.setNaam(naam);
                centra.push_back(CENTRUM);
            }
        }

        else if (elemName == "VACCINATIECENTRUM"){
            TiXmlNode* attr1 = elem->FirstChild("naam")->FirstChild();
            TiXmlNode* attr2 = elem->FirstChild("adres")->FirstChild();
            TiXmlNode* attr3 = elem->FirstChild("inwoners")->FirstChild();
            TiXmlNode* attr4 = elem->FirstChild("capaciteit")->FirstChild();
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

void fileParser::uitvoer() {

    //aanmaken uitvoer bestand
    ofstream myfile;

    //openen van het uitvoerbestand
    myfile.open("../uitvoer.txt");

    //zolang de file open is
    if (myfile.is_open())
    {
        //maken een ostringstream aan zodat we de integer kunnen opzetten in een string
        std::ostringstream HubVaccins; HubVaccins << leveringen;
        //schrijven een string weg in het uitvoer bestand
        myfile << "Hub (" + HubVaccins.str() + " vaccins)\n";
        //lopen over alle centra
        for (unsigned int i = 0; i < centra.size(); i++) {
            //zetten de integer van het aantal vaccins in het centrum om naar een string
            std::ostringstream geleverdeVaccins; geleverdeVaccins << centra[i].getVaccins();
            //schrijven een string weg in het uitvoer bestand
            myfile << "\t-> " + centra[i].getNaam() + "(" + geleverdeVaccins.str() + " vaccins)""\n";
        }
        //wit regel in het bestand
        myfile << "\n";
        //lopen terug over de centra
        for (unsigned int i = 0; i < centra.size(); i++) {
            //zetten de integer van het aantal gevaccineerde in het centrum om naar een string
            std::ostringstream gevaccineerden; gevaccineerden << centra[i].getVaccinated();
            //berekenen het aantal niet gevaccineerden
            int aantalNietGevaccineerden = centra[i].getInwoners() - centra[i].getVaccinated();
            //zetten dit terug om naar een string
            std::ostringstream OutputAantalNietGevaccineerden; OutputAantalNietGevaccineerden << aantalNietGevaccineerden;
            //schrijven dit weg in het output bestand
            myfile << centra[i].getNaam() + ": " + gevaccineerden.str() + " gevaccineerd, nog " + OutputAantalNietGevaccineerden.str() + " niet gevaccineerd\n";
        }
        //we sluiten de file
        myfile.close();
    }
    else cerr << "Unable to open file";
}
