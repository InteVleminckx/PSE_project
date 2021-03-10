/*
 * korte beschrijving:
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date:
 * @version:
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
#define PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
#include "TinyXML/tinyxml.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "vaccinatiecentrum.h"
#include <fstream>
#include <sstream>  // Required for stringstreams
using namespace std;

class fileParser {
public:
    TiXmlDocument doc;
    TiXmlElement* root;

    //HUB
    int leveringen;
    int hubVaccins; // aantal vaccins in de HUB
    int interval;
    int transport;

    vector<vaccinatiecentrum> centra;

    fileParser * _initCheck; //use pointer to myself to verify whether I am properly initialized

    bool properlyInitialized();

    /// \functie: parseFile
    /// \param file
    /// \preconditie: XML file met geldige invoer
    /// \return: true als de invoer geldig is, anders false
    /*
     * Deze functie is de constructor.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @return : true als de invoer geldig is, anders false.
     */
    int parseFile(string &file);

    /// \functie: parseXML
    /// \preconditie:
    /*
     * Deze functie is
     */
    void parseXML();

    /// \functie: uitvoer
    /// \preconditie: Het systeem bevat een simulatie met de verschillende vaccinatiecentra
    /*
     * Deze functie is
     */
    void uitvoer();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
