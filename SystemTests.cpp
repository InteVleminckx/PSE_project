//
// Created by inte on 13.03.21.
//
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
TEST_F(SystemsTests, DefaultConstructor) { // naam test: DefaultConstructor

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
    parsedFile.parseFile(file);

    EXPECT_GE(parsedFile.leveringen, 0); // aantal leveringen >= 0

    EXPECT_GE(parsedFile.hubVaccins, 0); // aantal vaccins in hub >= 0

    EXPECT_GT(parsedFile.interval, 0); // interval > 0

    EXPECT_GT(parsedFile.transport, 0); // Transport > 0

    EXPECT_GT(parsedFile.centra.size(), (unsigned) 0); // aantal centra > 0

    cout << "Start van de simulatie:" << endl;
    cout << "\n";

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
TEST_F(SystemsTests, afterSimulation){

    string file = "../test-bestanden/systemFiles/systemTest1.xml";
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
    cout << "\n";
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

TEST_F(SystemsTests, NietGenoegVaccins){
    string file = "../test-bestanden/systemFiles/systemTest2.xml";
    parsedFile.parseFile(file);
    Transport transportSim(parsedFile);

}