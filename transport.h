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
#include "vaccinatiecentrum.h"
#include <fstream>
#include "fileParser.h"
#include <sstream>  // Required for stringstreams
using namespace std;

class transport {
private:

    int aantalVaccins;
    int leveringInterval;
    //aanmaken uitvoer bestand
    ofstream OVP;
    //openen van het uitvoerbestand

    vector<pair<string, int> > vaccinsTransport;


public:

    /*
     * Deze functie is de constructor voor de transportsimulatie
     * @param file : het .xml bestand dat ingelezen wordt.
     */
    transport(fileParser &file);

    /*
     * Deze functie verzorgt de (automatische) verdeling van de vaccins over de vaccinatiecentra, met
     * telkens op het interval een levering vaccins aan de HUB.
     * @param file : het .xml bestand dat ingelezen wordt.
     */
    void transportSimulatie(fileParser &file);

    /*
     * Deze functie verzorgt de (automatische) vaccinatie van de mensen in het vaccinatiecentrum.
     * Het aantal gevaccineerden in het centrum wordt vergroot gelijk aan het aantal vaccins in
     * het centrum, en daarnaast wordt het aantal vaccins in het centrum verlaagd.
     * @param centrum : het vaccinatiecentrum
     */
    void vaccinatieInCentrum(vaccinatiecentrum &centrum);

    /*
     * Deze functie checkt of alle inwoners van alle centra gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @return : true bij succes, false bij geen succes.
     */
    bool isAllPeopleVaccinated(fileParser &file);


};

#endif //PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
