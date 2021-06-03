/*
 * korte beschrijving:
 * Test de algemene werking van het systeem + enkele randgevallen.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "../Header_files/FileParser.h"
#include "../Header_files/Distributie.h"

class SystemsTests: public ::testing::Test {
protected:
    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    FileParser parsedFile;

};

// Tests the default constructor.
TEST_F(SystemsTests, DefaultConstructor) { // fNaam test: DefaultConstructor

    for (unsigned int i = 1; i < 7; ++i) {
        FileParser newParsedFile;
        ostringstream number;
        number << i;
        string Number = number.str();
        string file = "../test-bestanden/systemFiles/systemTest" + Number + ".xml";
        EXPECT_EQ(0, newParsedFile.parseFile(file));
    }
}

// Tests the "beforeSimulation" scenario
TEST_F(SystemsTests, beforeSimulation) {

    string file = "../test-bestanden/systemFiles/systemTest1.xml";

    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);


}

// Tests the "afterSimulation" scenario
TEST_F(SystemsTests, afterSimulation){

    string file = "../test-bestanden/systemFiles/systemTest1.xml";

    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];
    //hub1
    Hub* hub1 = parsedFile.fHubs[1];

    //na simulatie
    Distributie distributie(parsedFile);

    //hub0
    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 1983000);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 477000);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 2680000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 1270892);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 265520);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 2680000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedSecondTime());


}

TEST_F(SystemsTests, NietGenoegVaccins){
    string file = "../test-bestanden/systemFiles/systemTest2.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 8000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 5000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 3000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 8000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 5000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 3000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);

    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 410565);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 123549);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 223500);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 1327);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 565);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 1471);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(455173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(60935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(227029, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 372000);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 114549);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 220500);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 327);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 1065);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 471);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(252000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(45500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(124000, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(SystemsTests, ZeerKortInterval){
    string file = "../test-bestanden/systemFiles/systemTest3.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 1);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 2);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 3);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 3);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 2);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 1);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 7873892);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 265520);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 3350000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 3223892);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 2657520);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 6700000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(SystemsTests, ZeerGrootInterval){
    string file = "../test-bestanden/systemFiles/systemTest4.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 30);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 40);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 50);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 30);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 40);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 50);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 2209827);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 823614);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 1076000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 65);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(462173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(74935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(201000, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 2209827);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 823614);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 1076000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 65);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(282173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(56935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(135000, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(SystemsTests, InwonersLessThanCapaciteit){
    string file = "../test-bestanden/systemFiles/systemTest5.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(55000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(55000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 1222941);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 328971);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 2672500);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 327);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 549);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 1222941);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 328971);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 2665000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 327);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 549);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(SystemsTests, ZeerKleinTransport){
    string file = "../test-bestanden/systemFiles/systemTest6.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 200);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 100);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 50);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 200);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 100);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 50);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 11469412);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 3295800);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 13400000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 27);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 65);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 149);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 171);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(255229, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 11469412);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 3295800);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 13400000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 27);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 65);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 149);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 171);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(255229, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(SystemsTests, groterAantalCentra){
    string file = "../test-bestanden/systemFiles/systemTest7.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(49451, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum5
    vaccinatiecentrum = hub1->fHubCentra[4];

    EXPECT_EQ("De Waai", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Werft 28, Geel", vaccinatiecentrum->getAdres());
    EXPECT_EQ(63478, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum6
    vaccinatiecentrum = hub1->fHubCentra[5];

    EXPECT_EQ("Evenementenhal De Soeverein", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Sportveldenstraat 10, Lommel", vaccinatiecentrum->getAdres());
    EXPECT_EQ(113256, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum7
    vaccinatiecentrum = hub1->fHubCentra[6];

    EXPECT_EQ("Welzijnscampus De Motten", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Dijk 124, Tongeren", vaccinatiecentrum->getAdres());
    EXPECT_EQ(179250, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 7);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 11872892);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 2887520);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 13400000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 971);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 11329857);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 2815071);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 13344500);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 1327);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 549);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 1971);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[4]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[4]->getVaccins(Moderna), 522);
    EXPECT_EQ(hub1->fHubCentra[4]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[5]->getVaccins(Pfizer), 244);
    EXPECT_EQ(hub1->fHubCentra[5]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[5]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[6]->getVaccins(Pfizer), 250);
    EXPECT_EQ(hub1->fHubCentra[6]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[6]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(228029, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum5
    vaccinatiecentrum = hub1->fHubCentra[4];
    EXPECT_EQ(63478, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(55978, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum6
    vaccinatiecentrum = hub1->fHubCentra[5];
    EXPECT_EQ(113256, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(109756, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum7
    vaccinatiecentrum = hub1->fHubCentra[6];
    EXPECT_EQ(179250, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(175750, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(SystemsTests, kleinerAantalCentra){
    string file = "../test-bestanden/systemFiles/systemTest8.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(540173, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(76935, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 2);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 2);

    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 1521892);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 490000);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 2613000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 1521892);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 490000);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 2613000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 1065);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(540173, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(76935, vaccinatiecentrum->getVaccinatedSecondTime());

}
