/*
 * korte beschrijving:
 * Klasse (Utils) : Deze klasse bevat alle hulpfuncties die we gebruiken
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 24/04/2021
 * @version: Specificatie 2.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_UTILS_H
#define PROJECT_SOFTWARE_ENGENEERING_UTILS_H

#include "iostream"
#include "../TinyXML/tinyxml.h"
#include <fstream>
#include "vector"


using namespace std;

class Distributie;
class FileParser;

class Utils {
private:

    ofstream fFileList;

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
    static bool isTag(const string &tag, TiXmlElement *elem, bool isFirstchildElement, TiXmlNode* elem1);

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
    static vector<bool> checkTags(TiXmlElement *elem, bool isFirstchildElement, ofstream &testOutput, TiXmlNode* elem1);


    /*
     * @functie: checkValues
     * We controleren hier of de values die tussen de 2 tags staat correct is
     * @param elem
     * @param isVaccins
     * @param testOutput
     */
    static vector<bool> checkValues(TiXmlElement *elem, TiXmlNode* elem1, bool isVaccins, ofstream &testOutput,
        const vector<bool>& isTag);

    /*
     * @functie : grafischeImpressie
     * Deze functie geeft in een percentage weer hoeveel mensen er gevaccineerd zijn en hoeveel vaccins er nog in een
     * centra zit
     * @param file : het geparste xml bestand, met alle huidige gegevens in
     */
    static void grafischeImpressie(FileParser &file);

    /*
     * @functie: statistischeVerwerking
     * Deze functie geeft in een .cvs formaat de statistische gegevens weer (deze wordt aangeroepen op het einde van we simulatie)
     * @param file : het geparste xml bestand, met alle huidige gegevens in
     */
    static void statistischeVerwerking(FileParser &file);

    void Graphics(FileParser &file, int day, Distributie* distributie,bool close = false);

};

#endif //PROJECT_SOFTWARE_ENGENEERING_UTILS_H
