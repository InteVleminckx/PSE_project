//
// Created by inte on 07.04.21.
//

#ifndef PROJECT_SOFTWARE_ENGENEERING_DISTRIBUTIE_H
#define PROJECT_SOFTWARE_ENGENEERING_DISTRIBUTIE_H
#include <iostream>
#include "FileParser.h"
#include "Transport.h"
//#include "TinyXML/tinyxml.h"
//#include <string>
//#include <vector>
//#include <map>
//#include <cmath>
//#include <algorithm>
//#include "Vaccinatiecentrum.h"
//#include <fstream>


using namespace std;

class Distributie {

public:

    Distributie(FileParser &file);

    /*
     * @functie : isAllPeopleVaccinated
     * Deze functie checkt of alle inwoners van alle fCentra gevaccineerd zijn.
     * @param file : het .xml bestand dat ingelezen wordt.
     * @return : true als alle inwoners gevaccineerd zijn, anders false.
     */
    bool isAllPeopleVaccinated(FileParser &file, unsigned int j);

    bool properlyInitialized();

};


#endif //PROJECT_SOFTWARE_ENGENEERING_DISTRIBUTIE_H
