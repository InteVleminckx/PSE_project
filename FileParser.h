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
#include "Vaccinatiecentrum.h"
#include <fstream>
#include "DesignByContract.h"
#include <sstream>  // Required for stringstreams
using namespace std;

class FileParser {

    TiXmlDocument fDoc;
    TiXmlElement* fRoot;

public:

    //HUB
    int fLeveringen;
    int fHubVaccins; // aantal vaccins in de HUB
    int fInterval;
    int fTransport;

    vector<Vaccinatiecentrum> fCentra;
    FileParser * _initCheck; //use pointer to myself to verify whether I am properly initialized

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
    bool parseXML();

    /// \functie: uitvoer
    /// \preconditie: Het systeem bevat een simulatie met de verschillende vaccinatiecentra
    /*
     * Deze functie is
     */
    void uitvoer(bool begin = true);

    bool isDigit(const string &str);
    bool isAlpha(const string &str);
    bool isAlphaNum(const string &str);
    bool isTag(const string &tag, TiXmlElement *elem);
    bool isLittleAlpha(const string &str);


};


#endif //PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
