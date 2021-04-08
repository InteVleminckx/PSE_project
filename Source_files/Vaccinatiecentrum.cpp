/*
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "../Header_files/Vaccinatiecentrum.h"

Vaccinatiecentrum::Vaccinatiecentrum() {
    _initCheck = this;
    ENSURE(this->properlyInitialized(), "Constructor was not properly initialized");
}

//void Vaccinatiecentrum::vaccinatieInCentrum(Vaccinatiecentrum &centrum) {
//
//    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling vaccinatieInCentrum");
//
//    fOVP.open("../simulatieOutput/overzichtVaccinatieprocedure.txt");
//
//    // min van drie elementen werkt niet, dus we hebben het 2 keer apart gedaan.
//    int inwonersGevaccineerd = min(fVaccinsInCentrum, fCapaciteit);
//    inwonersGevaccineerd = min(inwonersGevaccineerd, fInwoners - fVaccinated);
//
//    fVaccinated += inwonersGevaccineerd;
//    fVaccinsInCentrum -= inwonersGevaccineerd;
//
//    if (inwonersGevaccineerd != 0) {
//        fOVP << "Er werden " << inwonersGevaccineerd << " inwoners gevaccineerd in " << centrum.getNaam() << ".\n";
//    }
//
//}


void Vaccinatiecentrum::setNaam(string &Cnaam) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setNaam");
    REQUIRE((!Cnaam.empty()), "Een vaccininatiecentrum moet een fNaam hebben, met minstens 1 karakter.");
    fNaam = Cnaam;
    ENSURE((getNaam() == Cnaam), "setNaam postcondition failure.");
}

void Vaccinatiecentrum::setAdres(string &Cadres) {
//    isAdresGeldig(Cadres);
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setAdres");
    REQUIRE((!Cadres.empty()), "Het fAdres moet minstens 1 karakter.");
    fAdres = Cadres;
    ENSURE((getAdres() == Cadres), "setAdres postcondition failure.");
}

void Vaccinatiecentrum::setInwoners(int &Cinwoners) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setInwoners");
    REQUIRE((Cinwoners > 0), "Een gebied heeft meer dan 0 inwoners.");
    fInwoners = Cinwoners;
    ENSURE((getInwoners() == Cinwoners), "setInwoners postcondition failure.");
}

void Vaccinatiecentrum::setCapaciteit(int &Ccapaciteit) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setCapaciteit");
    REQUIRE((Ccapaciteit > 0), "Een vaccininatiecentrum heeft een grotere fCapaciteit dan 0.");
    fCapaciteit = Ccapaciteit;
    ENSURE((getCapaciteit() == Ccapaciteit), "setCapaciteit postcondition failure.");
}

void Vaccinatiecentrum::setVaccins(int Cvaccinaties, string &type) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccins");
    REQUIRE((Cvaccinaties >= 0), "Een vaccininatiecentrum heeft 0 of meer fVaccinsInCentrum in bezit.");
    fVaccinsInCentrum[type] = Cvaccinaties;
    ENSURE((getVaccins(type) == Cvaccinaties), "setVaccins postcondition failure.");
}

void Vaccinatiecentrum::setVaccinated(int Cvaccinated) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccinated");
    REQUIRE((Cvaccinated >= 0), "Een gebied kan 0 of meer personen hebben die gevaccineerd zijn.");
    fVaccinated = Cvaccinated;
    ENSURE((getVaccinated() == Cvaccinated), "setVaccinated postcondition failure.");
}

string Vaccinatiecentrum::getNaam() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getNaam");
    return fNaam;
}

string Vaccinatiecentrum::getAdres() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getAdres");
    return fAdres;
}

int Vaccinatiecentrum::getInwoners() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getInwoners");
    return fInwoners;
}

int Vaccinatiecentrum::getCapaciteit() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getCapaciteit");
    return fCapaciteit;
}

int Vaccinatiecentrum::getVaccins(string &type) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccins");

    return fVaccinsInCentrum[type];
}

int Vaccinatiecentrum::getVaccinated() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinated");

    return fVaccinated;
}

bool Vaccinatiecentrum::properlyInitialized() {
    return _initCheck == this;
}


//void Vaccinatiecentrum::isAdresGeldig(string &Cadres) {
//
//    REQUIRE((!Cadres.empty()), "Geen geldig fAdres voor het vaccinatiecentrum.");
//
//    bool isPassedKomma = false;
//    vector<string> beforeKomma;
//    vector<string> afterKomma;
//
//    string woord;
//
//    for (unsigned int i = 0; i < Cadres.size(); ++i) {
//
//        if (Cadres[i] != ',' && Cadres[i] != ' '){
//            woord += Cadres[i];
//        }
//        if ((Cadres[i] == ' ' || i == Cadres.size()-1) && isPassedKomma){
//            if (!woord.empty()){
//                afterKomma.push_back(woord);
//                woord = "";
//            }
//        }
//
//        else if ((Cadres[i] == ' ' || Cadres[i] == ',') && !isPassedKomma ){
//            beforeKomma.push_back(woord);
//            woord = "";
//        }
//        if (Cadres[i] == ','){
//            isPassedKomma = true;
//        }
//    }
//
//    bool isCorrectHouseNumber = false;
//
//
//    //controllen huisnummer allemaal numbers laatste kan zowel nummer als letter zijn
//    if (beforeKomma[beforeKomma.size()-1].size() == 1){
//        if ('0' < beforeKomma[beforeKomma.size()-1][0] && beforeKomma[beforeKomma.size()-1][0] <= '9'){
//            isCorrectHouseNumber = true;
//        }
//    }
//
//    else if (beforeKomma[beforeKomma.size()-1].size() > 1){
//        for (unsigned int i = 0; i < beforeKomma[beforeKomma.size()-1].size()-1; ++i) {
//            if ('0' < beforeKomma[beforeKomma.size()-1][i] && beforeKomma[beforeKomma.size()-1][i] <= '9'){
//                isCorrectHouseNumber = true;
//            }
//            else{
//                isCorrectHouseNumber = false;
//                break;
//            }
//        }
//    }
//
//    REQUIRE((isCorrectHouseNumber == true), "Geen geldig huisnummer, "
//        "moet bestaan uit allemaal cijfers en laatste kan zowel cijfer als letter zijn.");
//    REQUIRE((beforeKomma.size() >= 2), "Geen geldig fAdres voor de komma.");
//    REQUIRE((!afterKomma.empty()), "Geen geldig fAdres na de komma.");
//
//    // checken of achter de komma alles wel klopt ???
//
//}

