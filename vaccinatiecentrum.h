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

public:

    void setNaam(string &Cnaam);
    void setAdres(string &Cadres);
    void setInwoners(int &Cinwoners);
    void setCapaciteit(int &Ccapaciteit);

    string getNaam();
    string getAdres();
    int getInwoners();
    int getCapaciteit();




};


#endif //PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
