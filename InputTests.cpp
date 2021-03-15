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

TEST_F(InputTests, DefaultConstructor1) {

    string file = "../test-bestanden/failFiles/failedFile1.xml";
    EXPECT_TRUE(parsedFile.parseFile(file));

//    try {
//        parsedFile.parseFile(file);
//        fail(); // did not throw
//    } catch (bool e) {
//        cout << "Fout" << endl;
//    }

}

TEST_F(InputTests, DefaultConstructor2) {
    string file = "../test-bestanden/failFiles/failedFile2.xml";
    EXPECT_TRUE( parsedFile.parseFile(file));
}

TEST_F(InputTests, DefaultConstructor3) {

    string file = "../test-bestanden/failFiles/failedFile3.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor4) {

    string file = "../test-bestanden/failFiles/failedFile4.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor5) {

    string file = "../test-bestanden/failFiles/failedFile5.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor6) {

    string file = "../test-bestanden/failFiles/failedFile6.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor7) {

    string file = "../test-bestanden/failFiles/failedFile7.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor8) {

    string file = "../test-bestanden/failFiles/failedFile8.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor9) {

    string file = "../test-bestanden/failFiles/failedFile9.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor10) {

    string file = "../test-bestanden/failFiles/failedFile10.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor11) {

    string file = "../test-bestanden/failFiles/failedFile11.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor12) {

    string file = "../test-bestanden/failFiles/failedFile12.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor13) {

    string file = "../test-bestanden/failFiles/failedFile13.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor14) {

    string file = "../test-bestanden/failFiles/failedFile14.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor15) {

    string file = "../test-bestanden/failFiles/failedFile15.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor16) {

    string file = "../test-bestanden/failFiles/failedFile16.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor17) {

    string file = "../test-bestanden/failFiles/failedFile17.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor18) {

    string file = "../test-bestanden/failFiles/failedFile18.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor19) {

    string file = "../test-bestanden/failFiles/failedFile19.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor20) {

    string file = "../test-bestanden/failFiles/failedFile20.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor21) {

    string file = "../test-bestanden/failFiles/failedFile21.xml";
    EXPECT_EQ(1, parsedFile.parseFile(file));

}

TEST_F(InputTests, DefaultConstructor22) {

    string file = "../test-bestanden/succesFiles/succesFile1.xml";
    EXPECT_EQ(0, parsedFile.parseFile(file));

//    parsedFile.parseFile(file);
//    Transport transport(parsedFile);

}
//
//TEST_F(InputTests, DefaultConstructor23) {
//
//    string file = "../test-bestanden/succesFiles/succesFile2.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor24) {
//
//    string file = "../test-bestanden/succesFiles/succesFile3.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor25) {
//
//    string file = "../test-bestanden/succesFiles/succesFile4.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor26) {
//
//    string file = "../test-bestanden/succesFiles/succesFile5.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor27) {
//
//    string file = "../test-bestanden/succesFiles/succesFile6.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
//
//TEST_F(InputTests, DefaultConstructor28) {
//
//    string file = "../test-bestanden/succesFiles/succesFile7.xml";
//    EXPECT_EQ(0, parsedFile.parseFile(file));
//
//}
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
