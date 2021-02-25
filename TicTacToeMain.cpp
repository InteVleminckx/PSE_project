//============================================================================
// Name        : TicTacToeMain.cpp
// Author      : Serge Demeyer
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer - University of Antwerp
// Description : TicTactToe in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main(int argc, char **argv) {
	TicTacToe ttt;

	cout << "START: ttt.nrOfMoves() = " << ttt.nrOfMoves() << endl;
	while (ttt.notDone()) {
		ttt.doMove();
	};
	cout << "END: ttt.nrOfMoves() = " << ttt.nrOfMoves() << endl;
}
