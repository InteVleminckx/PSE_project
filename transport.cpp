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
    ofstream OT;

    //openen van het uitvoerbestand
    OT.open("../overzichtTransport.txt");
    OVP.open("../overzichtVaccinatieprocedure.txt");


    while (!allVaccinated){
        //check allVaccinated

        //als interval om is, nieuwe levering in de hub
        if (day % (leveringInterval+1) == 0) {aantalVaccins += file.leveringen;}

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

            OT << "Er werden " << ladingen << " ladingen (" << ladingen * file.transport <<
               " vaccins) getransporteerd naar " << centrumNaam + ".\n";

            vaccinatieInCentrum(file.centra[i]);

        }
        OT << "\n";
        day++;
    }
}

void transport::vaccinatieInCentrum(vaccinatiecentrum &centrum) {

    int vaccinsInCentrum = centrum.getVaccins();
    int capaciteit = centrum.getCapaciteit();
    int aantalOngevaccineerden = centrum.getInwoners() - centrum.getVaccinated();

    int inwonersGevaccineerd = min(vaccinsInCentrum, capaciteit);
    inwonersGevaccineerd = min(inwonersGevaccineerd, aantalOngevaccineerden); // min van drie elementen werkt niet, dus we hebben het 2 keer apart gedaan.

    centrum.setVaccinated(inwonersGevaccineerd);
    centrum.setVaccins(centrum.getVaccins() - inwonersGevaccineerd);

    OVP << "Er werden " << inwonersGevaccineerd << " inwoners gevaccineerd in " << centrum.getNaam() << ".\n";
}

