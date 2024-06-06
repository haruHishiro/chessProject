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
	void setupStartPosition();

	void doMove(step* move);
	bool isCorrectMove(step* move);

	int getPositionScore();

	void setupFiguresSteps();
	void allocFiguresSteps();
	int analyze();

	void setIsWhiteMove(bool isWhiteMove);
	void setupPositionScore();
	void setPositionScore(int positionScore);
	void setNotation(stepList* notation);
	step* getLastMove();

	void setPosition(char** chessDeck);
	void setFigures(figuresList* whiteFigures, figuresList* blackFigures);

	void setupCheck();
	void setupDraw();
	void setupIsEndGame();

	bool getIsCheck();
	bool getIsDraw();
	bool getIsEndGame();

	void printDeck();
	void printNotation();

	step* getBestStep();

private:
	void setupCurentDeck();
	void clearTreeStatement();
	void setupFlags();
	// variables for difficulty
	char difficulty;
	unsigned char maxDeep;      // how deep we want to analyze
	unsigned char curentDeep;

	char** curentChessDeck;    // main deck
	int positionScore;
	int treePositionScore;

	stepList* notation;
	step* bestStep;

	figuresList* whiteFigures;
	char whiteFiguresNumber;
	figuresList* blackFigures;
	char blackFiguresNumber;

	stepList allocatedSteps;
	unsigned short allocatedStepsNumber;

	bool isWhiteMove;

	bool isCheck;
	bool isEndGame;
	bool isDraw;

	deck** deckTree;

	bool botSideIsWhite;
};
