//
// Created by inte on 25.02.21.
//

#ifndef PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
#define PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
class vaccinatiecentrum {
private:
    string naam;
    string adres;
    int inwoners;
    int capaciteit;
    int vaccins;
    int vaccinated;

public:

    void setNaam(string &Cnaam);
    void setAdres(string &Cadres);
    void setInwoners(int &Cinwoners);
    void setCapaciteit(int &Ccapaciteit);
    void setVaccins(int Cvaccinaties);
    void setVaccinated(int Cvaccinated);

    string getNaam();
    string getAdres();
    int getInwoners();
    int getCapaciteit();
    int getVaccins();
    int getVaccinated();



};


#endif //PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
