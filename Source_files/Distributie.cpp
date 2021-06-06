/*
 * korte beschrijving:
 * klasse (Distributie), Roept de transport aan en doet de leveringen aan de de hubs
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 07/04/2021
 * @version: Specificatie 2.1
*/

#include "../Header_files/Distributie.h"

Distributie::Distributie(FileParser &file) {

    _initCheck = this;

    int day = 0;

    //aanmaken uitvoer bestand
    ofstream OT;

    //openen van het uitvoerbestand
    OT.open("../simulatieOutput/overzichtTransport.txt");

    Utils utils;

    while (!isAllPeopleVaccinatedInTotal(file) && day < 1000){

        for (unsigned int i = 0; i < file.fHubs.size(); ++i) {

            OT << "Hub " << i+1 << endl;

            for (unsigned int j = 0; j < file.fHubs[i]->fVaccins.size(); j++) { // alle vaccins updaten (leveringen checken)
                if (day % (file.fHubs[i]->fVaccins[j]->getInterval() + 1) == 0) { // als we op de leveringsdatum zitten

                    file.fHubs[i]->fVaccins[j]->setAantalVaccins(file.fHubs[i]->fVaccins[j]->getLeveringen());

                    string type = file.fHubs[i]->fVaccins[j]->getType();
                    file.fHubs[i]->setAantalGeleverdeVaccins(type, file.fHubs[i]->getAantalGeleverdeVaccins(type)
                        + file.fHubs[i]->fVaccins[j]->getLeveringen());
//                    cout << "week: " << day/7 << endl;
                }
            }

            if (!isAllPeopleVaccinatedInHub(file, i)) {

                for (unsigned int j = 0; j < file.getHubs()[i]->getHubCentra().size(); ++j) {

                    file.fHubs[i]->fHubCentra[j]->fLadingen = 0;
                    file.fHubs[i]->transport(file.fHubs[i]->fHubCentra[j], OT, day);

                }
            }
        }
        utils.Graphics(file, day, this);
        day++;
    }

    utils.Graphics(file, day, this,true);

    ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state"); //

}

bool Distributie::isAllPeopleVaccinatedInHub(FileParser &file, unsigned int j) {
    REQUIRE(this->properlyInitialized(), "Distributie wasn't initialized when calling isALlPeopleVaccinated");

    for (unsigned int i = 0; i < file.fHubs[j]->fHubCentra.size(); i++) {
        if (file.fHubs[j]->fHubCentra[i]->getInwoners() != file.fHubs[j]->fHubCentra[i]->getVaccinatedSecondTime()) {
            return false;
        }
    }

    ENSURE(Hub::getAantalOngevaccineerdeInwonersInHub(file.fHubs[j]) == 0, "isAllPeopleVaccinatedInHub postcondition failed.");
    return true;
}


bool Distributie::isAllPeopleVaccinatedInTotal(FileParser &file) {
    REQUIRE(this->properlyInitialized(), "Distributie wasn't initialized when calling isALlPeopleVaccinatedInTotal");

    for (unsigned int i = 0; i < file.fHubs.size(); i++) {
        for (unsigned int j = 0; j < file.fHubs[i]->fHubCentra.size(); j++) {
            if (file.fHubs[i]->fHubCentra[j]->getInwoners() != file.fHubs[i]->fHubCentra[j]->getVaccinatedSecondTime()) {
                return false;
            }
        }
    }
    ENSURE(Hub::getAantalOngevaccineerdeInwonersInTotal(file.getHubs()) == 0, "isAllPeopleVaccinatedInTotal postcondition failed.");

    return true;
}

bool Distributie::properlyInitialized() {
    return _initCheck == this;
}


