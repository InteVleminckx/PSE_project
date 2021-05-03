//
// Created by inte on 20.03.21.
//

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


