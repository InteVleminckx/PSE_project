/*
 * korte beschrijving:
 * Klasse (Hub), bevat het aantal vaccins in de hub zelf en de vaccinatiecentra waar de hub aan moet distribueren.
 * Houdt ook het aantal geleverde vaccins van elk type bij.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 24/04/2021
 * @version: Specificatie 2.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_HUB_H
#define PROJECT_SOFTWARE_ENGENEERING_HUB_H

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

using namespace std;

class Hub {
public:

    Hub* _initCheck;

//    ofstream fOVP; //overzichtVaccinatieProcedure

    vector<Vaccin*> fVaccins;
    map<string, int> fAantalGeleverdeVaccins;

    vector<Vaccinatiecentrum*> fHubCentra;

    int VCcounter;

    /*
     * @functie: Hub
     * Constructor voor Hub.
     */
    Hub();

    /*
     * @functie : transport
     * Deze functie regelt het transport van de hubs naar de vaccinatiecentrums.
     * @param centrum : Het centrum waar de vaccins naar getransporteert worden
     * @param OT : uitvoer bestand waar de transport informatie in te vinden is
     * @param day : de huidige dag waar ons bevinden in de simulatie
     */
    void transport(Vaccinatiecentrum* centrum, ofstream &OT, int day);

    /*
     * @functie : setAantalGeleverdeVaccins
     * Deze functie zet het aantal vaccins van een type per hub.
     * @param type : string, type van het vaccin
     * @param aantal : int, hoeveelheid vaccins die worden toegevoegd
     * REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling setAantalGeleverdeVaccins");
     * REQUIRE(aantal > 0, "Het aantal geleverde vaccins moet groter zijn dan 0.");
     * ENSURE((getAantalGeleverdeVaccins(type) == aantal), "setVaccinatedFirstTime postcondition failure.");
     */
    void setAantalGeleverdeVaccins(string &type, int aantal);

    /*
     * @functie : getAantalGeleverdeVaccins
     * Deze functie geeft het aantal vaccins in de hub van een type terug.
     * @param type : string, type van het vaccin.
     * @return : int, aantal vaccins van het type in de hub.
     * REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling getAantalGeleverdeVaccins");
     */
    int getAantalGeleverdeVaccins(string &type);

    /*
     * @functie : getAantalOngevaccineerdeInwonersInHub
     * Deze functie geeft aantal niet gevaccineerde personen per hub.
     * @return : int, aantal ongevaccineerde inwoners.
     * REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling getAantalOngevaccineerdeInwonersInHub");
     */
    static int getAantalOngevaccineerdeInwonersInHub(Hub* hub);

    /*
     *@functie : getAantalOngevaccineerdeInwonersInTotal
     * Deze functie geeft aantal niet gevaccineerde personen intotaal van alle hubs.
     * @param hubs : alle hubs die vaccines verdelen over centra.
     * @return : int, aantal ongevaccineerde inwoners.
     * REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling getAantalOngevaccineerdeInwonersInTotal");
     */
    static int getAantalOngevaccineerdeInwonersInTotal(const vector<Hub*>& hubs);

    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_HUB_H
