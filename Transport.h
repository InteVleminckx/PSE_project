/*
 * korte beschrijving:
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date:
 * @version:
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
#define PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H

#include "TinyXML/tinyxml.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "Vaccinatiecentrum.h"
#include <fstream>
//#include "FileParser.h"
#include <sstream>  // Required for stringstreams

using namespace std;

class FileParser;
class Transport;

class Transport {

    Transport* _initCheck;
    int fAantalVaccins;
    int fLeveringInterval;
    ofstream fOVP; //overzichtVaccinatieProcedure

public:

    /*
     * Deze functie is de constructor voor de transportsimulatie
     * @param file : het .xml bestand dat ingelezen wordt.
     */
    Transport(FileParser &file);

    /*
     * @functie : transportSimulatie
     * Deze functie verzorgt de (automatische) verdeling van de fVaccinsInCentrum over de vaccinatiecentra, met
     * telkens op het fInterval een levering fVaccinsInCentrum aan de HUB.
     * @param file : het .xml bestand dat ingelezen wordt.
     */
    void transportSimulatie(FileParser &file);

//    /*
//     * @functie : vaccinatieInCentrum
//     * Deze functie verzorgt de (automatische) vaccinatie van de mensen in het Vaccinatiecentrum.
//     * Het aantal gevaccineerden in het centrum wordt vergroot gelijk aan het aantal fVaccinsInCentrum in
//     * het centrum, en daarnaast wordt het aantal fVaccinsInCentrum in het centrum verlaagd.
//     * @param centrum : het Vaccinatiecentrum
//     */
//    void vaccinatieInCentrum(Vaccinatiecentrum &centrum);

    /*
     * @functie : isAllPeopleVaccinated
     * Deze functie checkt of alle inwoners van alle fCentra gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @return : true bij succes, false bij geen succes.
     */
    bool isAllPeopleVaccinated(FileParser &file);


    bool properlyInitialized();

};

#endif //PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
