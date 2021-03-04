//
// Created by inte on 25.02.21.
//

#include "vaccinatiecentrum.h"

void vaccinatiecentrum::setNaam(string &Cnaam) {naam = Cnaam;}

void vaccinatiecentrum::setAdres(string &Cadres) {adres = Cadres;}

void vaccinatiecentrum::setInwoners(int &Cinwoners) {inwoners = Cinwoners;}

void vaccinatiecentrum::setCapaciteit(int &Ccapaciteit) {capaciteit = Ccapaciteit;}

void vaccinatiecentrum::setVaccins(int Cvaccinaties) {vaccins = Cvaccinaties;}

void vaccinatiecentrum::setVaccinated(int Cvaccinated) {vaccinated = Cvaccinated;}

string vaccinatiecentrum::getNaam() {return naam;}

string vaccinatiecentrum::getAdres() {return adres;}

int vaccinatiecentrum::getInwoners() {return inwoners;}

int vaccinatiecentrum::getCapaciteit() {return capaciteit;}

int vaccinatiecentrum::getVaccins() {return vaccins;}

int vaccinatiecentrum::getVaccinated() {return vaccinated;}
