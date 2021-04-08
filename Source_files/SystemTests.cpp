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
#include "../Header_files/Transport.h"

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
    parsedFile.parseFile(file);

    EXPECT_GE(parsedFile.fLeveringen, 0); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_GT(parsedFile.fInterval, 0); // fInterval > 0

    EXPECT_GT(parsedFile.fTransport, 0); // Transport > 0

    EXPECT_GT(parsedFile.fCentra.size(), (unsigned) 0); // aantal fCentra > 0

    cout << "Start van de simulatie:" << endl;
    cout << "\n";

    cout << "Hub (" << parsedFile.fHubVaccins << " fVaccinsInCentrum)\n";

    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
        EXPECT_NE("", parsedFile.fCentra[centrum].getNaam()); // fNaam mag niet leeg zijn
        EXPECT_NE("", parsedFile.fCentra[centrum].getAdres()); // fAdres mag niet leeg zijn

        EXPECT_GE(parsedFile.fCentra[centrum].getInwoners(), 0); // inwoners centrum >= 0
        EXPECT_GE(parsedFile.fCentra[centrum].getCapaciteit(), 0); // fCapaciteit centrum >= 0

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccins(), 0); // fVaccinsInCentrum in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccins(), parsedFile.fCentra[centrum].getCapaciteit() * 2);

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccinated(), 0); // gevaccineerden in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccinated(), parsedFile.fCentra[centrum].getInwoners());
    }

    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
        cout << "\t-> " << parsedFile.fCentra[centrum].getNaam() << "(" << parsedFile.fCentra[centrum].getVaccins()
             << " fVaccinsInCentrum)""\n";
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
    Transport transport(parsedFile);

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0


    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccins(), 0); // fVaccinsInCentrum in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccins(), parsedFile.fCentra[centrum].getCapaciteit() * 2);

        EXPECT_GE(parsedFile.fCentra[centrum].getVaccinated(), 0); // gevaccineerden in centrum >= 0
        EXPECT_LE(parsedFile.fCentra[centrum].getVaccinated(), parsedFile.fCentra[centrum].getInwoners());

        //er kunnen niet meer mensen gevaccineerd zijn dan er inwoners zijn
        EXPECT_GE(parsedFile.fCentra[centrum].getInwoners() - parsedFile.fCentra[centrum].getVaccinated(), 0);

    }

    cout << "Einde van de simulatie:" << endl;
    cout << "\n";
    cout << "Hub (" << parsedFile.fHubVaccins << " fVaccinsInCentrum)\n";

    for (unsigned int centrum = 0; centrum < parsedFile.fCentra.size(); centrum++) {
        cout << "\t-> " << parsedFile.fCentra[centrum].getNaam() << "(" << parsedFile.fCentra[centrum].getVaccins()
             << " fVaccinsInCentrum)""\n";
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

    EXPECT_EQ(parsedFile.fLeveringen, 7000);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 1000);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 50000);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 5000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 20000);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 10000);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 1000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 40000);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 4000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 5000); // aantal fVaccinsInCentrum in hub >= 0


    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 5000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), 50000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 2000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), 20000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 1000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), 10000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 0); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), 40000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(SystemsTests, ZeerKortInterval){
    string file = "../test-bestanden/systemFiles/systemTest3.xml";
    parsedFile.parseFile(file);

    EXPECT_EQ(parsedFile.fLeveringen, 93000); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fInterval, 1); // fInterval > 0

    EXPECT_EQ(parsedFile.fTransport, 2000); // Transport > 0

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4); // aantal fCentra > 0

//    cout << "Start van de simulatie:" << endl;
//    cout << "\n";
//
//    cout << "Hub (" << parsedFile.fHubVaccins << " fVaccinsInCentrum)\n";

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 540173);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 7500);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 76935);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 49451);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 1000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 257029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 3000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 3063000); // aantal fVaccinsInCentrum in hub >= 0


    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 7827); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), 540173); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 3065); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), 76935); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 549); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), 49451); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 971); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(SystemsTests, ZeerGrootInterval){
    string file = "../test-bestanden/systemFiles/systemTest4.xml";
    parsedFile.parseFile(file);

    EXPECT_EQ(parsedFile.fLeveringen, 20000); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fInterval, 30); // fInterval > 0

    EXPECT_EQ(parsedFile.fTransport, 1000); // Transport > 0

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4); // aantal fCentra > 0

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 100000);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 5000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 20000);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 70000);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 1000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 40000);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 4000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 19000); // aantal fVaccinsInCentrum in hub >= 0


    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 5000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), 100000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 2000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), 20000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 0); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), 70000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 4000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), 40000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(SystemsTests, ZeerKleinTransport){
    string file = "../test-bestanden/systemFiles/systemTest5.xml";
    parsedFile.parseFile(file);

    EXPECT_EQ(parsedFile.fLeveringen, 30000); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fInterval, 6); // fInterval > 0

    EXPECT_EQ(parsedFile.fTransport, 100); // Transport > 0

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4); // aantal fCentra > 0


    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 241000);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 8000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 46000);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 4500);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 164000);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 6000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 89000);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 4000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 9500); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 8000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), 241000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 4500); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), 46000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 4000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), 164000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 4000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), 89000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(SystemsTests, InwonersLessThanCapaciteit){
    string file = "../test-bestanden/systemFiles/systemTest6.xml";
    parsedFile.parseFile(file);

    EXPECT_EQ(parsedFile.fLeveringen, 50000); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fInterval, 6); // fInterval > 0

    EXPECT_EQ(parsedFile.fTransport, 2000); // Transport > 0

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4); // aantal fCentra > 0


    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 15000);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 20000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 46000);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 4500);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 164000);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 6000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 89000);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 4000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 50000); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 21000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), 15000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 6000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), 46000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 4000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), 164000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 5000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), 89000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(SystemsTests, groterAantalCentra){
    string file = "../test-bestanden/systemFiles/systemTest7.xml";
    parsedFile.parseFile(file);

    EXPECT_EQ(parsedFile.fLeveringen, 50000); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fInterval, 6); // fInterval > 0

    EXPECT_EQ(parsedFile.fTransport, 2000); // Transport > 0

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 6); // aantal fCentra > 0

//    cout << "Start van de simulatie:" << endl;
//    cout << "\n";
//
//    cout << "Hub (" << parsedFile.fHubVaccins << " fVaccinsInCentrum)\n";

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 500000);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 20000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 140000);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 4500);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 164000);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 6000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());


    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 89000);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 4000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

    EXPECT_EQ("Luchtbal", parsedFile.fCentra[4].getNaam());
    EXPECT_EQ("Hertoginstraat 17, Antwerpen", parsedFile.fCentra[4].getAdres());
    EXPECT_EQ(parsedFile.fCentra[4].getInwoners(), 84000);
    EXPECT_EQ(parsedFile.fCentra[4].getCapaciteit(), 8000);
    EXPECT_GE(parsedFile.fCentra[4].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[4].getVaccins(), parsedFile.fCentra[4].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[4].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[4].getVaccinated(), parsedFile.fCentra[4].getInwoners());

    EXPECT_EQ("Grote Markt", parsedFile.fCentra[5].getNaam());
    EXPECT_EQ("Louisastraat 20, Antwerpen", parsedFile.fCentra[5].getAdres());
    EXPECT_EQ(parsedFile.fCentra[5].getInwoners(), 123000);
    EXPECT_EQ(parsedFile.fCentra[5].getCapaciteit(), 15500);
    EXPECT_GE(parsedFile.fCentra[5].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[5].getVaccins(), parsedFile.fCentra[5].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[5].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[5].getVaccinated(), parsedFile.fCentra[5].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 8000); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 0); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), 500000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 6000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), 140000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 6000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), 164000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinated(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 5000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), 89000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinated(), parsedFile.fCentra[3].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[4].getVaccins(), 8000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[4].getVaccinated(), 84000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[4].getVaccinated(), parsedFile.fCentra[4].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[5].getVaccins(), 17000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[5].getVaccinated(), 123000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[5].getVaccinated(), parsedFile.fCentra[5].getInwoners());

}

TEST_F(SystemsTests, kleinerAantalCentra){
    string file = "../test-bestanden/systemFiles/systemTest8.xml";
    parsedFile.parseFile(file);

    EXPECT_EQ(parsedFile.fLeveringen, 12000); // aantal fLeveringen >= 0

    EXPECT_GE(parsedFile.fHubVaccins, 0); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fInterval, 3); // fInterval > 0

    EXPECT_EQ(parsedFile.fTransport, 1300); // Transport > 0

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 2); // aantal fCentra > 0

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 95000);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 3500);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 27500);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 1987);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinated(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 3300); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 3800); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), 95000); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinated(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 2400); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), 27500); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinated(), parsedFile.fCentra[1].getInwoners());

}