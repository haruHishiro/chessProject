#pragma once

#include "figure.h"


class deck {
public:
	deck();
	~deck();
	void setDificulty();

	char** getDeck();
	void setDeck(char** chessDeck); // must be [8][8]
	void doMove(step move);

	void setupSteps();
	void setStepScore(step step);



private:
	// variables for difficulty
	bool enableAlfaBeta;
	unsigned char alfaBeta_k;
	unsigned char deep;

	char chessDeckCurent[8][8];    // main deck
	char chessDeckIterable[8][8]; // for moves scoring
	figure* whiteFigures;
	figure* blackFigures;

	step* allocatedSteps;

	bool isWhiteMove;

	bool isCheck;
	bool isEndGame;
	bool isDraw;
};
