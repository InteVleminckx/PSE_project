//
// Created by inte on 08.04.21.
//

#ifndef PROJECT_SOFTWARE_ENGENEERING_UTILS_H
#define PROJECT_SOFTWARE_ENGENEERING_UTILS_H

#include "iostream"
#include "../TinyXML/tinyxml.h"
#include <fstream>

using namespace std;

class Utils {
public:

    /*
     * @functie : isDigit
     * Deze functie checkt of de meegegeven string bestaat uit enkel digits (cijfers).
     * @param str : (string) string die wordt meegegeven.
     * @return : true als het uit digits bestaat, anders false.
     */
    static bool isDigit(const string &str);

    /*
     * @functie : isAlpha
     * Deze functie checkt of de meegegeven string uit enkel letters bestaat (een spatie mag).
     * @param str : (string) string die wordt meegegeven.
     * @return : true als het uit letters bestaat, anders false.
     */
    static bool isAlpha(const string &str);

    /*
     * @functie : isAlphaNum
     * Deze functie checkt of de string uit enkel letters en cijfers bestaat (een spatie mag).
     * @param str : (string) string die wordt meegegeven.
     * @return : true als het uit letters en cijfers bestaat, anders false.
     */
    static bool isAlphaNum(const string &str);

    /*
     * @functie : isTag
     * Deze functie checkt of het meegegeven element een child bevat die de fNaam tag heeft.
     * @param tag : (string) string die wordt meegegeven.
     * @param elem : (TiXmlElement) element dat wordt meegegeven.
     * @return : true als de string (fNaam) een child is van het element, anders false.
     */
    static bool isTag(const string &tag, TiXmlElement *elem, bool isFirstchildElement);

    /*
     * @functie : isLittleAlpha
     * Deze functie checkt of de meegegeven string uit enkel kleine letters bestaat (een spatie mag).
     * @param str : (string) string die wordt meegegeven.
     * @return : true als het uit kleine letters bestaat, anders false.
     */
    static bool isLittleAlpha(const string &str);

    /*
     * @functie : isCorrectTemperature
     * Deze functie checkt of de meegeven string uit een positieve of negatieve integer bestaat.
     * @param str :(string) string die wordt meegegeven.
     * @return : true als het een juiste invoer is als temperatuur, anders false.
     */
    static bool isCorrectTemperature(const string &str);

    /*
     * @functie: checkTags
     * We kunnen met deze functie alle controle tags ineens aanroepen, dan staat dit niet allemaal minden in onze code
     * @param elem
     * @param isFirstchildElement
     * @param testOutput
     */
    static void checkTags(TiXmlElement *elem, bool isFirstchildElement, ofstream &testOutput);


    /*
     * @functie: checkValues
     * We controleren hier of de values die tussen de 2 tags staat correct is
     * @param elem
     * @param isVaccins
     * @param testOutput
     */
    static void checkValues(TiXmlElement *elem, TiXmlNode* elem1, bool isVaccins, ofstream &testOutput);


};


#endif //PROJECT_SOFTWARE_ENGENEERING_UTILS_H
