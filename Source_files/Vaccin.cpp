//
// Created by inte on 20.03.21.
//

#include "../Header_files/Vaccin.h"

Vaccin::Vaccin(string &type, int leveringen, int interval, int transport, int hernieuwingen, int temperatuur) {
    fType = type;
    fLeveringen = leveringen;
    fInterval = interval;
    fTransport = transport;
    fHernieuwingen = hernieuwingen;
    fTemperatuur = temperatuur;
    fAantalVaccins = 0;
    _initCheck = this;

    ENSURE(this->properlyInitialized(), "Constructor was not properly initialized");

}

bool Vaccin::properlyInitialized() {
    return _initCheck == this;

}

void Vaccin::setAantalVaccins(int aantalVaccins) {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling setAantalVaccins");
    fAantalVaccins+=aantalVaccins;
    ENSURE(getAantalVaccins() == fAantalVaccins+aantalVaccins, "Postcondition failure");
}

string Vaccin::getType() {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getType");
    return fType;
}

int Vaccin::getLeveringen() {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getLeveringen");
    return fLeveringen;
}

int Vaccin::getHernieuwingen() {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getHernieuwingen");
    return fHernieuwingen;
}

int Vaccin::getTransport() {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getTransport");
    return fTransport;
}

int Vaccin::getInterval() {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getInterval");
    return fInterval;
}

int Vaccin::getTemperatuur() {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getTemperatuur");
    return fTemperatuur;
}

int Vaccin::getAantalVaccins() {
    REQUIRE(this->properlyInitialized(), "Vaccin wasn't initialized when calling getAantalVaccins");
    return fAantalVaccins;
}


