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


void Vaccinatiecentrum::vaccinatieHernieuwing(Vaccin *vaccin, int day, ofstream &OT) {

    REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieHernieuwing");

    string vaccinType = vaccin->getType();
    int gebruikteVaccins = getGebruikteVaccins(day, vaccinType);

    vaccin->setAantalVaccins(-gebruikteVaccins);

    setVaccinatedSecondTime(gebruikteVaccins + getVaccinatedSecondTime());

    eraseDayfromGebruikteVaccins(day, vaccinType);

    OT << "Er werden " << gebruikteVaccins << " mensen "  <<
       "gevaccineerd (als hernieuwing) in " << getNaam() + ".\n";

}

void Vaccinatiecentrum::vaccinatieFirstTime(Vaccin *vaccin, ofstream &OT, int day, int &teVaccineren) {


    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling vaccinatieFirstTime");

    string centrumNaam = getNaam();
    string vaccinType = vaccin->getType();
    int vaccinsCentrum =getVaccins(vaccinType);
    int capaciteitCentrum = getCapaciteit();
    double vaccins_transport_min = capaciteitCentrum - vaccinsCentrum;

    int ladingen = 0;
    bool foundLadingen = false;

    int tempVaccins = vaccin->getAantalVaccins();

    if (vaccin->getTemperatuur() > 0){
        for (int j = 0; j < (vaccins_transport_min + vaccin->getTransport())/vaccin->getTransport();
             ++j) {

            bool getLadingen = false;

            if ((tempVaccins - j*vaccin->getTransport()) > 0 ){ getLadingen = true;}

            if (j*vaccin->getTransport() + vaccinsCentrum >= capaciteitCentrum &&
                2*capaciteitCentrum >= j*vaccin->getTransport() + vaccinsCentrum && !foundLadingen && getLadingen){
                ladingen = j; foundLadingen = true;
            }
        }
    }

    else{
        foundLadingen = true;
        for (int j = 0; j < (vaccins_transport_min + vaccin->getTransport())/vaccin->getTransport();
             ++j) {

            bool getLadingen = false;

            if ((tempVaccins - j*vaccin->getTransport()) > 0 ){ getLadingen = true;}

            if (j*vaccin->getTransport() + vaccinsCentrum <= capaciteitCentrum && foundLadingen && getLadingen){
                ladingen = j; foundLadingen = true;
            }
            else {
                break;
            }
        }
    }

    int inwonersTeVaccineren = getInwoners() - getVaccinatedFirstTime();


    int tempLadingen = 0;
    bool isChangedLadingen = false;
    while (inwonersTeVaccineren < vaccin->getTransport()*ladingen){
        tempLadingen = ladingen;
        ladingen--;
        isChangedLadingen = true;
    }

    if (isChangedLadingen){
        ladingen = tempLadingen;
    }


    setVaccins((ladingen * vaccin->getTransport()) + vaccinsCentrum, vaccinType);

    vaccin->setAantalVaccins(-(ladingen * vaccin->getTransport()));

    OT << "Er werden " << ladingen << " ladingen (" << ladingen * vaccin->getTransport() <<
       " vaccins) getransporteerd naar " << centrumNaam + ".\n";

    teVaccineren = vaccinatieInCentrum(vaccin, teVaccineren, day);


}

int Vaccinatiecentrum::vaccinatieInCentrum(Vaccin *vaccin, int teVaccineren, int day) {

    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling vaccinatieInCentrum");

    string vaccinType = vaccin->getType();
    int vaccinsInCentrum = getVaccins(vaccinType);
    int capaciteit = getCapaciteit();
    int aantalOngevaccineerden = getInwoners() - getVaccinatedFirstTime();

    int inwonersGevaccineerd = min(vaccinsInCentrum, capaciteit);
    inwonersGevaccineerd = min(inwonersGevaccineerd, aantalOngevaccineerden);
    // min van drie elementen werkt niet, dus we hebben het 2 keer apart gedaan.

    if (teVaccineren == 0){
        teVaccineren = inwonersGevaccineerd;
    }

    if (teVaccineren < inwonersGevaccineerd){
        setVaccinatedFirstTime(teVaccineren + getVaccinatedFirstTime());
        setVaccins(getVaccins(vaccinType) - teVaccineren, vaccinType);
        if (vaccin->getHernieuwingen() == 0) {
            setVaccinatedSecondTime(teVaccineren + getVaccinatedSecondTime());
        }
        else {
            setGebruikteVaccins(day+vaccin->getHernieuwingen(), vaccinType, teVaccineren);
        }

        int newTempCapaciteit = getCapaciteit()-teVaccineren;
        setCapaciteit(newTempCapaciteit);

    }
    else{
        setVaccinatedFirstTime(inwonersGevaccineerd + getVaccinatedFirstTime());
        setVaccins(getVaccins(vaccinType) - inwonersGevaccineerd, vaccinType);
        if (vaccin->getHernieuwingen() == 0) {
            setVaccinatedSecondTime(inwonersGevaccineerd + getVaccinatedSecondTime());
        }
        else {
            setGebruikteVaccins(day+vaccin->getHernieuwingen(), vaccinType, inwonersGevaccineerd);
        }

        int newTempCapaciteit = getCapaciteit()-inwonersGevaccineerd;
        setCapaciteit(newTempCapaciteit);

    }

    return capaciteit - inwonersGevaccineerd;
}

void Vaccinatiecentrum::eraseDayfromGebruikteVaccins(int dagHernieuwing, string &type) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling eraseDayfromGebruikteVaccins");
    fGebruikteVaccins.erase(make_pair(dagHernieuwing, type));
}

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
    REQUIRE((Ccapaciteit >= 0), "Een vaccininatiecentrum heeft een grotere fCapaciteit dan 0.");
    fCapaciteit = Ccapaciteit;
    ENSURE((getCapaciteit() == Ccapaciteit), "setCapaciteit postcondition failure.");
}

void Vaccinatiecentrum::setVaccins(int Cvaccinaties, string &type) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccins");
    REQUIRE((Cvaccinaties >= 0), "Een vaccininatiecentrum heeft 0 of meer fVaccinsInCentrum in bezit.");
    fVaccinsInCentrum[type] = Cvaccinaties;
    ENSURE((getVaccins(type) == Cvaccinaties), "setVaccins postcondition failure.");
}

void Vaccinatiecentrum::setVaccinatedFirstTime(int Cvaccinated) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccinatedFirstTime");
    REQUIRE((Cvaccinated >= 0), "Een gebied kan 0 of meer personen hebben die gevaccineerd zijn.");
    fVaccinatedFirstTime = Cvaccinated;
    ENSURE((getVaccinatedFirstTime() == Cvaccinated), "setVaccinatedFirstTime postcondition failure.");
}

void Vaccinatiecentrum::setVaccinatedSecondTime(int Cvaccinated) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccinatedSecondTime");
    REQUIRE((Cvaccinated >= 0), "Een gebied kan 0 of meer personen hebben die gevaccineerd zijn.");
    fVaccinatedSecondTime = Cvaccinated;
    ENSURE((getVaccinatedSecondTime() == Cvaccinated), "setVaccinatedSecondTime postcondition failure.");
}

void Vaccinatiecentrum::setGebruikteVaccins(int dagHernieuwing, string &type, int aantalPersonen) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setGebruikteVaccins");
    REQUIRE((aantalPersonen >= 0), "Aantal personen moet groter of gelijk zijn aan 0.");
    REQUIRE((dagHernieuwing > 0), "De dag van een hernieuwing moet positief zijn");
    fGebruikteVaccins[make_pair(dagHernieuwing, type)] = aantalPersonen;
    ENSURE((getGebruikteVaccins(dagHernieuwing, type) == aantalPersonen), "setGebruikteVaccins postcondtion failure");

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

int Vaccinatiecentrum::getVaccinatedFirstTime() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinatedFirstTime");
    return fVaccinatedFirstTime;
}

int Vaccinatiecentrum::getVaccinatedSecondTime() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinatedSecondTime");
    return fVaccinatedSecondTime;
}

int Vaccinatiecentrum::getGebruikteVaccins(int dagHernieuwing, string &type) {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getGebruikteVaccins");

    if (fGebruikteVaccins.count(make_pair(dagHernieuwing, type))){
        return fGebruikteVaccins[make_pair(dagHernieuwing, type)];
    }

    return 0;
}

map<string, int> Vaccinatiecentrum::getVaccinsInCentrum() {
    REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinsInCentrum");
    return fVaccinsInCentrum;
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
//    //controlleren huisnummer, allemaal numbers, laatste kan zowel nummer als letter zijn
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

