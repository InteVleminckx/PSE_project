/*
 * korte beschrijving:
 * Roept alle testen op.
 * Deze klasse runt alle testen.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include <gtest/gtest.h>

#include "TinyXML/tinyxml.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "Vaccinatiecentrum.h"
#include <fstream>
#include "FileParser.h"
#include "Transport.h"

class SimulatieTest: public ::testing::Test {
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
TEST_F(SimulatieTest, DefaultConstructor) { // naam test: DefaultConstructor

    string file = "../bestand1.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

}

// Tests the "beforeSimulation" scenario
TEST_F(SimulatieTest, beforeSimulation) {

    string file = "../bestand1.xml";
    parsedFile.parseFile(file);

//    int type = 0;
//
//    REQUIRE((typeid(parsedFile.leveringen) == typeid(type)), "Leveringen moet een integer zijn");


//    REQUIRE((typeid(parsedFile.leveringen) != typeid(int)), "Leveringen moet een integer zijn");
    EXPECT_GE(parsedFile.leveringen, 0); // aantal leveringen >= 0
    EXPECT_GE(parsedFile.hubVaccins, 0); // aantal vaccins in hub >= 0
    EXPECT_GE(parsedFile.interval, 0); // interval >= 0
    EXPECT_GE(parsedFile.transport, 0); // Transport >= 0

    EXPECT_GT(parsedFile.centra.size(), (unsigned) 0); // aantal centra > 0

    cout << "Start van de simulatie:" << endl;
    cout << "Hub (" << parsedFile.hubVaccins << " vaccins)\n";


    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        EXPECT_NE("", parsedFile.centra[centrum].getNaam()); // naam mag niet leeg zijn
        EXPECT_NE("", parsedFile.centra[centrum].getAdres()); // adres mag niet leeg zijn

        EXPECT_GE(parsedFile.centra[centrum].getInwoners(),0); // inwoners centrum >= 0
        EXPECT_GE(parsedFile.centra[centrum].getCapaciteit(),0); // capaciteit centrum >= 0

        EXPECT_GE(parsedFile.centra[centrum].getVaccins(),0); // vaccins in centrum >= 0
        EXPECT_LE(parsedFile.centra[centrum].getVaccins(), parsedFile.centra[centrum].getCapaciteit()*2);

        EXPECT_GE( parsedFile.centra[centrum].getVaccinated(), 0); // gevaccineerden in centrum >= 0
        EXPECT_LE( parsedFile.centra[centrum].getVaccinated(), parsedFile.centra[centrum].getInwoners());

    }

    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        cout << "\t-> " << parsedFile.centra[centrum].getNaam() << "(" << parsedFile.centra[centrum].getVaccins()
            << " vaccins)""\n";
    }
    //wit regel in het bestand
    cout << "\n";
    //lopen terug over de centra
    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        //berekenen het aantal niet gevaccineerden
        int aantalNietGevaccineerden = parsedFile.centra[centrum].getInwoners()
                - parsedFile.centra[centrum].getVaccinated();
        cout << parsedFile.centra[centrum].getNaam() << ": " << parsedFile.centra[centrum].getVaccinated()
            << " gevaccineerd, nog " << aantalNietGevaccineerden << " niet gevaccineerd\n";
    }

}

// Tests the "afterSimulation" scenario
TEST_F(SimulatieTest, afterSimulation){

    string file = "../bestand1.xml";
    parsedFile.parseFile(file);
    Transport transportSim(parsedFile);

    EXPECT_GE(parsedFile.hubVaccins, 0); // aantal vaccins in hub >= 0


    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {

        EXPECT_GE(parsedFile.centra[centrum].getVaccins(),0); // vaccins in centrum >= 0
        EXPECT_LE(parsedFile.centra[centrum].getVaccins(), parsedFile.centra[centrum].getCapaciteit()*2);

        EXPECT_GE( parsedFile.centra[centrum].getVaccinated(), 0); // gevaccineerden in centrum >= 0
        EXPECT_LE( parsedFile.centra[centrum].getVaccinated(), parsedFile.centra[centrum].getInwoners());

        //er kunnen niet meer mensen gevaccineerd zijn dan er inwoners zijn
        EXPECT_GE(parsedFile.centra[centrum].getInwoners() - parsedFile.centra[centrum].getVaccinated(), 0);

    }

    cout << "Einde van de simulatie:" << endl;
    cout << "Hub (" << parsedFile.hubVaccins << " vaccins)\n";

    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        cout << "\t-> " << parsedFile.centra[centrum].getNaam() << "(" << parsedFile.centra[centrum].getVaccins()
            << " vaccins)""\n";
    }
    //wit regel in het bestand
    cout << "\n";
    //lopen terug over de centra
    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        //berekenen het aantal niet gevaccineerden
        int aantalNietGevaccineerden = parsedFile.centra[centrum].getInwoners()
            - parsedFile.centra[centrum].getVaccinated();
        cout << parsedFile.centra[centrum].getNaam() << ": " << parsedFile.centra[centrum].getVaccinated()
            << " gevaccineerd, nog " << aantalNietGevaccineerden << " niet gevaccineerd\n";
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}