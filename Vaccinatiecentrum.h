/*
 * korte beschrijving:
 * Klasse (Vaccinatiecentrum) om een vaccinatiecentrum aan te maken.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
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

    /*
     * @functie: setNaam
     * Deze functie zet de naam van het vaccinatiecentrum.
     * @param Cnaam : string, naam van het vaccinatiecentrum.
     */
    void setNaam(string &Cnaam);
    /*
     * @functie: setAdres
     * Deze functie zet het adres van het vaccinatiecentrum.
     * @param Cadres : string, adres van het vaccinatiecentrum.
     */
    void setAdres(string &Cadres);
    /*
     * @functie: setInwoners
     * Deze functie zet het aantal inwoners in de omgeving van het vaccinatiecentrum.
     * @param Cinwoners : int, aantal inwoners in de omgeving van het vaccinatiecentrum.
     */
    void setInwoners(int &Cinwoners);
    /*
     * @functie: setCapaciteit
     * Deze functie zet de capaciteit van het vaccinatiecentrum.
     * @param Ccapaciteit : int, capaciteit van het vaccinatiecentrum.
     */
    void setCapaciteit(int &Ccapaciteit);
    /*
     * @functie: setVaccins
     * Deze functie zet het aantal vaccins die het vaccinatiecentrum in bezit heeft.
     * @param Cvaccinaties : int, aantal vaccins in het vaccinatiecentrum.
     */
    void setVaccins(int Cvaccinaties);
    /*
     * @functie: setVaccinated
     * Deze functie zet het aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     * @param Cvaccinated : int, aantal gevaccineerde in de omgeving van het vaccinatiecentrum.
     */
    void setVaccinated(int Cvaccinated);

    /*
     * @functie: getNaam
     * Deze functie geeft de naam van het vaccinatiecentrum.
     * @return: string, de naam van het vaccinatiecentrum.
     */
    string getNaam();
    /*
     * @functie: getAdres
     * Deze functie geeft het adres van het vaccinatiecentrum.
     * @return: string, het adres van het vaccinatiecentrum.
     */
    string getAdres();
    /*
     * @functie: getInwoners
     * Deze functie geeft het aantal inwoners in de omgeving van het vaccinatiecentrum.
     * @return: int, inwoners in de omgeving van het vaccinatiecentrum.
     */
    int getInwoners();
    /*
     * @functie: getCapaciteit
     * Deze functie geeft de capaciteit voor het opslagen van de vaccinatie van een vaccinatiecetrum.
     * @return: int, de capaciteit van het vaccinatiecentrum.
     */
    int getCapaciteit();
    /*
     * @functie: getVaccins
     * Deze functie geeft het huidige aantal vaccins in bezit.
     * @return: int, huidig aantal vaccins in het vaccinatiecentrum.
     */
    int getVaccins();
    /*
     * @functie: getVaccinated
     * Deze functie geeft hoeveel mensen er al gevaccineerd zijn.
     * @return: int, aantal personen die al gevaccineerd zijn.
     */
    int getVaccinated();

//    void isAdresGeldig(string &Cadres);
};


#endif //PROJECT_SOFTWARE_ENGENEERING_VACCINATIECENTRUM_H
