//============================================================================
// Name        : TicTacToeTests.cpp
// Author      : Serge Demeyer
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer - University of Antwerp
// Description : TicTactToe in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include "Largest.cpp"
#include "TicTacToe.h"

class TicTactToeTest: public ::testing::Test {
protected:
	// You should make the members protected s.t. they can be
	// accessed from sub-classes.

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
//	TicTacToe ttt_;
};

//// Tests the default constructor.
//TEST_F(TicTactToeTest, DefaultConstructor) {
//	EXPECT_EQ(0, ttt_.nrOfMoves());
//	EXPECT_TRUE(ttt_.notDone());
//}
//
//// Tests the "happy day" scenario
//TEST_F(TicTactToeTest, HappyDay) {
//	EXPECT_EQ(0, ttt_.nrOfMoves());
//	EXPECT_TRUE(ttt_.notDone());
//	while (ttt_.notDone()) {
//		ttt_.doMove();
//	};
//	EXPECT_FALSE(ttt_.notDone());
//	EXPECT_EQ(9, ttt_.nrOfMoves());
//}

TEST(LargestValue, EquelTo){

    vector<int>* vect = new vector<int>{ 10, 20, 30, 100 };
    EXPECT_EQ(100, largest2(vect));
}

TEST(LargestValue, LowerThenLargestInVector){

    vector<int>* vect = new vector<int>{ 10, 20, 30, 100 };
    EXPECT_LT(99, largest2(vect));
}

TEST(LargestValue, LowerNegativeThenLargestInVector){

    vector<int>* vect = new vector<int>{ 10, 20, 30, 100 };
    EXPECT_LT(-99, largest2(vect));
}

TEST(LargestValue, HigherThenLargestInVector){

    vector<int>* vect = new vector<int>{ 10, 20, 30, 100 };
    EXPECT_GT(101, largest2(vect));
}

TEST(LargestValue, HigherNagativeThenLargestInVector){

    vector<int>* vect = new vector<int>{ -10, -20, -30, -100 };
    EXPECT_GT(101, largest2(vect));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
