/*
 * korte beschrijving:
 * Klasse (Transport), simuleert het verplaatsen van de vaccinaties naar de fCentra en het vaccineren van de inwoners in de fCentra.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
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
//#include "FileParser.h"

using namespace std;

class FileParser;
//class Transport;

class Transport {

    Transport* _initCheck;
    int fAantalVaccins;
    int fLeveringInterval;
    ofstream fOVP; //overzichtVaccinatieProcedure

public:

    /*
     * @functie : Transport
     * Deze functie is de constructor voor de transportsimulatie. Hier roepen we de functie transportSimulatie aan.
     * @param file : het .xml bestand dat ingelezen wordt.
     */
    Transport(Hub* hub, Vaccinatiecentrum* centrum, ofstream &OT);

    /*
     * @functie : transportSimulatie
     * Deze functie verzorgt de (automatische) verdeling van de fVaccinsInCentrum over de vaccinatiecentra, met
     * telkens op het fInterval een levering fVaccinsInCentrum aan de HUB.
     * @param file : het .xml bestand dat ingelezen wordt.
     */
//    void transportSimulatie(FileParser &file);

    /*
     * @functie : vaccinatieInCentrum
     * Deze functie verzorgt de (automatische) vaccinatie van de mensen in het Vaccinatiecentrum.
     * Het aantal gevaccineerden in het centrum wordt vergroot gelijk aan het aantal fVaccinsInCentrum in
     * het centrum, en daarnaast wordt het aantal fVaccinsInCentrum in het centrum verlaagd.
     * @param centrum : het Vaccinatiecentrum
     */
    int vaccinatieInCentrum(Vaccinatiecentrum* centrum, string &vaccinType, int teVaccineren);

    /*
     * @functie : isAllPeopleVaccinated
     * Deze functie checkt of alle inwoners van alle fCentra gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @return : true als alle inwoners gevaccineerd zijn, anders false.
     */
//    bool isAllPeopleVaccinated(FileParser &file);


    bool properlyInitialized();

};

#endif //PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
