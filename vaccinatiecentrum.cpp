//
// Created by inte on 25.02.21.
//

#include "vaccinatiecentrum.h"

void vaccinatiecentrum::setNaam(string &Cnaam) {naam = Cnaam;}

void vaccinatiecentrum::setAdres(string &Cadres) {adres = Cadres;}

void vaccinatiecentrum::setInwoners(int &Cinwoners) {inwoners = Cinwoners;}

void vaccinatiecentrum::setCapaciteit(int &Ccapaciteit) {capaciteit = Ccapaciteit;}

string vaccinatiecentrum::getNaam() {return naam;}

string vaccinatiecentrum::getAdres() {return adres;}

int vaccinatiecentrum::getInwoners() {return inwoners;}

int vaccinatiecentrum::getCapaciteit() {return capaciteit;}
