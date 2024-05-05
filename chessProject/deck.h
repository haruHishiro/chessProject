#pragma once

#include "figure.h"
#include "stepList.h"
#include "figuresList.h"


class deck {
public:
	deck(unsigned char difficulty);
	deck(unsigned char curentDeep, unsigned char maxDeep);
	~deck();
	void setDificulty(unsigned char difficulty);

	//char** getDeck();
	//void setDeck(char** chessDeck); // must be [8][8]
	void doMove(step* move);

	int getPositionScore();

	void setupFiguresSteps();
	int analyze();

	void setIsWhiteMove(bool isWhiteMove);
	void setupPositionScore();
	void setNotation(stepList notation);
	step* getLastMove();

	void setPosition(char** chessDeck);
	void setFigures(figuresList whiteFigures, figuresList blackFigures);

	void setupEndGameFlags();

private:
	void setupFlags();
	// variables for difficulty
	char difficulty;
	unsigned char maxDeep;      // how many moves we want to analyze
	unsigned char curentDeep;

	char** curentChessDeck;    // main deck
	int positionScore;
	int treePositionScore;

	stepList notation;
	step* bestStep;

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
	bool botSideIsWhite;
};
