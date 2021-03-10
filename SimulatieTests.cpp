//
// Created by Maksim Karnaukh on 10/03/2021.
//

#include <gtest/gtest.h>

#include "TinyXML/tinyxml.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "vaccinatiecentrum.h"
#include <fstream>
#include "fileParser.h"

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
    fileParser parsedFile; // dit gebruiken ?

};

// Tests the default constructor.
TEST_F(SimulatieTest, DefaultConstructor) { // naam test: DefaultConstructor
    EXPECT_EQ(0, parsedFile.parseFile((string &) "../bestand1.xml"));
}

// Tests the "happy day" scenario
TEST_F(SimulatieTest, HappyDay) {
    EXPECT_GE(0, parsedFile.leveringen); // aantal leveringen >= 0
    EXPECT_GE(0, parsedFile.hubVaccins); // aantal vaccins in hub >= 0
    EXPECT_GE(0, parsedFile.interval); // interval >= 0
    EXPECT_GE(0, parsedFile.transport); // transport >= 0

    EXPECT_NE(0, parsedFile.centra.size()); // aantal centra != 0

    cout << "Start van de simulatie" << endl;
    cout << "Hub (" << parsedFile.hubVaccins << " vaccins)\n";


    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        EXPECT_NE("", parsedFile.centra[centrum].getNaam()); // naam mag niet leeg zijn
        EXPECT_NE("", parsedFile.centra[centrum].getAdres()); // adres mag niet leeg zijn

        EXPECT_GE(0, parsedFile.centra[centrum].getInwoners()); // inwoners centrum >= 0
        EXPECT_GE(0, parsedFile.centra[centrum].getCapaciteit()); // capaciteit centrum >= 0

        EXPECT_GE(0, parsedFile.centra[centrum].getVaccins()); // vaccins in centrum >= 0
        EXPECT_LE(parsedFile.centra[centrum].getCapaciteit()*2, parsedFile.centra[centrum].getVaccins()); // klopt dit ??

        EXPECT_GE(0, parsedFile.centra[centrum].getVaccinated()); // gevaccineerden in centrum >= 0
        EXPECT_LE(parsedFile.centra[centrum].getInwoners(), parsedFile.centra[centrum].getVaccinated()); // klopt dit ??

    }

    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        cout << "\t-> " << parsedFile.centra[centrum].getNaam() << "(" << parsedFile.centra[centrum].getVaccins() << " vaccins)""\n";
    }
    //wit regel in het bestand
    cout << "\n";
    //lopen terug over de centra
    for (unsigned int centrum = 0; centrum < parsedFile.centra.size(); centrum++) {
        //berekenen het aantal niet gevaccineerden
        int aantalNietGevaccineerden = parsedFile.centra[centrum].getInwoners() - parsedFile.centra[centrum].getVaccinated();
        cout << parsedFile.centra[centrum].getNaam() << ": " << parsedFile.centra[centrum].getVaccinated() << " gevaccineerd, nog " << aantalNietGevaccineerden << " niet gevaccineerd\n";
    }



}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}