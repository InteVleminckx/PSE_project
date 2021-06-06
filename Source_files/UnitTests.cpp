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
#include "../Header_files/Vaccinatiecentrum.h"
#include "../Header_files/FileParser.h"

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

    string str = "geen digit";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = "geen_digit";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = "123";
    EXPECT_EQ(1, Utils::isDigit(str));
    str = "abc123";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = "!!!";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = ":)";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = "54646";
    EXPECT_EQ(1, Utils::isDigit(str));
    str = "54,646";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = "xD";
    EXPECT_EQ(0, Utils::isDigit(str));
    str = "10/10";
    EXPECT_EQ(0, Utils::isDigit(str));
}

TEST_F(UnitTests, Functie_isAlpha){

    string str = "geendigit";
    EXPECT_EQ(1, Utils::isAlpha(str));
    str = "geen digit";
    EXPECT_EQ(1, Utils::isAlpha(str));
    str = "geen_digit";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = "123";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = "abc123";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = "!!!";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = ":)";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = "54646";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = "54,646";
    EXPECT_EQ(0, Utils::isAlpha(str));
    str = "xD";
    EXPECT_EQ(1, Utils::isAlpha(str));
    str = "10/10";
    EXPECT_EQ(0, Utils::isAlpha(str));
}

TEST_F(UnitTests, Functie_isAlphaNum){

    string str = "geendigit";
    EXPECT_EQ(1, Utils::isAlphaNum(str));
    str = "geen digit";
    EXPECT_EQ(1, Utils::isAlphaNum(str));
    str = "geen_digit";
    EXPECT_EQ(0, Utils::isAlphaNum(str));
    str = "123";
    EXPECT_EQ(1, Utils::isAlphaNum(str));
    str = "abc123";
    EXPECT_EQ(1, Utils::isAlphaNum(str));
    str = "!!!";
    EXPECT_EQ(0, Utils::isAlphaNum(str));
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, Utils::isAlphaNum(str));
    str = ":)";
    EXPECT_EQ(0, Utils::isAlphaNum(str));
    str = "54646";
    EXPECT_EQ(1, Utils::isAlphaNum(str));
    str = "54,646";
    EXPECT_EQ(1, Utils::isAlphaNum(str)); // toelaten want fAdres bestaat uit een komma ook
    str = "xD";
    EXPECT_EQ(1, Utils::isAlphaNum(str));
    str = "10/10";
    EXPECT_EQ(0, Utils::isAlphaNum(str));

}

TEST_F(UnitTests, Functie_isLittleAlpha){


    string str = "geendigit";
    EXPECT_EQ(1, Utils::isLittleAlpha(str));
    str = "geen digit";
    EXPECT_EQ(1, Utils::isLittleAlpha(str));
    str = "geen_digit";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "123";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "abc123";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "!!!";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "_-_-_-_-_-_-_-_";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = ":)";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "54646";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "Xylofoon";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "xD";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));
    str = "CHECK";
    EXPECT_EQ(0, Utils::isLittleAlpha(str));

}