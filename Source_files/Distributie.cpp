//
// Created by inte on 07.04.21.
//

#include "../Header_files/Distributie.h"

Distributie::Distributie(FileParser &file) {

    _initCheck = this;

    int day = 0;

    //aanmaken uitvoer bestand
    ofstream OT;

    //openen van het uitvoerbestand
    OT.open("../simulatieOutput/overzichtTransport.txt");

    while (!isAllPeopleVaccinatedInTotal(file) || day == 1000){



        for (unsigned int i = 0; i < file.fHubs.size(); ++i) {

            OT << "Hub " << i+1 << endl;

            for (unsigned int j = 0; j < file.fHubs[i]->fVaccins.size(); j++) { // alle vaccins updaten (leveringen checken)
                if (day % (file.fHubs[i]->fVaccins[j]->getInterval() + 1) == 0) { // als we op de leveringsdatum zitten

                    file.fHubs[i]->fVaccins[j]->setAantalVaccins(file.fHubs[i]->fVaccins[j]->getLeveringen());
//            cout << "week: " << day/7 << endl;
                }
            }

            if (!isAllPeopleVaccinatedInHub(file, i)) {
                for (unsigned int j = 0; j < file.fHubs[i]->fHubCentra.size(); ++j) {

                    Transport(file.fHubs[i], file.fHubs[i]->fHubCentra[j], OT);

                }
            }
        }
        day++;
//        if (day == 106){
//            cout << endl;
//        }
    }
}

bool Distributie::isAllPeopleVaccinatedInHub(FileParser &file, unsigned int j) {
    REQUIRE(this->properlyInitialized(), "Distributie wasn't initialized when calling isALlPeopleVaccinated");

    for (unsigned int i = 0; i < file.fHubs[j]->fHubCentra.size(); i++) {
        if (file.fHubs[j]->fHubCentra[i]->getInwoners() != file.fHubs[j]->fHubCentra[i]->getVaccinatedSecondTime()) {
            return false;
        }
    }

    return true;
}

bool Distributie::properlyInitialized() {
    return _initCheck == this;
}


