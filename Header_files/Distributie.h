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
#include "Transport.h"

using namespace std;

class Distributie {

public:

    Distributie(FileParser &file);

    /*
     * @functie : isAllPeopleVaccinated
     * Deze functie checkt of alle inwoners van alle fCentra gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * REQUIRE(this->properlyInitialized(), "Distributie wasn't initialized when calling isALlPeopleVaccinatedIntotal");
     * @return : true als alle inwoners gevaccineerd zijn, anders false.
     */
    bool isAllPeopleVaccinated(FileParser &file, unsigned int j);

    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_DISTRIBUTIE_H
