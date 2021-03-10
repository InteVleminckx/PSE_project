/*
 * korte beschrijving:
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date:
 * @version:
*/

#include "Vaccinatiecentrum.h"

void Vaccinatiecentrum::setNaam(string &Cnaam) {
    REQUIRE((!Cnaam.empty()), "Een vaccininatiecentrum moet een naam hebben, met minstens 1 karakter");
    naam = Cnaam;
    ENSURE((getNaam() == Cnaam), "setNaam postcondition failure");
}

void Vaccinatiecentrum::setAdres(string &Cadres) {
    isAdresGeldig(Cadres);
    adres = Cadres;
    ENSURE((getAdres() == Cadres), "setAdres postcondition failure");
}

void Vaccinatiecentrum::setInwoners(int &Cinwoners) {
    inwoners = Cinwoners;
}

void Vaccinatiecentrum::setCapaciteit(int &Ccapaciteit) {
    capaciteit = Ccapaciteit;
}

void Vaccinatiecentrum::setVaccins(int Cvaccinaties) {
    vaccins = Cvaccinaties;
}

void Vaccinatiecentrum::setVaccinated(int Cvaccinated) {
    vaccinated = Cvaccinated;
}

string Vaccinatiecentrum::getNaam() {
    return naam;
}

string Vaccinatiecentrum::getAdres() {
    return adres;
}

int Vaccinatiecentrum::getInwoners() {
    return inwoners;
}

int Vaccinatiecentrum::getCapaciteit() {
    return capaciteit;
}

int Vaccinatiecentrum::getVaccins() {
    return vaccins;
}

int Vaccinatiecentrum::getVaccinated() {
    return vaccinated;
}

void Vaccinatiecentrum::isAdresGeldig(string &Cadres) {

    REQUIRE((!Cadres.empty()), "Geen geldig adres voor het vaccinatiecentrum.");

    bool isPassedKomma = false;
    vector<string> beforeKomma;
    vector<string> afterKomma;

    string woord;

    for (unsigned int i = 0; i < Cadres.size(); ++i) {

        if (Cadres[i] != ',' && Cadres[i] != ' '){
            woord += Cadres[i];
        }
        if ((Cadres[i] == ' ' || i == Cadres.size()-1) && isPassedKomma){
            if (!woord.empty()){
                afterKomma.push_back(woord);
                woord = "";
            }
        }

        else if ((Cadres[i] == ' ' || Cadres[i] == ',') && !isPassedKomma ){
            beforeKomma.push_back(woord);
            woord = "";
        }
        if (Cadres[i] == ','){
            isPassedKomma = true;
        }
    }

    bool isCorrectHouseNumber = false;

    //controllen huisnummer allemaal numbers laatste kan zowel nummer als letter zijn
    for (unsigned int i = 0; i < beforeKomma[beforeKomma.size()-1].size()-1; ++i) {
        if ('0' < beforeKomma[beforeKomma.size()-1][i] && beforeKomma[beforeKomma.size()-1][0] <= '9'){
            isCorrectHouseNumber = true;
        }
        else{
            isCorrectHouseNumber = false;
            break;
        }
    }

    REQUIRE((isCorrectHouseNumber == true), "Geen geldig huisnummer, moet bestaan uit allemaal cijfers en laatste kan zowel cijfer als letter zijn.");
    REQUIRE((beforeKomma.size() >= 2), "Geen geldig adres voor de komma.");
    REQUIRE((!afterKomma.empty()), "Geen geldig adres na de komma.");

    // checken of achter de komma alles wel klopt ???

}

