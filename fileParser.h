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
using namespace std;

class fileParser {
public:
    TiXmlDocument doc;
    TiXmlElement* root;

    //HUB
    int leveringen;
    int interval;
    int transport;
    vector<vaccinatiecentrum*> centra;

    //



    int parseFile(string &file);
    void parseXML();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_FILEPARSER_H
