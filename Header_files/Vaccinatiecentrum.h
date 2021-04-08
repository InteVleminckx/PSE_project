/*
 * korte beschrijving:
 * Klasse (Vaccinatiecentrum) om een vaccinatiecentrum aan te maken.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
#define PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sstream>  // Required for stringstreams
#include <fstream>
#include "DesignByContract.h"

using namespace std;

class Vaccinatiecentrum {

    string fNaam;
    string fAdres;
    int fInwoners;
    int fCapaciteit;
    map<string, int> fVaccinsInCentrum; // fVaccinsInCentrum in het centrum
    int fVaccinated; // aantal gevaccineerden

//    ofstream fOVP;

    Vaccinatiecentrum* _initCheck;

//    map<string,int> vaccinTypes;

public:

    Vaccinatiecentrum();


    /*
     * @functie : vaccinatieInCentrum
     * Deze functie verzorgt de (automatische) vaccinatie van de mensen in het Vaccinatiecentrum.
     * Het aantal gevaccineerden in het centrum wordt vergroot gelijk aan het aantal fVaccinsInCentrum in
     * het centrum, en daarnaast wordt het aantal fVaccinsInCentrum in het centrum verlaagd.
     * @param centrum : het Vaccinatiecentrum
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling vaccinatieInCentrum");
     */
//    void vaccinatieInCentrum(Vaccinatiecentrum &centrum);

    /*
     * @functie: setNaam
     * Deze functie zet de fNaam van het vaccinatiecentrum.
     * @param Cnaam : string, fNaam van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setNaam");
     * REQUIRE((!Cnaam.empty()), "Een vaccininatiecentrum moet een fNaam hebben, met minstens 1 karakter.");
     * ENSURE((getNaam() == Cnaam), "setNaam postcondition failure.");     */
    void setNaam(string &Cnaam);
    /*
     * @functie: setAdres
     * Deze functie zet het fAdres van het vaccinatiecentrum.
     * @param Cadres : string, fAdres van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setAdres");
     * REQUIRE((!Cadres.empty()), "Het fAdres moet minstens 1 karakter.");
     * ENSURE((getAdres() == Cadres), "setAdres postcondition failure.");
     */
    void setAdres(string &Cadres);
    /*
     * @functie: setInwoners
     * Deze functie zet het aantal inwoners in de omgeving van het vaccinatiecentrum.
     * @param Cinwoners : int, aantal inwoners in de omgeving van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setInwoners");
     * REQUIRE((Cinwoners > 0), "Een gebied heeft meer dan 0 inwoners.");
     * ENSURE((getInwoners() == Cinwoners), "setInwoners postcondition failure.");
     */
    void setInwoners(int &Cinwoners);
    /*
     * @functie: setCapaciteit
     * Deze functie zet de fCapaciteit van het vaccinatiecentrum.
     * @param Ccapaciteit : int, fCapaciteit van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setCapaciteit");
     * REQUIRE((Ccapaciteit > 0), "Een vaccininatiecentrum heeft een grotere fCapaciteit dan 0.");
     * ENSURE((getCapaciteit() == Ccapaciteit), "setCapaciteit postcondition failure.");
     */
    void setCapaciteit(int &Ccapaciteit);
    /*
     * @functie: setVaccins
     * Deze functie zet het aantal fVaccinsInCentrum die het vaccinatiecentrum in bezit heeft.
     * @param Cvaccinaties : int, aantal fVaccinsInCentrum in het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccins");
     * REQUIRE((Cvaccinaties >= 0), "Een vaccininatiecentrum heeft 0 of meer fVaccinsInCentrum in bezit.");
     * ENSURE((getVaccins() == Cvaccinaties), "setVaccins postcondition failure.");
     */
    void setVaccins(int Cvaccinaties, string &type);
    /*
     * @functie: setVaccinated
     * Deze functie zet het aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     * @param Cvaccinated : int, aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling setVaccinated");
     * REQUIRE((Cvaccinated >= 0), "Een gebied kan 0 of meer personen hebben die gevaccineerd zijn.");
     * ENSURE((getVaccinated() == Cvaccinated), "setVaccinated postcondition failure.");
     */
    void setVaccinated(int Cvaccinated);

    /*
     * @functie: getNaam
     * Deze functie geeft de fNaam van het vaccinatiecentrum.
     * @return: string, de fNaam van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getNaam");
     */
    string getNaam();

    /*
     * @functie: getAdres
     * Deze functie geeft het fAdres van het vaccinatiecentrum.
     * @return: string, het fAdres van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getAdres");
     */
    string getAdres();

    /*
     * @functie: getInwoners
     * Deze functie geeft het aantal inwoners in de omgeving van het vaccinatiecentrum.
     * @return: int, inwoners in de omgeving van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getInwoners");
     */
    int getInwoners();

    /*
     * @functie: getCapaciteit
     * Deze functie geeft de fCapaciteit voor het opslagen van de vaccinatie van een vaccinatiecetrum.
     * @return: int, de fCapaciteit van het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getCapaciteit");
     */
    int getCapaciteit();

    /*
     * @functie: getVaccins
     * Deze functie geeft het huidige aantal fVaccinsInCentrum in bezit.
     * @return: int, huidig aantal fVaccinsInCentrum in het vaccinatiecentrum.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccins");
     */
    int getVaccins();

    /*
     * @functie: getVaccinated
     * Deze functie geeft hoeveel mensen er al gevaccineerd zijn.
     * @return: int, aantal personen die al gevaccineerd zijn.
     * REQUIRE(this->properlyInitialized(), "Vaccinatiecentrum wasn't initialized when calling getVaccinated");
     */
    int getVaccinated();

//    void isAdresGeldig(string &Cadres);

    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
