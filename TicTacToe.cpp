//============================================================================
// Name        : TicTacToe.cpp
// Author      : Serge Demeyer
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer - University of Antwerp
// Description : TicTactToe in C++, Ansi-style
//============================================================================

#include "TicTacToe.h"

TicTacToe::TicTacToe() {
	_nrOfMoves = 0;
}

bool TicTacToe::notDone() {
	return _nrOfMoves < 9;
}

void TicTacToe::doMove() {
	_nrOfMoves++;
}

int TicTacToe::nrOfMoves() {
	return _nrOfMoves;
}
