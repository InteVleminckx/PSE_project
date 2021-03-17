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

    EXPECT_GE(parsedFile.fLeveringen, 0); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal vaccins in hub >= 0

    EXPECT_GT(parsedFile.fInterval, 0); // fInterval > 0

    EXPECT_GT(parsedFile.fTransport, 0); // Transport > 0

    EXPECT_GT(parsedFile.fCentra.size(), (unsigned) 0); // aantal fCentra > 0

    cout << "Start van de simulatie:" << endl;
    cout << "\n";

    cout << "Hub (" << parsedFile.fHubVaccins << " vaccins)\n";

    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
        EXPECT_NE("", parsedFile.fCentra[centrum].getNaam()); // naam mag niet leeg zijn
        EXPECT_NE("", parsedFile.fCentra[centrum].getAdres()); // adres mag niet leeg zijn

        EXPECT_GE(parsedFile.fCentra[centrum].getInwoners(), 0); // inwoners centrum >= 0
        EXPECT_GE(parsedFile.fCentra[centrum].getCapaciteit(), 0); // capaciteit centrum >= 0

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccins(), 0); // vaccins in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccins(), parsedFile.fCentra[centrum].getCapaciteit() * 2);

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccinated(), 0); // gevaccineerden in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccinated(), parsedFile.fCentra[centrum].getInwoners());
    }

    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
        cout << "\t-> " << parsedFile.fCentra[centrum].getNaam() << "(" << parsedFile.fCentra[centrum].getVaccins()
             << " vaccins)""\n";
    }
    //wit regel in het bestand
    cout << "\n";
    //lopen terug over de fCentra
    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
    //berekenen het aantal niet gevaccineerden
        int aantalNietGevaccineerden = parsedFile.fCentra[centrum].getInwoners()
                                   - parsedFile.fCentra[centrum].getVaccinated();
        cout << parsedFile.fCentra[centrum].getNaam() << ": " << parsedFile.fCentra[centrum].getVaccinated()
             << " gevaccineerd, nog " << aantalNietGevaccineerden << " niet gevaccineerd\n";
    }

}

// Tests the "afterSimulation" scenario
TEST_F(SystemsTests, afterSimulation){

    string file = "../test-bestanden/systemFiles/systemTest1.xml";
    parsedFile.parseFile(file);
    Transport transportSim(parsedFile);

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal vaccins in hub >= 0


    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccins(), 0); // vaccins in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccins(), parsedFile.fCentra[centrum].getCapaciteit() * 2);

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccinated(), 0); // gevaccineerden in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccinated(), parsedFile.fCentra[centrum].getInwoners());

        //er kunnen niet meer mensen gevaccineerd zijn dan er inwoners zijn
        EXPECT_GE(parsedFile.fCentra[centrum].getInwoners() - parsedFile.fCentra[centrum].getVaccinated(), 0);

    }

    cout << "Einde van de simulatie:" << endl;
    cout << "\n";
    cout << "Hub (" << parsedFile.fHubVaccins << " vaccins)\n";

    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
        cout << "\t-> " << parsedFile.fCentra[centrum].getNaam() << "(" << parsedFile.fCentra[centrum].getVaccins()
             << " vaccins)""\n";
    }
    //wit regel in het bestand
    cout << "\n";
    //lopen terug over de fCentra
    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
        //berekenen het aantal niet gevaccineerden
        int aantalNietGevaccineerden = parsedFile.fCentra[centrum].getInwoners()
                                       - parsedFile.fCentra[centrum].getVaccinated();
        cout << parsedFile.fCentra[centrum].getNaam() << ": " << parsedFile.fCentra[centrum].getVaccinated()
             << " gevaccineerd, nog " << aantalNietGevaccineerden << " niet gevaccineerd\n";
    }
}

TEST_F(SystemsTests, NietGenoegVaccins){
    string file = "../test-bestanden/systemFiles/systemTest2.xml";
    parsedFile.parseFile(file);
    Transport transportSim(parsedFile);

}