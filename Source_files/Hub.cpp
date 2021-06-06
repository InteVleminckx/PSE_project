/*
 * korte beschrijving:
 * Klasse (Hub), bevat het aantal vaccins in de hub zelf en de vaccinatiecentra waar de hub aan moet distribueren.
 * Houdt ook het aantal geleverde vaccins van elk type bij.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 07/06/2021
 * @version: Specificatie 2.1
*/

#include "../Header_files/Hub.h"

Hub::Hub() {
    _initCheck = this;
    VCcounter = 0;
    ENSURE(this->properlyInitialized(), "Constructor was not properly initialized");
}

void Hub::transport(Vaccinatiecentrum *centrum, ofstream &OT, int day) {

    REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling transport");

    int teVaccineren = 0;

    bool isHernieuwd = false;

    int tempCapaciteit = centrum->getCapaciteit();

    for (unsigned int i = 0; i < fVaccins.size(); ++i) {
        string type = fVaccins[i]->getType();
        if (centrum->getGebruikteVaccins(day, type) != 0) {
            // opnieuw vaccineren
            centrum->vaccinatieHernieuwing(fVaccins[i], day, OT);
            isHernieuwd = true;
        }
    }
    if (!isHernieuwd) {
        for (unsigned int i = 0; i < fVaccins.size(); ++i) {

            if (centrum->getVaccinatedFirstTime() == centrum->getInwoners()){
                break;
            }

            else {
                centrum->vaccinatieFirstTime(fVaccins[i], OT, day, teVaccineren);

                if (teVaccineren <= 0) {
                    break;
                }
            }
        }
        OT << "\n";
    }
    centrum->setCapaciteit(tempCapaciteit);

}

bool Hub::properlyInitialized() {

    return _initCheck == this;
}

void Hub::setAantalGeleverdeVaccins(string &type, int aantal) {
    REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling setAantalGeleverdeVaccins");
    REQUIRE(aantal > 0, "Het aantal geleverde vaccins moet groter zijn dan 0.");
    fAantalGeleverdeVaccins[type] = aantal;
    ENSURE((getAantalGeleverdeVaccins(type) == aantal), "setVaccinatedFirstTime postcondition failure.");
}

int Hub::getAantalGeleverdeVaccins(string &type) {
    REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling getAantalGeleverdeVaccins");

    if (fAantalGeleverdeVaccins.count(type)){
        return fAantalGeleverdeVaccins[type];
    }
    return 0;
}

int Hub::getAantalOngevaccineerdeInwonersInHub(Hub* hub) {
    REQUIRE(hub->properlyInitialized(), "Hub wasn't initialized when calling getAantalOngevaccineerdeInwonersInHub");

    int aantalOngevaccineerden = 0;

    for (unsigned int i = 0; i < hub->fHubCentra.size(); ++i) {
        aantalOngevaccineerden += (hub->fHubCentra[i]->getInwoners() - hub->fHubCentra[i]->getVaccinatedSecondTime());
    }
    return aantalOngevaccineerden;
}

int Hub::getAantalOngevaccineerdeInwonersInTotal(const vector<Hub*>& hubs) {

    int aantalOngevaccineerden = 0;
    for (unsigned int j = 0; j < hubs.size(); j++) {
        REQUIRE(hubs[j]->properlyInitialized(), "Hub wasn't initialized when calling getAantalOngevaccineerdeInwonersInTotal");
        aantalOngevaccineerden += getAantalOngevaccineerdeInwonersInHub(hubs[j]);
    }

    return aantalOngevaccineerden;
}


