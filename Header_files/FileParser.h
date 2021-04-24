/*
 * korte beschrijving:
 * klasse (FileParser), parsed het xml bestand en geeft een uitvoer weer van de simulatie.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 24/04/2021
 * @version: Specificatie 2.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
#define PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H

#include <sstream>  // Required for stringstreams
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "../TinyXML/tinyxml.h"
#include "DesignByContract.h"
#include "Vaccinatiecentrum.h"
#include "Vaccin.h"
#include "Hub.h"
#include "Utils.h"

using namespace std;

class FileParser;

class FileParser {

    TiXmlDocument fDoc;
    TiXmlElement* fRoot;

public:

    //HUB
    vector<Hub*> fHubs;

    ofstream testOutput;

    FileParser * _initCheck; //use pointer to myself to verify whether I am properly initialized

    bool properlyInitialized();

    /*
     * @functie : parseFile
     * Deze functie is de constructor. Hier roepen we de functie parseXML aan.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @return : true als de invoer geldig is, anders false.
     */
    int parseFile(string &file);

    /*
     * @functie : parseXML
     * Deze functie parst het .xml bestand.
     * REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling parseXML");
     */
    void parseXML();

    /*
     * @functie : setCentrumInformation
     * Deze functie geeft alle informatie die het xml bestand bevat over een centrum, aan het juiste centrum
     * @param i : iterator voor de hub in de hubvector
     * @param naam : naam van vaccinatiecentrum
     * @param adresString : adres van vaccinatiecentrum
     * @param inwonersInt : inwoners van het vaccinatiecentrum
     * @param capaciteitInt : capaciteit van het vaccinatiecentrum
     * REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling setCentrumInformation");
     */
    void setCentrumInformation(unsigned int i, string &naam, string &adresString, int inwonersInt, int capaciteitInt);

    /*
     * @functie : uitvoer
     * Deze functie maakt een output bestand aan met daarin een overzicht van het aantal fVaccinsInCentrum in de HUB,
     * het aantal fVaccinsInCentrum per centrum op dat moment en het aantal gevaccineerden per centrum.
     * @param begin : (by default op true) Deze boolean parameter duidt aan of we
     * uitvoerBegin.txt (bij true) (overzicht aan het begin van de simulatie) of
     * uitvoerEinde.txt (bij false) (overzicht aan het einde van de simulatie) moeten aanmaken.
     * REQUIRE(this->properlyInitialized(), "parsedFile wasn't initialized when calling uitvoer");
     */
    void uitvoer(bool begin = true);

};

#endif //PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
