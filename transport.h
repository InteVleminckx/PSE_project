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

    int aantalVaccins;
    int leveringInterval;
    //aanmaken uitvoer bestand
    ofstream OVP;
    //openen van het uitvoerbestand

    vector<pair<string, int> > vaccinsTransport;


public:

    transport(fileParser &file);

    void transportSimulatie(fileParser &file);

    void vaccinatieInCentrum(vaccinatiecentrum &centrum);

    bool isAllPeopleVaccinated(fileParser &file);


};


#endif //PROJECT_SOFTWARE_ENGENEERING_TRANSPORT_H
