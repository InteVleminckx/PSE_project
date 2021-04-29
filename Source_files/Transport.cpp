/*
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include "../Header_files/Transport.h"
#include "../Header_files/FileParser.h"

Transport::Transport(Hub* hub, Vaccinatiecentrum* centrum, ofstream &OT, int day) {
    _initCheck = this;

//    //aanmaken uitvoer bestand
//    ofstream OT;
//
//    //openen van het uitvoerbestand
//    OT.open("../simulatieOutput/overzichtTransport.txt");
//    fOVP.open("../simulatieOutput/overzichtVaccinatieprocedure.txt");

    int teVaccineren = 0;

    bool isHernieuwd = false;

    int tempCapaciteit = centrum->getCapaciteit();

    for (unsigned int i = 0; i < hub->fVaccins.size(); ++i) {
        string type = hub->fVaccins[i]->getType();
        if (centrum->getGebruikteVaccins(day, type) != 0) {
            // opnieuw vaccineren
            vaccinatieHernieuwing(centrum, hub->fVaccins[i], day, OT);
            isHernieuwd = true;
        }
    }
    if (!isHernieuwd) {
        for (unsigned int i = 0; i < hub->fVaccins.size(); ++i) {

            if (centrum->getVaccinatedFirstTime() == centrum->getInwoners()){
                break;
            }

            else {
                vaccinatieFirstTime(hub->fVaccins[i], centrum, OT, day, teVaccineren);

                if (teVaccineren <= 0) {
                    break;
                }
            }
        }
        OT << "\n";
    }

    centrum->setCapaciteit(tempCapaciteit);
}

void Transport::vaccinatieHernieuwing(Vaccinatiecentrum *centrum, Vaccin* vaccin, int day, ofstream &OT) {

    REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieHernieuwing");

    string vaccinType = vaccin->getType();
    int gebruikteVaccins = centrum->getGebruikteVaccins(day, vaccinType);

    vaccin->setAantalVaccins(-gebruikteVaccins);

    centrum->setVaccinatedSecondTime(gebruikteVaccins + centrum->getVaccinatedSecondTime());

    centrum->eraseDayfromGebruikteVaccins(day, vaccinType);

    OT << "Er werden " << gebruikteVaccins << " mensen "  <<
       "gevaccineerd (als hernieuwing) in " << centrum->getNaam() + ".\n";


}


int Transport::vaccinatieInCentrum(Vaccinatiecentrum* centrum,Vaccin* vaccin, int teVaccineren, int day) {

    REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieInCentrum");

    string vaccinType = vaccin->getType();
    int vaccinsInCentrum = centrum->getVaccins(vaccinType);
    int capaciteit = centrum->getCapaciteit();
    int aantalOngevaccineerden = centrum->getInwoners() - centrum->getVaccinatedFirstTime();

    int inwonersGevaccineerd = min(vaccinsInCentrum, capaciteit);
    inwonersGevaccineerd = min(inwonersGevaccineerd, aantalOngevaccineerden);
    // min van drie elementen werkt niet, dus we hebben het 2 keer apart gedaan.

    if (teVaccineren == 0){
        teVaccineren = inwonersGevaccineerd;
    }


//    if (vaccin->getTemperatuur() < 0 && teVaccineren > centrum->getCapaciteit()){
//        int lading = floor(centrum->getCapaciteit()/vaccin->getTransport());
//        teVaccineren = lading * centrum->getCapaciteit();
//    }

    if (teVaccineren < inwonersGevaccineerd){
        centrum->setVaccinatedFirstTime(teVaccineren + centrum->getVaccinatedFirstTime());
        centrum->setVaccins(centrum->getVaccins(vaccinType) - teVaccineren, vaccinType);
        if (vaccin->getHernieuwingen() == 0) {
            centrum->setVaccinatedSecondTime(teVaccineren + centrum->getVaccinatedSecondTime());
        }
        else {
            centrum->setGebruikteVaccins(day+vaccin->getHernieuwingen(), vaccinType, teVaccineren);
        }

        int newTempCapaciteit = centrum->getCapaciteit()-teVaccineren;
        centrum->setCapaciteit(newTempCapaciteit);

    }
    else{
        centrum->setVaccinatedFirstTime(inwonersGevaccineerd + centrum->getVaccinatedFirstTime());
        centrum->setVaccins(centrum->getVaccins(vaccinType) - inwonersGevaccineerd, vaccinType);
        if (vaccin->getHernieuwingen() == 0) {
            centrum->setVaccinatedSecondTime(inwonersGevaccineerd + centrum->getVaccinatedSecondTime());
        }
        else {
            centrum->setGebruikteVaccins(day+vaccin->getHernieuwingen(), vaccinType, inwonersGevaccineerd);
        }

        int newTempCapaciteit = centrum->getCapaciteit()-inwonersGevaccineerd;
        centrum->setCapaciteit(newTempCapaciteit);

    }

//    if (inwonersGevaccineerd != 0) {
//        fOVP << "Er werden " << inwonersGevaccineerd << " inwoners gevaccineerd in " << centrum->getNaam() << ".\n";
//    }
    return capaciteit - inwonersGevaccineerd;
}

void Transport::vaccinatieFirstTime(Vaccin* vaccin, Vaccinatiecentrum* centrum, ofstream &OT, int day, int &teVaccineren) {
    REQUIRE(this->properlyInitialized(), "Transport wasn't initialized when calling vaccinatieFirstTime");

    string centrumNaam = centrum->getNaam();
    string vaccinType = vaccin->getType();
    int vaccinsCentrum = centrum->getVaccins(vaccinType);
    int capaciteitCentrum = centrum->getCapaciteit();
    double vaccins_transport_min = capaciteitCentrum - vaccinsCentrum;

    int ladingen = 0;
    bool foundLadingen = false;

    int tempVaccins = vaccin->getAantalVaccins();

    if (vaccin->getTemperatuur() > 0){
        for (int j = 0; j < (vaccins_transport_min + vaccin->getTransport())/vaccin->getTransport();
             ++j) {

            bool getLadingen = false;

            if ((tempVaccins - j*vaccin->getTransport()) > 0 ){ getLadingen = true;}

            if (j*vaccin->getTransport() + vaccinsCentrum >= capaciteitCentrum &&
                2*capaciteitCentrum >= j*vaccin->getTransport() + vaccinsCentrum && !foundLadingen && getLadingen){
                ladingen = j; foundLadingen = true;
            }
        }
    }

    else{
        foundLadingen = true;
        for (int j = 0; j < (vaccins_transport_min + vaccin->getTransport())/vaccin->getTransport();
             ++j) {

            bool getLadingen = false;

            if ((tempVaccins - j*vaccin->getTransport()) > 0 ){ getLadingen = true;}

            if (j*vaccin->getTransport() + vaccinsCentrum <= capaciteitCentrum && foundLadingen && getLadingen){
                ladingen = j; foundLadingen = true;
            }
            else {
                break;
            }
        }
    }

    int inwonersTeVaccineren = centrum->getInwoners() - centrum->getVaccinatedFirstTime();


    int tempLadingen = 0;
    bool isChangedLadingen = false;
    while (inwonersTeVaccineren < vaccin->getTransport()*ladingen){
        tempLadingen = ladingen;
        ladingen--;
        isChangedLadingen = true;
    }

    if (isChangedLadingen){
        ladingen = tempLadingen;
    }


    centrum->setVaccins((ladingen * vaccin->getTransport()) + vaccinsCentrum, vaccinType);

    vaccin->setAantalVaccins(-(ladingen * vaccin->getTransport()));

    OT << "Er werden " << ladingen << " ladingen (" << ladingen * vaccin->getTransport() <<
       " vaccins) getransporteerd naar " << centrumNaam + ".\n";

    teVaccineren = vaccinatieInCentrum(centrum, vaccin, teVaccineren, day);

}

//bool Transport::isAllPeopleVaccinated(FileParser &file) {
//    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling isALlPeopleVaccinated");
//
//        for (unsigned int j = 0; j < file.fHubs.size(); j++) {
//            for (unsigned int i = 0; i < file.fHubs[j]->fHubCentra.size(); i++) {
//                if (file.fHubs[j]->fHubCentra[i]->getInwoners() != file.fHubs[j]->fHubCentra[i]->getVaccinatedFirstTime()) {
//                    return false;
//                }
//            }
//        }
//    return true;
//}

bool Transport::properlyInitialized() {

    return _initCheck == this;
}





//void Transport::transportSimulatie(FileParser &file) {
//
//    REQUIRE(this->properlyInitialized(), "transportSim wasn't initialized when calling transportSimulatie");
//    int day = 0;
//
//    //aanmaken uitvoer bestand
//    ofstream OT;
//
//    //openen van het uitvoerbestand
//    OT.open("../simulatieOutput/overzichtTransport.txt");
//    fOVP.open("../simulatieOutput/overzichtVaccinatieprocedure.txt");
//
////    while (!isAllPeopleVaccinated(file)){
//        //check allVaccinated
//
//        //als fInterval om is, nieuwe levering in de hub
//        if (day % (fLeveringInterval + 1) == 0) {
//            fAantalVaccins += file.fLeveringen;
////            cout << "week: " << day/7 << endl;
//        }
//
//        for (unsigned int i = 0; i < file.fCentra.size(); i++){
//
//            string centrumNaam centrum->getNaam();
//
//            int vaccinsCentrum centrum->getVaccins(centrumNaam);
//            int capaciteitCentrum centrum->getCapaciteit();
//
//            double vaccins_transport_min = capaciteitCentrum - vaccinsCentrum;
//
//            int ladingen = 0;
//            bool foundLadingen = false;
//
//            int tempVaccins = fAantalVaccins;
//
//            for (int j = 0; j < (vaccins_transport_min + file.fTransport) / file.fTransport; ++j) {
//                bool getLadingen = false;
//
//                if ((tempVaccins - j*file.fTransport) > 0 ){ getLadingen = true;}
//
//                if (j*file.fTransport + vaccinsCentrum >= capaciteitCentrum &&
//                    2*capaciteitCentrum >= j*file.fTransport + vaccinsCentrum && !foundLadingen && getLadingen){
//                    ladingen = j; foundLadingen = true;
//                }
//
//            }
//            centrum->setVaccins((ladingen * file.fTransport) + vaccinsCentrum, centrumNaam);
//
//            fAantalVaccins -= ladingen * file.fTransport;
//
//            OT << "Er werden " << ladingen << " ladingen (" << ladingen * file.fTransport <<
//               " fVaccinsInCentrum) getransporteerd naar " << centrumNaam + ".\n";
//
////            vaccinatieInCentrum(file.fCentra[i]);
//
//        }
//        OT << "\n";
//        day++;
//    }
////    file.fHubVaccins = fAantalVaccins;
////}