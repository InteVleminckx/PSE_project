//
// Created by intev on 28/02/2021.
//

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

    fileParser file;
    int aantalVaccins;
    int leveringInterval;
    bool allVaccinated;
    //aanmaken uitvoer bestand
    ofstream OVP;
    //openen van het uitvoerbestand

    vector<pair<string, int> > vaccinsTransport;


public:

    transport(fileParser &bestand);

    void transportSimulatie();

    void vaccinatieInCentrum(vaccinatiecentrum &centrum);


};


#endif //PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
