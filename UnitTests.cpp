/*
 * korte beschrijving:
 * Deze klasse checkt voor elke klasse of de functies erin werken met zelfgemaakte locale input (per functie).
 * @author: Inte Vleminckx en Karnaukh Maksim
 * @date: 18/03/2021
 * @version: Specificatie 1.0
*/

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cmath>
#include "Vaccinatiecentrum.h"
#include "FileParser.h"
#include "Transport.h"

class UnitTests: public ::testing::Test {
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

};

TEST_F(UnitTests, Functie_isDigit){

    FileParser* newFile = new FileParser;
    newFile->_initCheck = newFile;
    string str = "geen digit";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = "geen_digit";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = "123";
    EXPECT_EQ(1, newFile->isDigit(str));
    str = "abc123";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = "!!!";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = ":)";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = "54646";
    EXPECT_EQ(1, newFile->isDigit(str));
    str = "54,646";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = "xD";
    EXPECT_EQ(0, newFile->isDigit(str));
    str = "10/10";
    EXPECT_EQ(0, newFile->isDigit(str));
}

TEST_F(UnitTests, Functie_isAlpha){

    FileParser* newFile = new FileParser;
    newFile->_initCheck = newFile;

    string str = "geendigit";
    EXPECT_EQ(1, newFile->isAlpha(str));
    str = "geen digit";
    EXPECT_EQ(1, newFile->isAlpha(str));
    str = "geen_digit";
    EXPECT_EQ(0, newFile->isAlpha(str));
    str = "123";
    EXPECT_EQ(0, newFile->isAlpha(str));
    str = "abc123";
    EXPECT_EQ(0, newFile->isAlpha(str));
    str = "!!!";
    EXPECT_EQ(0, newFile->isAlpha(str)); //
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, newFile->isAlpha(str));
    str = ":)";
    EXPECT_EQ(0, newFile->isAlpha(str));
    str = "54646";
    EXPECT_EQ(0, newFile->isAlpha(str));
    str = "54,646";
    EXPECT_EQ(0, newFile->isAlpha(str));
    str = "xD";
    EXPECT_EQ(1, newFile->isAlpha(str));
    str = "10/10";
    EXPECT_EQ(0, newFile->isAlpha(str));
}

TEST_F(UnitTests, Functie_isAlphaNum){

    FileParser* newFile = new FileParser;
    newFile->_initCheck = newFile;

    string str = "geendigit";
    EXPECT_EQ(1, newFile->isAlphaNum(str));
    str = "geen digit";
    EXPECT_EQ(1, newFile->isAlphaNum(str));
    str = "geen_digit";
    EXPECT_EQ(0, newFile->isAlphaNum(str)); //
    str = "123";
    EXPECT_EQ(1, newFile->isAlphaNum(str));
    str = "abc123";
    EXPECT_EQ(1, newFile->isAlphaNum(str));
    str = "!!!";
    EXPECT_EQ(0, newFile->isAlphaNum(str)); //
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, newFile->isAlphaNum(str));
    str = ":)";
    EXPECT_EQ(0, newFile->isAlphaNum(str));
    str = "54646";
    EXPECT_EQ(1, newFile->isAlphaNum(str));
    str = "54,646";
    EXPECT_EQ(1, newFile->isAlphaNum(str)); // toelaten want fAdres bestaat uit een komma ook
    str = "xD";
    EXPECT_EQ(1, newFile->isAlphaNum(str));
    str = "10/10";
    EXPECT_EQ(0, newFile->isAlphaNum(str));

    delete newFile;
}
//
//TEST_F(UnitTests, Functie_isTag){
//
//    FileParser* newFile = new FileParser;
//    newFile->_initCheck = newFile;
//
//    string str = "geendigit";
//    TiXmlElement* elem = new TiXmlElement("HUB");
//    elem->FirstChildElement()->Value() = "fLeveringen";
//
//
//    EXPECT_EQ(1, newFile->isTag(str, elem));
//
//    EXPECT_EQ(1, newFile->isTag(str, elem));
//    str = "geen_digit";
//    EXPECT_EQ(0, newFile->isTag(str, elem)); //
//    str = "123";
//    EXPECT_EQ(1, newFile->isTag(str, elem));
//    str = "abc123";
//    EXPECT_EQ(1, newFile->isTag(str, elem));
//
//    delete elem;
//    delete newFile;
//}

TEST_F(UnitTests, Functie_isLittleAlpha){

    FileParser* newFile = new FileParser;
    newFile->_initCheck = newFile;

    string str = "geendigit";
    EXPECT_EQ(1, newFile->isLittleAlpha(str));
    str = "geen digit";
    EXPECT_EQ(1, newFile->isLittleAlpha(str));
    str = "geen_digit";
    EXPECT_EQ(0, newFile->isLittleAlpha(str)); //
    str = "123";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));
    str = "abc123";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));
    str = "!!!";
    EXPECT_EQ(0, newFile->isLittleAlpha(str)); //
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));
    str = ":)";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));
    str = "54646";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));
    str = "Xylofoon";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));
    str = "xD";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));
    str = "CHECK";
    EXPECT_EQ(0, newFile->isLittleAlpha(str));

    delete newFile;
}


TEST_F(UnitTests, Functie_vaccinatieInCentrum){

    FileParser* newFile = new FileParser;
    newFile->_initCheck = newFile;

    Vaccinatiecentrum centrum;
    string centrumNaam = "Alfa";
    string adres = "Hertoginstraat 17, Antwerpen";
    int inwoners = 100000;
    int capaciteit = 10000;
    int vaccins = 5000; // fVaccinsInCentrum in het centrum
    int vaccinated = 20000; // aantal gevaccineerden

    centrum.setNaam(centrumNaam);
    centrum.setAdres(adres);
    centrum.setInwoners(inwoners);
    centrum.setCapaciteit(capaciteit);
    centrum.setVaccins(vaccins);
    centrum.setVaccinated(vaccinated);

    // getters en setters testen
    EXPECT_EQ("Alfa", centrum.getNaam());
    EXPECT_EQ("Hertoginstraat 17, Antwerpen", centrum.getAdres());
    EXPECT_EQ(100000, centrum.getInwoners());
    EXPECT_EQ(10000, centrum.getCapaciteit());
    EXPECT_EQ(5000, centrum.getVaccins());
    EXPECT_EQ(20000, centrum.getVaccinated());

    Transport transport(*newFile);
    transport.vaccinatieInCentrum(centrum);

    EXPECT_EQ(25000, centrum.getVaccinated());
    EXPECT_EQ(0, centrum.getVaccins());

    delete newFile;
}

