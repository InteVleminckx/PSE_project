/*
 * korte beschrijving:
 * Test de xml file op correcte invoer + nog enkele simulatie tests.
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cmath>
#include "../Header_files/FileParser.h"
#include "../Header_files/Transport.h"

class InputTests: public ::testing::Test {
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

TEST_F(InputTests, failedFile1) {

    string file = "../test-bestanden/failFiles/failedFile1.xml";
    EXPECT_TRUE(parsedFile.parseFile(file));

//    try {
//        parsedFile.parseFile(file);
//        fail(); // did not throw
//    } catch (bool e) {
//        cout << "Fout" << endl;
//    }

}

TEST_F(InputTests, failedFile2) {
    string file = "../test-bestanden/failFiles/failedFile2.xml";
    EXPECT_TRUE(parsedFile.parseFile(file));
}

TEST_F(InputTests, failedFile3) {

    string file = "../test-bestanden/failFiles/failedFile3.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile4) {

    string file = "../test-bestanden/failFiles/failedFile4.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile5) {

    string file = "../test-bestanden/failFiles/failedFile5.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile6) {

    string file = "../test-bestanden/failFiles/failedFile6.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile7) {

    string file = "../test-bestanden/failFiles/failedFile7.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile8) {

    string file = "../test-bestanden/failFiles/failedFile8.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile9) {

    string file = "../test-bestanden/failFiles/failedFile9.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile10) {

    string file = "../test-bestanden/failFiles/failedFile10.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile11) {

    string file = "../test-bestanden/failFiles/failedFile11.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile12) {

    string file = "../test-bestanden/failFiles/failedFile12.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile13) {

    string file = "../test-bestanden/failFiles/failedFile13.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile14) {

    string file = "../test-bestanden/failFiles/failedFile14.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile15) {

    string file = "../test-bestanden/failFiles/failedFile15.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile16) {

    string file = "../test-bestanden/failFiles/failedFile16.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile17) {

    string file = "../test-bestanden/failFiles/failedFile17.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile18) {

    string file = "../test-bestanden/failFiles/failedFile18.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile19) {

    string file = "../test-bestanden/failFiles/failedFile19.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile20) {

    string file = "../test-bestanden/failFiles/failedFile20.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, failedFile21) {

    string file = "../test-bestanden/failFiles/failedFile21.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, succesFile1) {

    string file = "../test-bestanden/succesFiles/succesFile1.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 20000);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 2000);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 456500);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 5000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 76935);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 39502);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 1000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 257029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 3000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 16000); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 5500); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 456500); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 3065); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 76935); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 498); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 39502); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 4971); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(InputTests, succesFile2) {

    string file = "../test-bestanden/succesFiles/succesFile2.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 193000);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 12000);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 540173);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 17500);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 76935);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 12000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 49451);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 11000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 257029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 13000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 162000); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 23827); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 540173); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 19065); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 76935); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 10549); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 49451); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 18971); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(InputTests, succesFile3) {

    string file = "../test-bestanden/succesFiles/succesFile3.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 9000);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 200);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 54073);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 7500);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 7695);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 4941);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 1000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 257029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 3000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 6600); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 7527); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 54073); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 2105); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 7695); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 1059); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 4941); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 971); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(InputTests, succesFile4) {

    string file = "../test-bestanden/succesFiles/succesFile4.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 5000);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 500);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 540555);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 5500);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 769555);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 20055);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 495541);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 10050);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 257029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 30000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 2500); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 5945); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 540555); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 20445); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 769555); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 10459); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 495541); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 12971); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());
}

TEST_F(InputTests, succesFile5) {

    string file = "../test-bestanden/succesFiles/succesFile5.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 12345);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 5);

    EXPECT_EQ(parsedFile.fTransport, 123);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 23456);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 10000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 15975);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2500);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 64656);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 1650);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 257029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 3000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 4839); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 10000); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 23456); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 2598); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 15975); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 1764); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 64656); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 2378); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(InputTests, succesFile6) {

    string file = "../test-bestanden/succesFiles/succesFile6.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 150000);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 10000);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 5405755);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 55000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 7695755);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 20055);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 4905541);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 10050);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 257029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 30000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 200000); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 64245); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 5405755); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 24245); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 7695755); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 14459); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 4905541); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 32971); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}

TEST_F(InputTests, succesFile7) {

    string file = "../test-bestanden/succesFiles/succesFile7.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 98765);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 5);

    EXPECT_EQ(parsedFile.fTransport, 555);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 44444);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 1111);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 66666);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2222);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 999999);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 3333);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 159615);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 555);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 3757740); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 1621); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 44444); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 2709); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 66666); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 3441); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 999999); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 780); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 159615); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}
//
TEST_F(InputTests, succesFile8) {

    string file = "../test-bestanden/succesFiles/succesFile8.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 39000);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 2000);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 371045);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 5700);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 53967);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 2000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 15494);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 1000);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 920872);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 3000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 615000); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 6955); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 371045); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 2033); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 53967); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 506); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 15494); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 3128); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 920872); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}
//
TEST_F(InputTests, succesFile9) {

    string file = "../test-bestanden/succesFiles/succesFile9.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 930001);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 20001);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 5401731);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 75001);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 769351);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 20001);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 494511);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 10001);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 2570291);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 30001);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 2709544); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 78543); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 5401731); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 30689); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 769351); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 5514); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 494511); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 29839); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 2570291); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());
}
//
TEST_F(InputTests, succesFile10) {

    string file = "../test-bestanden/succesFiles/succesFile10.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.fLeveringen, 455514);

    EXPECT_GE(parsedFile.fHubVaccins, 0);

    EXPECT_EQ(parsedFile.fInterval, 6);

    EXPECT_EQ(parsedFile.fTransport, 17500);

    EXPECT_EQ(parsedFile.fCentra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.fCentra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.fCentra[0].getAdres());
    EXPECT_EQ(parsedFile.fCentra[0].getInwoners(), 5401730);
    EXPECT_EQ(parsedFile.fCentra[0].getCapaciteit(), 75000);
    EXPECT_GE(parsedFile.fCentra[0].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccins(), parsedFile.fCentra[0].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[0].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.fCentra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.fCentra[1].getAdres());
    EXPECT_EQ(parsedFile.fCentra[1].getInwoners(), 769035);
    EXPECT_EQ(parsedFile.fCentra[1].getCapaciteit(), 22000);
    EXPECT_GE(parsedFile.fCentra[1].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccins(), parsedFile.fCentra[1].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[1].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.fCentra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.fCentra[2].getAdres());
    EXPECT_EQ(parsedFile.fCentra[2].getInwoners(), 494051);
    EXPECT_EQ(parsedFile.fCentra[2].getCapaciteit(), 10200);
    EXPECT_GE(parsedFile.fCentra[2].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccins(), parsedFile.fCentra[2].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[2].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.fCentra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.fCentra[3].getAdres());
    EXPECT_EQ(parsedFile.fCentra[3].getInwoners(), 2507029);
    EXPECT_EQ(parsedFile.fCentra[3].getCapaciteit(), 32000);
    EXPECT_GE(parsedFile.fCentra[3].getVaccins(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccins(), parsedFile.fCentra[3].getCapaciteit() * 2);
    EXPECT_GE(parsedFile.fCentra[3].getVaccinatedFirstTime(), 0);
    EXPECT_LE(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.fHubVaccins, 255794); // aantal fVaccinsInCentrum in hub >= 0

    EXPECT_EQ(parsedFile.fCentra[0].getVaccins(), 75770 ); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), 5401730); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[0].getVaccinatedFirstTime(), parsedFile.fCentra[0].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[1].getVaccins(), 35965); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), 769035); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[1].getVaccinatedFirstTime(), parsedFile.fCentra[1].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[2].getVaccins(), 13449); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), 494051); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[2].getVaccinatedFirstTime(), parsedFile.fCentra[2].getInwoners());

    EXPECT_EQ(parsedFile.fCentra[3].getVaccins(), 12971); // fVaccinsInCentrum in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), 2507029); // gevaccineerden in centrum >= 0
    EXPECT_EQ(parsedFile.fCentra[3].getVaccinatedFirstTime(), parsedFile.fCentra[3].getInwoners());

}

