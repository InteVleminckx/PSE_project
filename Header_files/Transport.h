/*
 * korte beschrijving:
 * Klasse (Transport), simuleert het verplaatsen van de vaccinaties naar de fCentra en het vaccineren van de inwoners in de fCentra.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 24/04/2021
 * @version: Specificatie 2.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
#define PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H

#include <sstream>  // Required for stringstreams
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "Vaccinatiecentrum.h"
#include "../TinyXML/tinyxml.h"
#include "Hub.h"

using namespace std;

class FileParser;
class Transport {

    Transport* _initCheck;
    ofstream fOVP; //overzichtVaccinatieProcedure

public:

    /*
     * @functie : Transport
     * Deze functie is de constructor voor de transportsimulatie. Hier roepen we de functie transportSimulatie aan.
     * @param hub : De hub die op die de transport gaat uitvoeren.
     * @param centrum : Het centrum waar de vaccins naar getransporteert worden
     * @param OT : uitvoer bestand waar de transport informatie in te vinden is
     * @param day : de huidige dag waar ons bevinden in de simulatie
     */
    Transport(Hub* hub, Vaccinatiecentrum* centrum, ofstream &OT, int day);

    /*
     * @functie: vaccinatieHernieuwing
     * Deze functie voert de hernieuwingen uit.
     * @param centrum : Vaccinatiecentrum, centrum waar de hernieuwingen plaatsvinden
     * @param vaccinType : string, het vaccin type waar de hernieuwing mee moet gebeuren
     * @param day : int, de dag van de hernieuwing
     * @param OT : uitvoer bestand waar de transport informatie in te vinden is
     * REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieHernieuwing");
     */
    void vaccinatieHernieuwing(Vaccinatiecentrum* centrum, Vaccin* vaccin, int day, ofstream &OT);

    /*
     * @functie: vaccinatieFirstTime
     * Wanneer er geen hernieuwingen moeten plaatsvinden dan worden er mensen die nog niet gevaccineerd
     * zijn voor de eerste keer gevaccineerd. Dit wordt hier bepaalt, het aan transport wordt hier dan
     * ook ineens berekent.
     * @param vaccin : Het vaccin die wordt gebruikt om te vaccineren.
     * @param centrum : Het centrum waar de vaccins naar getransporteert worden
     * @param OT : uitvoer bestand waar de transport informatie in te vinden is
     * @param day : de huidige dag waar ons bevinden in de simulatie
     * @param teVaccineren : controllen waarde om voor te breaken van de for loop, wanneer er geen nieuwe berekingen
     *                       meer gedaan moeten worden
     * REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieFirstTime");
     */
    void vaccinatieFirstTime(Vaccin* vaccin, Vaccinatiecentrum* centrum, ofstream &OT, int day, int &teVaccineren);

    /*
     * @functie : vaccinatieInCentrum
     * Deze functie verzorgt de (automatische) vaccinatie van de mensen in het Vaccinatiecentrum.
     * Het aantal gevaccineerden in het centrum wordt vergroot gelijk aan het aantal fVaccinsInCentrum in
     * het centrum, en daarnaast wordt het aantal fVaccinsInCentrum in het centrum verlaagd.
     * @param centrum : het Vaccinatiecentrum
     * REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieInCentrum");
     */
    int vaccinatieInCentrum(Vaccinatiecentrum* centrum, Vaccin* vaccin, int teVaccineren, int day);

    bool properlyInitialized();

};

#endif //PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
