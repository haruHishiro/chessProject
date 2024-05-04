#pragma once

#include "figure.h"
#include "stepList.h"
#include "figuresList.h"


class deck {
public:
	deck(unsigned char difficulty);
	deck(unsigned char difficulty, unsigned char curentDeep);
	~deck();
	void setDificulty(unsigned char difficulty);

	//char** getDeck();
	//void setDeck(char** chessDeck); // must be [8][8]
	void doMove(step* move);

	int getPositionScore();

	void setupSteps();
	step* getBestStep();

	void setNotation(stepList notation);

private:
	void setupFlags();
	// variables for difficulty
	char difficulty;
	bool enableAlfaBeta;
	unsigned char alfaBeta_k; // how many steps into move we want to check with
	unsigned char deep;      // how many moves we want to analyze
	unsigned char curentDeep;

	char** curentChessDeck;    // main deck

	stepList notation;

	figuresList whiteFigures;
	char whiteFiguresNumber;
	figuresList blackFigures;
	char blackFiguresNumber;

	stepList allocatedSteps;
	unsigned short allocatedStepsNumber;

	bool isWhiteMove;

	bool isCheck;
	bool isEndGame;
	bool isDraw;

	deck** deckTree;

	void clearTreeStatement();
};
