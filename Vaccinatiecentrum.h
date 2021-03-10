/*
 * korte beschrijving:
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date:
 * @version:
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
#define PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
class Vaccinatiecentrum {
private:
    string naam;
    string adres;
    int inwoners;
    int capaciteit;
    int vaccins; // vaccins in het centrum
    int vaccinated; // aantal gevaccineerden

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

    void isAdresGeldig(string &Cadres);
};


#endif //PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H