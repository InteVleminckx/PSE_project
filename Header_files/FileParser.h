/*
 * korte beschrijving:
 * klasse (FileParser), parsed het xml bestand en geeft een uitvoer weer van de simulatie
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
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

//class Hub;
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
     */
    void parseXML();

    /*
     * @functie : setCentrumInformation
     * Deze functie geeft alle informatie die het xml bestand bevat over een centrum, aan het juiste centrum
     * @param i
     * @param naam
     * @param adresString
     * @param inwonersInt
     * @param capaciteitInt
     */
    void setCentrumInformation(unsigned int i, string &naam, string &adresString, int inwonersInt, int capaciteitInt);

    /*
     * @functie : uitvoer
     * Deze functie maakt een output bestand aan met daarin een overzicht van het aantal fVaccinsInCentrum in de HUB,
     * het aantal fVaccinsInCentrum per centrum op dat moment en het aantal gevaccineerden per centrum.
     * @param begin : (by default op true) Deze boolean parameter duidt aan of we
     * uitvoerBegin.txt (bij true) (overzicht aan het begin van de simulatie) of
     * uitvoerEinde.txt (bij false) (overzicht aan het einde van de simulatie) moeten aanmaken.
     */
    void uitvoer(bool begin = true);

//    /*
//     * @functie : isDigit
//     * Deze functie checkt of de meegegeven string bestaat uit enkel digits (cijfers).
//     * @param str : (string) string die wordt meegegeven.
//     * @return : true als het uit digits bestaat, anders false.
//     */
//    bool isDigit(const string &str);
//
//    /*
//     * @functie : isAlpha
//     * Deze functie checkt of de meegegeven string uit enkel letters bestaat (een spatie mag).
//     * @param str : (string) string die wordt meegegeven.
//     * @return : true als het uit letters bestaat, anders false.
//     */
//    bool isAlpha(const string &str);
//
//    /*
//     * @functie : isAlphaNum
//     * Deze functie checkt of de string uit enkel letters en cijfers bestaat (een spatie mag).
//     * @param str : (string) string die wordt meegegeven.
//     * @return : true als het uit letters en cijfers bestaat, anders false.
//     */
//    bool isAlphaNum(const string &str);
//
//    /*
//     * @functie : isTag
//     * Deze functie checkt of het meegegeven element een child bevat die de fNaam tag heeft.
//     * @param tag : (string) string die wordt meegegeven.
//     * @param elem : (TiXmlElement) element dat wordt meegegeven.
//     * @return : true als de string (fNaam) een child is van het element, anders false.
//     */
//    bool isTag(const string &tag, TiXmlElement *elem, bool isFirstchildElement);
//
//    /*
//     * @functie : isLittleAlpha
//     * Deze functie checkt of de meegegeven string uit enkel kleine letters bestaat (een spatie mag).
//     * @param str : (string) string die wordt meegegeven.
//     * @return : true als het uit kleine letters bestaat, anders false.
//     */
//    bool isLittleAlpha(const string &str);
//
//    /*
//     * @functie : isCorrectTemperature
//     * Deze functie checkt of de meegeven string uit een positieve of negatieve integer bestaat.
//     * @param str :(string) string die wordt meegegeven.
//     * @return : true als het een juiste invoer is als temperatuur, anders false.
//     */
//    bool isCorrectTemperature(const string &str);


//    /*
//     * @functie: checkTags
//     * We kunnen met deze functie alle controle tags ineens aanroepen, dan staat dit niet allemaal minden in onze code
//     * @param elem
//     * @param isFirstchildElement
//     */
//    void checkTags(TiXmlElement *elem, bool isFirstchildElement);
//
//
//    /*
//     * @functie: checkValues
//     * We controleren hier of de values die tussen de 2 tags staat correct is
//     * @param elem
//     * @param isVaccins
//     */
//    void checkValues(TiXmlElement *elem, TiXmlNode* elem1, bool isVaccins);


};

#endif //PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
