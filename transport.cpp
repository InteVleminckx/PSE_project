//
// Created by intev on 28/02/2021.
//

#include "transport.h"


transport::transport(fileParser &bestand) {
    file = bestand;
    leveringInterval = file.interval;
    aantalVaccins = 0;
    allVaccinated = false;
    transportSimulatie();
}

void transport::transportSimulatie() {

    int day = 0;

    //aanmaken uitvoer bestand
    ofstream myfile;

    //openen van het uitvoerbestand
    myfile.open("../overzichtTransport.txt");

    while (!allVaccinated){
        //check allVaccinated

        //als interval om is, nieuwe levering in de hub
        if (day % (leveringInterval+1) == 0){

            cout << "day: " << day << " levering" <<endl;

            aantalVaccins += file.leveringen;
            myfile << "week " << day/7 << " :\n";
            for (unsigned int i = 0; i < file.centra.size(); i++){

                string centrumNaam = file.centra[i].getNaam();

                int vaccinsCentrum = file.centra[i].getVaccins();
                int capaciteitCentrum = file.centra[i].getCapaciteit();

                double vaccins_transport_min = capaciteitCentrum - vaccinsCentrum;

                int ladingen = 0;
                bool foundLadingen = false;
                for (int j = 0; j < (vaccins_transport_min + file.transport)/file.transport; ++j) {

                    if (j*file.transport + vaccinsCentrum >= capaciteitCentrum &&
                        2*capaciteitCentrum >= j*file.transport + vaccinsCentrum && !foundLadingen){
                        ladingen = j; foundLadingen = true;
                    }
                }

                file.centra[i].setVaccins((ladingen*file.transport)+vaccinsCentrum);
                aantalVaccins -= ladingen*file.transport;

                std::ostringstream ladingenVaccins; ladingenVaccins << ladingen;
                std::ostringstream vaccinsToCentrum; vaccinsToCentrum << ladingen*file.transport;


                myfile << "Er werden " + ladingenVaccins.str() + " ladingen (" + vaccinsToCentrum.str() +
                          " vaccins) getransporteerd naar " + centrumNaam + ".\n";
            }

            myfile << "\n";

        }
        cout << day << endl;
        day++;
    }
}

