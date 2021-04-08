//
// Created by inte on 20.03.21.
//

#ifndef PROJECT_SOFTWARE_ENGENEERING_HUB_H
#define PROJECT_SOFTWARE_ENGENEERING_HUB_H
//#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>  // Required for stringstreams
#include "DesignByContract.h"
#include "Vaccin.h"
#include "Vaccinatiecentrum.h"
#include "../TinyXML/tinyxml.h"
//#include "FileParser.h"
using namespace std;

class Hub {
public:

    Hub* _initCheck;
//    int fAantalVaccins;
//    int fLeveringInterval;
//    ofstream fOVP; //overzichtVaccinatieProcedure

    vector<Vaccin*> fVaccins;

    vector<Vaccinatiecentrum*> fHubCentra;

    int VCcounter;

    /*
     * @functie: Hub
     * Constructor voor Hub.
     */
    Hub();

    /*
     * @functie: distributie
     * Deze functie verdeeld de fVaccinsInCentrum over de vaccinatiecentra.
     * @param file : .xml bestand dat wordt meegegeven.
     */
//    void distributie(FileParser &file);

    /*
     * @functie : isAllPeopleVaccinated
     * Deze functie checkt of alle inwoners van alle fCentra gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @return : true als alle inwoners gevaccineerd zijn, anders false.
     */
//    bool isAllPeopleVaccinated(FileParser &file);


    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_HUB_H