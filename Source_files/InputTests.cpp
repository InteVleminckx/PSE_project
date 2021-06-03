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
#include "../Header_files/SimulatieUtils.h"
#include "../Header_files/Distributie.h"

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

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile1.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile1Test");

    test << "Error reading Attributes.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile1Test"));

}

TEST_F(InputTests, failedFile2) {
    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile2.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile2Test");

    test << "Geen correcte input voor de tag.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile2Test"));
}

TEST_F(InputTests, failedFile3) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile3.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile3Test");

    test << "Er moet minstens 1 vaccinatiecentrum zijn.\n" <<
            "Het aantal vaccinatiecentra komt niet overeen met het aantal opgegeven centra in het begin.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile3Test"));

}

TEST_F(InputTests, failedFile4) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile4.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile4Test");

    test << "Tag \"capaciteit\" niet gevonden.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile4Test"));

}

TEST_F(InputTests, failedFile5) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile5.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile5Test");

    test << "Tag \"naam\" niet gevonden.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile5Test"));

}

TEST_F(InputTests, failedFile6) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile6.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile6Test");

    test << "Tag \"adres\" niet gevonden.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile6Test"));

}

TEST_F(InputTests, failedFile7) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile7.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile7Test");

    test << "Tag \"inwoners\" niet gevonden.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile7Test"));

}

TEST_F(InputTests, failedFile8) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile8.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile8Test");

    test << "Het aantal vaccinatiecentra komt niet overeen met het aantal opgegeven centra in het begin.\n" <<
            "Het aantal vaccinatiecentra komt niet overeen met het aantal opgegeven centra in het begin.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile8Test"));

}

TEST_F(InputTests, failedFile9) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile9.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile9Test");

    test << "Tag \"levering\" niet gevonden.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile9Test"));
}

TEST_F(InputTests, failedFile10) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile10.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile10Test");

    test << "Tag \"interval\" niet gevonden.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile10Test"));
}

TEST_F(InputTests, failedFile11) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile11.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile11Test");

    test << "Tag \"type\" niet gevonden.\n" <<
            "Tag \"transport\" niet gevonden.\n" <<
            "Tag \"transport\" niet gevonden.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile11Test"));
}

TEST_F(InputTests, failedFile12) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile12.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile12Test");

    test << "Levering moet een positieve integer zijn.\n" <<
            "Hernieuwing moet een positieve integer zijn.\n" <<
            "Temperatuur moet een positieve of negatief integer zijn.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile12Test"));
}

TEST_F(InputTests, failedFile13) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile13.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile13Test");

    test << "Error reading end tag.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile13Test"));
}

TEST_F(InputTests, failedFile14) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile14.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile14Test");

    test << "Transport moet een positieve integer zijn.\n" <<
            "Transport moet een positieve integer zijn.\n" <<
            "Naam van een centrum moet een string zijn.\n" <<
            "Capaciteit moet een positieve integer zijn.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile14Test"));
}

TEST_F(InputTests, failedFile15) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile15.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile15Test");

    test << "Naam van een centrum moet een string zijn.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile15Test"));
}

TEST_F(InputTests, failedFile16) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile16.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile16Test");

    test << "Naam van een centrum moet een string zijn.\n" <<
            "Inwoners moet een positieve integer zijn.\n" <<
            "Het aantal vaccinatiecentra komt niet overeen met het aantal opgegeven centra in het begin.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile16Test"));
}

TEST_F(InputTests, failedFile17) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile17.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile17Test");

    test << "Interval moet een positieve integer zijn.\n" <<
            "Capaciteit moet een positieve integer zijn.\n" <<
            "Capaciteit moet een positieve integer zijn.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile17Test"));
}

TEST_F(InputTests, failedFile18) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile18.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile18Test");

    test << "Adres moet bestaan uit een string (en integers).\n" <<
            "Het aantal vaccinatiecentra komt niet overeen met het aantal opgegeven centra in het begin.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile18Test"));
}

TEST_F(InputTests, failedFile19) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile19.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile19Test");

    test << "Childtags moeten in kleine letters.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile19Test"));
}

TEST_F(InputTests, failedFile20) {

    ASSERT_TRUE(DirectoryExists("../test-bestanden"));
    ASSERT_TRUE(DirectoryExists("../test-bestanden/failFiles"));

    string file = "../test-bestanden/failFiles/failedFile20.xml";
    parsedFile.parseFile(file);
    ofstream test;
    test.open("../test-bestanden/failFiles/failedFile20Test");

    test << "Tag \"naam\" niet gevonden.\n" <<
            "Childtags moeten in kleine letters.\n";

    test.close();

    EXPECT_TRUE(FileCompare("../test-bestanden/testOutput.txt", "../test-bestanden/failFiles/failedFile20Test"));
}

TEST_F(InputTests, succesFile1) {

    string file = "../test-bestanden/succesFiles/succesFile1.xml";
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

TEST_F(InputTests, succesFile2) {
    string file = "../test-bestanden/succesFiles/succesFile2.xml";
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
    EXPECT_GE(vaccin->getLeveringen(), 50000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 3000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 10);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 60000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 30000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 25);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(500000, vaccinatiecentrum->getInwoners());
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
    EXPECT_EQ(120000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(300000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5000, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(500000, vaccinatiecentrum->getInwoners());
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
    EXPECT_EQ(120000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(300000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5000, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 6149500);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 3804000);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 5911500);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 1500);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 1000);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 49);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 500);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(500000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(353500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(33000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(300000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(126000, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 11674549);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 3030000);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 13386500);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 1500);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 549);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 1500);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(500000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(500000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(49451, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(300000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(277500, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(InputTests, succesFile3) {
    string file = "../test-bestanden/succesFiles/succesFile3.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    //string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;
    mapVaccins["Moderna"] = 0;
    //mapVaccins["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 150000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 25);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 20000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);


    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(1000000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(25000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(90500, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(150600, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(6000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(6500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 93000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 5);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 46000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(1000000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(25000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(90500, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(150600, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(6000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(257029, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(6500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);

    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 8541871);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 1120000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 2000);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 500);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 1400);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 1971);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(1000000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(740000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(90500, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(34500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(150600, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(104600, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(195029, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 11218871);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 2852000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 1500);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 1400);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 971);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(1000000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(698000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(90500, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(48500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(150600, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(98600, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(257029, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(193029, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(InputTests, succesFile4) {

    string file = "../test-bestanden/succesFiles/succesFile4.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";

    map<string, int> mapVaccins;
    mapVaccins["Pfizer"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 20000);
    EXPECT_EQ(vaccin->getInterval(), 5);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -5);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(450000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(6000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));


    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(95600, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3900, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));


    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(56000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2300, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));


    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(240000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccins, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 53900);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 1500);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 400);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 1000);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(450000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(450000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(95600, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(95600, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(56000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(56000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(240000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(240000, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(InputTests, succesFile5) {

    string file = "../test-bestanden/succesFiles/succesFile5.xml";
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
    EXPECT_GE(vaccin->getLeveringen(), 20000);
    EXPECT_EQ(vaccin->getInterval(), 7);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 80000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), 5);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 67000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 6);
    EXPECT_EQ(vaccin->getTemperatuur(), -100);

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

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);

    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 2154000);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 4939049);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 13076000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 827);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 65);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 49);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 971);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 1000);
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
    EXPECT_EQ(242029, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(InputTests, succesFile6){

    string file = "../test-bestanden/succesFiles/succesFile6.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccinsHub1;
    mapVaccinsHub1["Pfizer"] = 0;
    mapVaccinsHub1["Moderna"] = 0;

    map<string, int> mapVaccinsHub2;
    mapVaccinsHub2["Pfizer"] = 0;
    mapVaccinsHub2["AstraZeneca"] = 0;

    map<string, int> mapVaccinsHub3;
    mapVaccinsHub3["AstraZeneca"] = 0;
    mapVaccinsHub3["Moderna"] = 0;

    map<string, int> mapVaccinsHub4;
    mapVaccinsHub4["Pfizer"] = 0;
    mapVaccinsHub4["Moderna"] = 0;
    mapVaccinsHub4["AstraZeneca"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 40000);
    EXPECT_EQ(vaccin->getInterval(), 8);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 20000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);


    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(700000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(120000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(70500, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(390000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 35000);
    EXPECT_EQ(vaccin->getInterval(), 6);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), 10);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 26000);
    EXPECT_EQ(vaccin->getInterval(), 5);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(700000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(120000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(70500, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(390000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    Hub* hub2 = parsedFile.fHubs[2];

    //vaccin1
    vaccin = hub2->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 28500);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -20);

    //vaccin2
    vaccin = hub2->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 45000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -20);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub2->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(700000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub3, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub2->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(120000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub3, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub2->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(70500, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub3, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub2->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(390000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub3, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    Hub* hub3 = parsedFile.fHubs[3];

    //vaccin1
    vaccin = hub3->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 15000);
    EXPECT_EQ(vaccin->getInterval(), 3);
    EXPECT_EQ(vaccin->getTransport(), 500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -80);

    //vaccin2
    vaccin = hub3->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 20000);
    EXPECT_EQ(vaccin->getInterval(), 5);
    EXPECT_EQ(vaccin->getTransport(), 850);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub3->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 12000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 450);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub3->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(700000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(7500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub4, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub3->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(120000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(2000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub4, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub3->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(70500, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub4, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub3->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(390000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(3000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub4, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub2->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub3->fHubCentra.size(), (unsigned) 4);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 2858000);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 869500);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 1000);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 500);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 1000);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(700000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(501000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(80000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(70500, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(70500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(390000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(258000, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 3805500);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 3596500);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 1500);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 500);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 1500);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(700000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(253000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(79500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(70500, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(70500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(390000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(258000, vaccinatiecentrum->getVaccinatedSecondTime());

    //hub2

    //hub vaccins
    EXPECT_EQ(hub2->fVaccins[0]->getAantalVaccins(), 1489500);
    EXPECT_EQ(hub2->fVaccins[1]->getAantalVaccins(), 7762000);


    // centra's
    EXPECT_EQ(hub2->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub2->fHubCentra[0]->getVaccins(AstraZeneca), 1000);

    EXPECT_EQ(hub2->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub2->fHubCentra[1]->getVaccins(AstraZeneca), 1000);

    EXPECT_EQ(hub2->fHubCentra[2]->getVaccins(Moderna), 500);
    EXPECT_EQ(hub2->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub2->fHubCentra[3]->getVaccins(Moderna), 1000);
    EXPECT_EQ(hub2->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub2->fHubCentra[0];

    EXPECT_EQ(700000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(236000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub2->fHubCentra[1];
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(63000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub2->fHubCentra[2];
    EXPECT_EQ(70500, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(70500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub2->fHubCentra[3];
    EXPECT_EQ(390000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(147000, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub3

    //hub vaccins
    EXPECT_EQ(hub3->fVaccins[0]->getAantalVaccins(), 2853750);
    EXPECT_EQ(hub3->fVaccins[1]->getAantalVaccins(), 2778150);
    EXPECT_EQ(hub3->fVaccins[2]->getAantalVaccins(), 2053050);

    // centra's
    EXPECT_EQ(hub3->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub3->fHubCentra[0]->getVaccins(Moderna), 450);
    EXPECT_EQ(hub3->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub3->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub3->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub3->fHubCentra[1]->getVaccins(AstraZeneca), 450);

    EXPECT_EQ(hub3->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub3->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub3->fHubCentra[2]->getVaccins(AstraZeneca), 300);

    EXPECT_EQ(hub3->fHubCentra[3]->getVaccins(Pfizer), 250);
    EXPECT_EQ(hub3->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub3->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub3->fHubCentra[0];

    EXPECT_EQ(700000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(237050, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub3->fHubCentra[1];
    EXPECT_EQ(120000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(58600, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub3->fHubCentra[2];
    EXPECT_EQ(70500, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(29500, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub3->fHubCentra[3];
    EXPECT_EQ(390000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(197950, vaccinatiecentrum->getVaccinatedSecondTime());
}

TEST_F(InputTests, succesFile7) {

        string file = "../test-bestanden/succesFiles/succesFile7.xml";
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
        EXPECT_GE(vaccin->getLeveringen(), 9500);
        EXPECT_EQ(vaccin->getInterval(), 1);
        EXPECT_EQ(vaccin->getTransport(), 500);
        EXPECT_EQ(vaccin->getHernieuwingen(), 15);
        EXPECT_EQ(vaccin->getTemperatuur(), -70);

        //vaccin2
        vaccin = hub0->fVaccins[1];
        EXPECT_EQ(vaccin->getType(), "Moderna");
        EXPECT_GE(vaccin->getLeveringen(), 93000);
        EXPECT_EQ(vaccin->getInterval(), 13);
        EXPECT_EQ(vaccin->getTransport(), 5000);
        EXPECT_EQ(vaccin->getHernieuwingen(), 19);
        EXPECT_EQ(vaccin->getTemperatuur(), 15);

        //vaccin3
        vaccin = hub0->fVaccins[2];
        EXPECT_EQ(vaccin->getType(), "AstraZeneca");
        EXPECT_GE(vaccin->getLeveringen(), 95175);
        EXPECT_EQ(vaccin->getInterval(), 10);
        EXPECT_EQ(vaccin->getTransport(), 10000);
        EXPECT_EQ(vaccin->getHernieuwingen(), 19);
        EXPECT_EQ(vaccin->getTemperatuur(), -70);

        //vaccinatiecentrum1
        Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

        EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
        EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
        EXPECT_EQ(946784, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(2400, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_EQ(1915945, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(5100, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_EQ(87000, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(7000, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_EQ(976431, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(5400, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_GE(vaccin->getLeveringen(), 94678);
        EXPECT_EQ(vaccin->getInterval(), 6);
        EXPECT_EQ(vaccin->getTransport(), 5400);
        EXPECT_EQ(vaccin->getHernieuwingen(), 15);
        EXPECT_EQ(vaccin->getTemperatuur(), -70);

        //vaccin2
        vaccin = hub1->fVaccins[1];
        EXPECT_EQ(vaccin->getType(), "Moderna");
        EXPECT_GE(vaccin->getLeveringen(), 76214);
        EXPECT_EQ(vaccin->getInterval(), 13);
        EXPECT_EQ(vaccin->getTransport(), 8461);
        EXPECT_EQ(vaccin->getHernieuwingen(), 19);
        EXPECT_EQ(vaccin->getTemperatuur(), -70);

        //vaccin3
        vaccin = hub1->fVaccins[2];
        EXPECT_EQ(vaccin->getType(), "AstraZeneca");
        EXPECT_GE(vaccin->getLeveringen(), 1000);
        EXPECT_EQ(vaccin->getInterval(), 4);
        EXPECT_EQ(vaccin->getTransport(), 200);
        EXPECT_EQ(vaccin->getHernieuwingen(), 21);
        EXPECT_EQ(vaccin->getTemperatuur(), -70);

        //vaccinatiecentrum1
        vaccinatiecentrum = hub1->fHubCentra[0];

        EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
        EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
        EXPECT_EQ(946784, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(2400, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_EQ(1915945, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(5100, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_EQ(87000, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(7000, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_EQ(976431, vaccinatiecentrum->getInwoners());
        EXPECT_EQ(5400, vaccinatiecentrum->getCapaciteit());
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
        EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 738000);
        EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 4610055);
        EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 8660925);

        // centra's
        EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 0);
        EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
        EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

        EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 0);
        EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 2555);
        EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

        EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
        EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 2500);
        EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

        EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
        EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 5069);
        EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

        //vaccinatiecentrum1
        vaccinatiecentrum = hub0->fHubCentra[0];

        EXPECT_EQ(887000, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(871000, vaccinatiecentrum->getVaccinatedSecondTime());

        //vaccinatiecentrum2
        vaccinatiecentrum = hub0->fHubCentra[1];
        EXPECT_EQ(1915945, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(998245, vaccinatiecentrum->getVaccinatedSecondTime());

        //vaccinatiecentrum3
        vaccinatiecentrum = hub0->fHubCentra[2];
        EXPECT_EQ(87000, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(47500, vaccinatiecentrum->getVaccinatedSecondTime());

        //vaccinatiecentrum4
        vaccinatiecentrum = hub0->fHubCentra[3];
        EXPECT_EQ(976431, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(304700, vaccinatiecentrum->getVaccinatedSecondTime());


        //hub1
        //hub vaccins
        EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 11406323);
        EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 5487408);
        EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 0);

        // centra's
        EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 0);
        EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
        EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

        EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 0);
        EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
        EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

        EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 4800);
        EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 0);
        EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 0);

        EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 969);
        EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 0);
        EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

        //vaccinatiecentrum1
        vaccinatiecentrum = hub1->fHubCentra[0];

        EXPECT_EQ(96000, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(96000, vaccinatiecentrum->getVaccinatedSecondTime());

        //vaccinatiecentrum2
        vaccinatiecentrum = hub1->fHubCentra[1];
        EXPECT_EQ(4000, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(4000, vaccinatiecentrum->getVaccinatedSecondTime());

        //vaccinatiecentrum3
        vaccinatiecentrum = hub1->fHubCentra[2];
        EXPECT_EQ(87000, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(87000, vaccinatiecentrum->getVaccinatedSecondTime());

        //vaccinatiecentrum4
        vaccinatiecentrum = hub1->fHubCentra[3];
        EXPECT_EQ(976431, vaccinatiecentrum->getVaccinatedFirstTime());
        EXPECT_EQ(976431, vaccinatiecentrum->getVaccinatedSecondTime());
}

TEST_F(InputTests, succesFile8) {

    string file = "../test-bestanden/succesFiles/succesFile8.xml";
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
    EXPECT_GE(vaccin->getLeveringen(), 25000);
    EXPECT_EQ(vaccin->getInterval(), 10);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 25000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 10000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(645132, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(8500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(731640, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(10101, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(54643, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(672459, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(4500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_GE(vaccin->getLeveringen(), 25000);
    EXPECT_EQ(vaccin->getInterval(), 10);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 15);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 25000);
    EXPECT_EQ(vaccin->getInterval(), 13);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 10000);
    EXPECT_EQ(vaccin->getInterval(), 4);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(645132, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(8500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(731640, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(10101, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(54643, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(1500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(672459, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(4500, vaccinatiecentrum->getCapaciteit());
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
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 893901);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 989000);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 1280000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 1368);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 1360);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 857);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 1541);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(645132, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(491132, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(731640, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(519640, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(54643, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(54643, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(672459, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(455459, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 893901);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 989000);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 1280000);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 1368);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 1360);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 857);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 1541);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(AstraZeneca), 0);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(645132, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(491132, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(731640, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(519640, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(54643, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(54643, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(672459, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(455459, vaccinatiecentrum->getVaccinatedSecondTime());
}

TEST_F(InputTests, succesFile9) {

    string file = "../test-bestanden/succesFiles/succesFile9.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccinsHub1;
    map<string, int> mapVaccinsHub2;
    mapVaccinsHub1["Pfizer"] = 0;

    mapVaccinsHub2["Pfizer"] = 0;
    mapVaccinsHub2["Moderna"] = 0;
    mapVaccinsHub2["AstraZeneca"] = 0;

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 158000);
    EXPECT_EQ(vaccin->getInterval(), 7);
    EXPECT_EQ(vaccin->getTransport(), 4500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 10);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);


    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(987654, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(12500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(75270, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(4500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(69420, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 42500);
    EXPECT_EQ(vaccin->getInterval(), 5);
    EXPECT_EQ(vaccin->getTransport(), 1500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 10);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 15000);
    EXPECT_EQ(vaccin->getInterval(), 10);
    EXPECT_EQ(vaccin->getTransport(), 1700);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin3
    vaccin = hub1->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 100000);
    EXPECT_EQ(vaccin->getInterval(), 10);
    EXPECT_EQ(vaccin->getTransport(), 1000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 21);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(987654, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(12500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(75270, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(4500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(69420, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 3);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 3);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 17479156);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 2346);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 1230);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 2580);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(987654, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(987654, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(75270, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(75270, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(69420, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(69420, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 5960730);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 1169500);
    EXPECT_EQ(hub1->fVaccins[2]->getAantalVaccins(), 8679580);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 1646);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 230);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(AstraZeneca), 580);


    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(987654, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(543300, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(75270, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(30170, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(69420, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(44420, vaccinatiecentrum->getVaccinatedSecondTime());

}

TEST_F(InputTests, succesFile10) {

    string file = "../test-bestanden/succesFiles/succesFile10.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

    string Pfizer = "Pfizer";
    string Moderna = "Moderna";
    string AstraZeneca = "AstraZeneca";
    map<string, int> mapVaccinsHub1;
    mapVaccinsHub1["Pfizer"] = 0;
    mapVaccinsHub1["Moderna"] = 0;
    mapVaccinsHub1["AstraZeneca"] = 0;

    map<string, int> mapVaccinsHub2;
    mapVaccinsHub2["Pfizer"] = 0;
    mapVaccinsHub2["Moderna"] = 0;

    //voor simulatie

    //hub0
    Hub* hub0 = parsedFile.fHubs[0];

    //vaccin1
    Vaccin* vaccin = hub0->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 65400);
    EXPECT_EQ(vaccin->getInterval(), 5);
    EXPECT_EQ(vaccin->getTransport(), 500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 10);
    EXPECT_EQ(vaccin->getTemperatuur(), -54);

    //vaccin2
    vaccin = hub0->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 42210);
    EXPECT_EQ(vaccin->getInterval(), 10);
    EXPECT_EQ(vaccin->getTransport(),1200);
    EXPECT_EQ(vaccin->getHernieuwingen(), 14);
    EXPECT_EQ(vaccin->getTemperatuur(), 0);

    //vaccin3
    vaccin = hub0->fVaccins[2];
    EXPECT_EQ(vaccin->getType(), "AstraZeneca");
    EXPECT_GE(vaccin->getLeveringen(), 45000);
    EXPECT_EQ(vaccin->getInterval(), 5);
    EXPECT_EQ(vaccin->getTransport(), 2000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 0);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccinatiecentrum1
    Vaccinatiecentrum* vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(456456, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(10000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(75000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(14750, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(158000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(8000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub1, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));


    Hub* hub1 = parsedFile.fHubs[1];

    //vaccin1
    vaccin = hub1->fVaccins[0];
    EXPECT_EQ(vaccin->getType(), "Pfizer");
    EXPECT_GE(vaccin->getLeveringen(), 150000);
    EXPECT_EQ(vaccin->getInterval(), 15);
    EXPECT_EQ(vaccin->getTransport(), 12000);
    EXPECT_EQ(vaccin->getHernieuwingen(), 10);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);

    //vaccin2
    vaccin = hub1->fVaccins[1];
    EXPECT_EQ(vaccin->getType(), "Moderna");
    EXPECT_GE(vaccin->getLeveringen(), 75100);
    EXPECT_EQ(vaccin->getInterval(), 12);
    EXPECT_EQ(vaccin->getTransport(), 500);
    EXPECT_EQ(vaccin->getHernieuwingen(), 19);
    EXPECT_EQ(vaccin->getTemperatuur(), -70);


    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ("Park Spoor Oost", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Noordersingel 40, Antwerpen", vaccinatiecentrum->getAdres());
    EXPECT_EQ(456456, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(10000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];

    EXPECT_EQ("AED Studios", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Fabriekstraat 38, Lint", vaccinatiecentrum->getAdres());
    EXPECT_EQ(75000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(5000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];

    EXPECT_EQ("De Zoerla", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Gevaertlaan 1, Westerlo", vaccinatiecentrum->getAdres());
    EXPECT_EQ(14750, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(500, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];

    EXPECT_EQ("Flanders Expo", vaccinatiecentrum->getNaam());
    EXPECT_EQ("Maaltekouter 1, Sint-Denijs-Westrem", vaccinatiecentrum->getAdres());
    EXPECT_EQ(158000, vaccinatiecentrum->getInwoners());
    EXPECT_EQ(8000, vaccinatiecentrum->getCapaciteit());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccinatedSecondTime());
    EXPECT_EQ(mapVaccinsHub2, vaccinatiecentrum->getVaccinsInCentrum());
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Pfizer));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(Moderna));
    EXPECT_EQ(0, vaccinatiecentrum->getVaccins(AstraZeneca));

    EXPECT_EQ(hub0->fHubCentra.size(), (unsigned) 4);
    EXPECT_EQ(hub1->fHubCentra.size(), (unsigned) 4);


    //na simulatie
    Distributie distributie(parsedFile);

    //hub0

    //hub vaccins
    EXPECT_EQ(hub0->fVaccins[0]->getAantalVaccins(), 10103994);
    EXPECT_EQ(hub0->fVaccins[1]->getAantalVaccins(), 3631110);
    EXPECT_EQ(hub0->fVaccins[2]->getAantalVaccins(), 7401000);

    // centra's
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Pfizer), 444);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[0]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Pfizer), 300);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[1]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Pfizer), 250);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[2]->getVaccins(AstraZeneca), 0);

    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(Moderna), 0);
    EXPECT_EQ(hub0->fHubCentra[3]->getVaccins(AstraZeneca), 300);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub0->fHubCentra[0];

    EXPECT_EQ(456456, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(357256, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub0->fHubCentra[1];
    EXPECT_EQ(75000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(65200, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub0->fHubCentra[2];
    EXPECT_EQ(14750, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(14750, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub0->fHubCentra[3];
    EXPECT_EQ(158000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(112800, vaccinatiecentrum->getVaccinatedSecondTime());


    //hub1
    //hub vaccins
    EXPECT_EQ(hub1->fVaccins[0]->getAantalVaccins(), 9450000);
    EXPECT_EQ(hub1->fVaccins[1]->getAantalVaccins(), 4372994);

    // centra's
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[0]->getVaccins(Moderna), 44);

    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[1]->getVaccins(Moderna), 500);

    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[2]->getVaccins(Moderna), 250);

    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Pfizer), 0);
    EXPECT_EQ(hub1->fHubCentra[3]->getVaccins(Moderna), 500);

    //vaccinatiecentrum1
    vaccinatiecentrum = hub1->fHubCentra[0];

    EXPECT_EQ(456456, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(456456, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum2
    vaccinatiecentrum = hub1->fHubCentra[1];
    EXPECT_EQ(75000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(75000, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum3
    vaccinatiecentrum = hub1->fHubCentra[2];
    EXPECT_EQ(14750, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(14750, vaccinatiecentrum->getVaccinatedSecondTime());

    //vaccinatiecentrum4
    vaccinatiecentrum = hub1->fHubCentra[3];
    EXPECT_EQ(158000, vaccinatiecentrum->getVaccinatedFirstTime());
    EXPECT_EQ(158000, vaccinatiecentrum->getVaccinatedSecondTime());
}
