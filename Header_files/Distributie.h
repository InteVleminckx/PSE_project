/*
 * korte beschrijving:
 * klasse (Distributie), Roept de transport aan en doet de leveringen aan de de hubs
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 24/04/2021
 * @version: Specificatie 2.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_DISTRIBUTIE_H
#define PROJECT_SOFTWARE_ENGENEERING_DISTRIBUTIE_H

#include <iostream>
#include "FileParser.h"

using namespace std;

class Distributie {
    Distributie* _initCheck;
public:

    /*
     * @functie: Distributie
     * Deze functie is de bovenste laag van de simulatie, hier worden de vaccin leveringen geregeld, en wordt het transport van vaccins naar de centra geregeld.
     * @param file : .xml bestand dat wordt meegegeven.
     * ENSURE(properlyInitialized(), "constructor must end in properlyInitialized state");
     */
    Distributie(FileParser &file);

    /*
     * @functie : isAllPeopleVaccinatedInHub
     * Deze functie checkt of alle "inwoners" van een hub gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @param j: unsigned int, iterator voor de huidige hub in de vector
     * REQUIRE(this->properlyInitialized(), "Distributie wasn't initialized when calling isALlPeopleVaccinated");
     * @return : true als alle inwoners gevaccineerd zijn, anders false.
     * ENSURE(file.fHubs[j]->getAantalOngevaccineerdeInwonersInHub() == 0, "isAllPeopleVaccinatedInHub postcondition failed.");
     */
    bool isAllPeopleVaccinatedInHub(FileParser &file, unsigned int j);

    /*
     * @functie : isAllPeopleVaccinatedinTotal
     * Deze functie checkt of alle inwoners van alle hubs in elk centrum gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * REQUIRE(this->properlyInitialized(), "Distributie wasn't initialized when calling isALlPeopleVaccinatedIntotal");
     * @return : true als alle inwoners gevaccineerd zijn, anders false.
     * ENSURE(file.fHubs[0]->getAantalOngevaccineerdeInwonersInTotal(file.fHubs) == 0, "isAllPeopleVaccinatedInTotal postcondition failed.");
     */
    bool isAllPeopleVaccinatedInTotal(FileParser &file);


    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_DISTRIBUTIE_H
