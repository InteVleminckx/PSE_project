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
    EXPECT_TRUE( parsedFile.parseFile(file));
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

TEST_F(InputTests, DefaultConstructor22) {

    string file = "../test-bestanden/succesFiles/succesFile1.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.leveringen, 20000);

    EXPECT_GE(parsedFile.hubVaccins, 0);

    EXPECT_EQ(parsedFile.interval, 6);

    EXPECT_EQ(parsedFile.transport, 2000);

    EXPECT_EQ(parsedFile.centra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.centra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.centra[0].getAdres());
    EXPECT_EQ(parsedFile.centra[0].getInwoners(),456500);
    EXPECT_EQ(parsedFile.centra[0].getCapaciteit(),5000);
    EXPECT_GE(parsedFile.centra[0].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[0].getVaccins(), parsedFile.centra[0].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[0].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.centra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.centra[1].getAdres());
    EXPECT_EQ(parsedFile.centra[1].getInwoners(),76935);
    EXPECT_EQ(parsedFile.centra[1].getCapaciteit(),2000);
    EXPECT_GE(parsedFile.centra[1].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[1].getVaccins(), parsedFile.centra[1].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[1].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.centra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.centra[2].getAdres());
    EXPECT_EQ(parsedFile.centra[2].getInwoners(),39502);
    EXPECT_EQ(parsedFile.centra[2].getCapaciteit(),1000);
    EXPECT_GE(parsedFile.centra[2].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[2].getVaccins(), parsedFile.centra[2].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[2].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.centra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.centra[3].getAdres());
    EXPECT_EQ(parsedFile.centra[3].getInwoners(),257029);
    EXPECT_EQ(parsedFile.centra[3].getCapaciteit(),3000);
    EXPECT_GE(parsedFile.centra[3].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[3].getVaccins(), parsedFile.centra[3].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[3].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.hubVaccins, 16000); // aantal vaccins in hub >= 0

    EXPECT_EQ(parsedFile.centra[0].getVaccins(),5500); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), 456500); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ(parsedFile.centra[1].getVaccins(),3065); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), 76935); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ(parsedFile.centra[2].getVaccins(),498); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), 39502); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ(parsedFile.centra[3].getVaccins(),4971); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

}

TEST_F(InputTests, succesFile2) {

    string file = "../test-bestanden/succesFiles/succesFile2.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.leveringen, 193000);

    EXPECT_GE(parsedFile.hubVaccins, 0);

    EXPECT_EQ(parsedFile.interval, 6);

    EXPECT_EQ(parsedFile.transport, 12000);

    EXPECT_EQ(parsedFile.centra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.centra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.centra[0].getAdres());
    EXPECT_EQ(parsedFile.centra[0].getInwoners(),540173);
    EXPECT_EQ(parsedFile.centra[0].getCapaciteit(),17500);
    EXPECT_GE(parsedFile.centra[0].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[0].getVaccins(), parsedFile.centra[0].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[0].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.centra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.centra[1].getAdres());
    EXPECT_EQ(parsedFile.centra[1].getInwoners(),76935);
    EXPECT_EQ(parsedFile.centra[1].getCapaciteit(),12000);
    EXPECT_GE(parsedFile.centra[1].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[1].getVaccins(), parsedFile.centra[1].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[1].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.centra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.centra[2].getAdres());
    EXPECT_EQ(parsedFile.centra[2].getInwoners(),49451);
    EXPECT_EQ(parsedFile.centra[2].getCapaciteit(),11000);
    EXPECT_GE(parsedFile.centra[2].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[2].getVaccins(), parsedFile.centra[2].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[2].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.centra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.centra[3].getAdres());
    EXPECT_EQ(parsedFile.centra[3].getInwoners(),257029);
    EXPECT_EQ(parsedFile.centra[3].getCapaciteit(),13000);
    EXPECT_GE(parsedFile.centra[3].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[3].getVaccins(), parsedFile.centra[3].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[3].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.hubVaccins, 162000); // aantal vaccins in hub >= 0

    EXPECT_EQ(parsedFile.centra[0].getVaccins(),23827); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), 540173); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ(parsedFile.centra[1].getVaccins(),19065); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), 76935); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ(parsedFile.centra[2].getVaccins(),10549); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), 49451); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ(parsedFile.centra[3].getVaccins(),18971); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

}

TEST_F(InputTests, succesFile3) {

    string file = "../test-bestanden/succesFiles/succesFile3.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.leveringen, 9000);

    EXPECT_GE(parsedFile.hubVaccins, 0);

    EXPECT_EQ(parsedFile.interval, 6);

    EXPECT_EQ(parsedFile.transport, 200);

    EXPECT_EQ(parsedFile.centra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.centra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.centra[0].getAdres());
    EXPECT_EQ(parsedFile.centra[0].getInwoners(),54073);
    EXPECT_EQ(parsedFile.centra[0].getCapaciteit(),7500);
    EXPECT_GE(parsedFile.centra[0].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[0].getVaccins(), parsedFile.centra[0].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[0].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.centra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.centra[1].getAdres());
    EXPECT_EQ(parsedFile.centra[1].getInwoners(),7695);
    EXPECT_EQ(parsedFile.centra[1].getCapaciteit(),2000);
    EXPECT_GE(parsedFile.centra[1].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[1].getVaccins(), parsedFile.centra[1].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[1].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.centra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.centra[2].getAdres());
    EXPECT_EQ(parsedFile.centra[2].getInwoners(),4941);
    EXPECT_EQ(parsedFile.centra[2].getCapaciteit(),1000);
    EXPECT_GE(parsedFile.centra[2].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[2].getVaccins(), parsedFile.centra[2].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[2].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.centra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.centra[3].getAdres());
    EXPECT_EQ(parsedFile.centra[3].getInwoners(),257029);
    EXPECT_EQ(parsedFile.centra[3].getCapaciteit(),3000);
    EXPECT_GE(parsedFile.centra[3].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[3].getVaccins(), parsedFile.centra[3].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[3].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.hubVaccins, 6600); // aantal vaccins in hub >= 0

    EXPECT_EQ(parsedFile.centra[0].getVaccins(),7527); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), 54073); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ(parsedFile.centra[1].getVaccins(),2105); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), 7695); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ(parsedFile.centra[2].getVaccins(),1059); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), 4941); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ(parsedFile.centra[3].getVaccins(),971); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

}

TEST_F(InputTests, succesFile4) {

    string file = "../test-bestanden/succesFiles/succesFile4.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.leveringen, 5000);

    EXPECT_GE(parsedFile.hubVaccins, 0);

    EXPECT_EQ(parsedFile.interval, 6);

    EXPECT_EQ(parsedFile.transport, 500);

    EXPECT_EQ(parsedFile.centra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.centra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.centra[0].getAdres());
    EXPECT_EQ(parsedFile.centra[0].getInwoners(),540555);
    EXPECT_EQ(parsedFile.centra[0].getCapaciteit(),5500);
    EXPECT_GE(parsedFile.centra[0].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[0].getVaccins(), parsedFile.centra[0].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[0].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.centra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.centra[1].getAdres());
    EXPECT_EQ(parsedFile.centra[1].getInwoners(),769555);
    EXPECT_EQ(parsedFile.centra[1].getCapaciteit(),20055);
    EXPECT_GE(parsedFile.centra[1].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[1].getVaccins(), parsedFile.centra[1].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[1].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.centra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.centra[2].getAdres());
    EXPECT_EQ(parsedFile.centra[2].getInwoners(),495541);
    EXPECT_EQ(parsedFile.centra[2].getCapaciteit(),10050);
    EXPECT_GE(parsedFile.centra[2].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[2].getVaccins(), parsedFile.centra[2].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[2].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.centra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.centra[3].getAdres());
    EXPECT_EQ(parsedFile.centra[3].getInwoners(),257029);
    EXPECT_EQ(parsedFile.centra[3].getCapaciteit(),30000);
    EXPECT_GE(parsedFile.centra[3].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[3].getVaccins(), parsedFile.centra[3].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[3].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.hubVaccins, 2500); // aantal vaccins in hub >= 0

    EXPECT_EQ(parsedFile.centra[0].getVaccins(),5945); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), 540555); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ(parsedFile.centra[1].getVaccins(),20445); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), 769555); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ(parsedFile.centra[2].getVaccins(),10459); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), 495541); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ(parsedFile.centra[3].getVaccins(),12971); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());
}

TEST_F(InputTests, succesFile5) {

    string file = "../test-bestanden/succesFiles/succesFile5.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.leveringen, 12345);

    EXPECT_GE(parsedFile.hubVaccins, 0);

    EXPECT_EQ(parsedFile.interval, 5);

    EXPECT_EQ(parsedFile.transport, 123);

    EXPECT_EQ(parsedFile.centra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.centra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.centra[0].getAdres());
    EXPECT_EQ(parsedFile.centra[0].getInwoners(),23456);
    EXPECT_EQ(parsedFile.centra[0].getCapaciteit(),10000);
    EXPECT_GE(parsedFile.centra[0].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[0].getVaccins(), parsedFile.centra[0].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[0].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.centra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.centra[1].getAdres());
    EXPECT_EQ(parsedFile.centra[1].getInwoners(),15975);
    EXPECT_EQ(parsedFile.centra[1].getCapaciteit(),2500);
    EXPECT_GE(parsedFile.centra[1].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[1].getVaccins(), parsedFile.centra[1].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[1].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.centra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.centra[2].getAdres());
    EXPECT_EQ(parsedFile.centra[2].getInwoners(),64656);
    EXPECT_EQ(parsedFile.centra[2].getCapaciteit(),1650);
    EXPECT_GE(parsedFile.centra[2].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[2].getVaccins(), parsedFile.centra[2].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[2].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.centra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.centra[3].getAdres());
    EXPECT_EQ(parsedFile.centra[3].getInwoners(),257029);
    EXPECT_EQ(parsedFile.centra[3].getCapaciteit(),3000);
    EXPECT_GE(parsedFile.centra[3].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[3].getVaccins(), parsedFile.centra[3].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[3].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.hubVaccins, 4839); // aantal vaccins in hub >= 0

    EXPECT_EQ(parsedFile.centra[0].getVaccins(),10000); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), 23456); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ(parsedFile.centra[1].getVaccins(),2598); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), 15975); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ(parsedFile.centra[2].getVaccins(),1764); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), 64656); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ(parsedFile.centra[3].getVaccins(),2378); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

}

TEST_F(InputTests, succesFile6) {

    string file = "../test-bestanden/succesFiles/succesFile6.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.leveringen, 150000);

    EXPECT_GE(parsedFile.hubVaccins, 0);

    EXPECT_EQ(parsedFile.interval, 6);

    EXPECT_EQ(parsedFile.transport, 10000);

    EXPECT_EQ(parsedFile.centra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.centra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.centra[0].getAdres());
    EXPECT_EQ(parsedFile.centra[0].getInwoners(),5405755);
    EXPECT_EQ(parsedFile.centra[0].getCapaciteit(),55000);
    EXPECT_GE(parsedFile.centra[0].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[0].getVaccins(), parsedFile.centra[0].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[0].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.centra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.centra[1].getAdres());
    EXPECT_EQ(parsedFile.centra[1].getInwoners(),7695755);
    EXPECT_EQ(parsedFile.centra[1].getCapaciteit(),20055);
    EXPECT_GE(parsedFile.centra[1].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[1].getVaccins(), parsedFile.centra[1].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[1].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.centra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.centra[2].getAdres());
    EXPECT_EQ(parsedFile.centra[2].getInwoners(),4905541);
    EXPECT_EQ(parsedFile.centra[2].getCapaciteit(),10050);
    EXPECT_GE(parsedFile.centra[2].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[2].getVaccins(), parsedFile.centra[2].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[2].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.centra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.centra[3].getAdres());
    EXPECT_EQ(parsedFile.centra[3].getInwoners(),257029);
    EXPECT_EQ(parsedFile.centra[3].getCapaciteit(),30000);
    EXPECT_GE(parsedFile.centra[3].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[3].getVaccins(), parsedFile.centra[3].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[3].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.hubVaccins, 200000); // aantal vaccins in hub >= 0

    EXPECT_EQ(parsedFile.centra[0].getVaccins(),64245); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), 5405755); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ(parsedFile.centra[1].getVaccins(),24245); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), 7695755); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ(parsedFile.centra[2].getVaccins(),14459); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), 4905541); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ(parsedFile.centra[3].getVaccins(),32971); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), 257029); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

}

TEST_F(InputTests, succesFile7) {

    string file = "../test-bestanden/succesFiles/succesFile7.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    EXPECT_EQ(parsedFile.leveringen, 98765);

    EXPECT_GE(parsedFile.hubVaccins, 0);

    EXPECT_EQ(parsedFile.interval, 5);

    EXPECT_EQ(parsedFile.transport, 555);

    EXPECT_EQ(parsedFile.centra.size(), (unsigned) 4);

    EXPECT_EQ("Park Spoor Oost", parsedFile.centra[0].getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", parsedFile.centra[0].getAdres());
    EXPECT_EQ(parsedFile.centra[0].getInwoners(),44444);
    EXPECT_EQ(parsedFile.centra[0].getCapaciteit(),1111);
    EXPECT_GE(parsedFile.centra[0].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[0].getVaccins(), parsedFile.centra[0].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[0].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ("AED Studios", parsedFile.centra[1].getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", parsedFile.centra[1].getAdres());
    EXPECT_EQ(parsedFile.centra[1].getInwoners(),66666);
    EXPECT_EQ(parsedFile.centra[1].getCapaciteit(),2222);
    EXPECT_GE(parsedFile.centra[1].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[1].getVaccins(), parsedFile.centra[1].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[1].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ("De Zoerla", parsedFile.centra[2].getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", parsedFile.centra[2].getAdres());
    EXPECT_EQ(parsedFile.centra[2].getInwoners(),999999);
    EXPECT_EQ(parsedFile.centra[2].getCapaciteit(),3333);
    EXPECT_GE(parsedFile.centra[2].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[2].getVaccins(), parsedFile.centra[2].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[2].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ("Flanders Expo", parsedFile.centra[3].getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", parsedFile.centra[3].getAdres());
    EXPECT_EQ(parsedFile.centra[3].getInwoners(),159615);
    EXPECT_EQ(parsedFile.centra[3].getCapaciteit(),555);
    EXPECT_GE(parsedFile.centra[3].getVaccins(),0);
    EXPECT_LE(parsedFile.centra[3].getVaccins(), parsedFile.centra[3].getCapaciteit()*2);
    EXPECT_GE( parsedFile.centra[3].getVaccinated(), 0);
    EXPECT_LE( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

    Transport transport(parsedFile);

    EXPECT_EQ(parsedFile.hubVaccins, 3757740); // aantal vaccins in hub >= 0

    EXPECT_EQ(parsedFile.centra[0].getVaccins(),1621); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), 44444); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[0].getVaccinated(), parsedFile.centra[0].getInwoners());

    EXPECT_EQ(parsedFile.centra[1].getVaccins(),2709); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), 66666); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[1].getVaccinated(), parsedFile.centra[1].getInwoners());

    EXPECT_EQ(parsedFile.centra[2].getVaccins(),3441); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), 999999); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[2].getVaccinated(), parsedFile.centra[2].getInwoners());

    EXPECT_EQ(parsedFile.centra[3].getVaccins(),780); // vaccins in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), 159615); // gevaccineerden in centrum >= 0
    EXPECT_EQ( parsedFile.centra[3].getVaccinated(), parsedFile.centra[3].getInwoners());

}
//
//TEST_F(InputTests, DefaultConstructor29) {
//
//    string file = "../test-bestanden/succesFiles/succesFile8.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor30) {
//
//    string file = "../test-bestanden/succesFiles/succesFile9.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor31) {
//
//    string file = "../test-bestanden/succesFiles/succesFile10.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor32) {
//
//    string file = "../test-bestanden/succesFiles/succesFile11.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor33) {
//
//    string file = "../test-bestanden/succesFiles/succesFile12.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor34) {
//
//    string file = "../test-bestanden/succesFiles/succesFile13.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor35) {
//
//    string file = "../test-bestanden/succesFiles/succesFile14.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor36) {
//
//    string file = "../test-bestanden/succesFiles/succesFile15.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor37) {
//
//    string file = "../test-bestanden/succesFiles/succesFile16.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor38) {
//
//    string file = "../test-bestanden/succesFiles/succesFile17.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor39) {
//
//    string file = "../test-bestanden/succesFiles/succesFile18.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor40) {
//
//    string file = "../test-bestanden/succesFiles/succesFile19.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor41) {
//
//    string file = "../test-bestanden/succesFiles/succesFile20.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
