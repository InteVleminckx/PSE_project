//
// Created by inte on 20.03.21.
//

#include "../Header_files/Hub.h"

Hub::Hub() {
    _initCheck = this;
    VCcounter = 0;
    ENSURE(this->properlyInitialized(), "Constructor was not properly initialized");
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
