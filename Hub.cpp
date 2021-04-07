//
// Created by inte on 20.03.21.
//

#include "Hub.h"

Hub::Hub() {
    _initCheck = this;
    VCcounter = 0;
    ENSURE(this->properlyInitialized(), "Constructor was not properly initialized");
}

//void Hub::distributie(FileParser &file) {
//    REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling distributie");
//
//    int day = 0;
//
//    //aanmaken uitvoer bestand
//    ofstream OT;
//
//    //openen van het uitvoerbestand
//    OT.open("../simulatieOutput/overzichtTransport.txt");
//
//
//    while (!isAllPeopleVaccinated(file)){
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
//            string centrumNaam = file.fCentra[i].getNaam();
//
//            int vaccinsCentrum = file.fCentra[i].getVaccins();
//            int capaciteitCentrum = file.fCentra[i].getCapaciteit();
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
//            }
//
//            file.fCentra[i].setVaccins((ladingen * file.fTransport) + vaccinsCentrum);
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
//    file.fHubVaccins = fAantalVaccins;
//
//
//}

//bool Hub::isAllPeopleVaccinated(FileParser &file) {
//    REQUIRE(this->properlyInitialized(), "Hub wasn't initialized when calling isALlPeopleVaccinated");
//
//    for (unsigned int i = 0; i < file.fCentra.size(); i++) {
//        if (file.fCentra[i].getInwoners() != file.fCentra[i].getVaccinated()) {
//            return false;
//        }
//    }
//    return true;
//}


bool Hub::properlyInitialized() {

    return _initCheck == this;
}