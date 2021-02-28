//
// Created by inte on 25.02.21.
//

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
    int interval;
    int transport;

    vector<vaccinatiecentrum> centra;

    /// \functie: parseFile
    /// \param file
    /// \preconditie: XML file met geldige invoer
    /// \return: true als de invoer geldig is, anders false
    int parseFile(string &file);

    /// \functie: parseXML
    /// \preconditie: Een ASCII bestand met daarop een beschrijving van de vaccinatiecentra
    void parseXML();

    /// \functie: uitvoer
    /// \preconditie: Het systeem bevat een simulatie met de verschillende vaccinatiecentra
    void uitvoer();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
