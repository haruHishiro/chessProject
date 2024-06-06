#pragma once

#include "figure.h"
#include "stepList.h"
#include "figuresList.h"


class deck {
public:
	deck(unsigned char difficulty);
	~deck();
	
	void setupStartPosition();

	void doMove(step* move);
	bool isCorrectMove(step* move);

	int getPositionScore();

	void setupFiguresSteps();
	void allocFiguresSteps();

	void newAnalize(char curentDeep, char maxDeep);
	void newAnalize();

	void setIsWhiteMove(bool isWhiteMove);
	void setupPositionScore();
	void setPositionScore(int positionScore);
	void setNotation(stepList* notation);

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

	step* getLast();
	step* getBestStep();

	step* getBestStepMove();

	void setBestStep(step* best);

	bool getIsWhiteMove();

	figuresList* getBlackFiguresList();
	figuresList* getWhiteFiguresList();

	bool IsValidMove(step* move);

	void setBotSide(bool side);
	bool getBotSide();

	void printValidSteps();

private:
	void setupCurentDeck();
	void clearTreeStatement();
	void setupFlags();
	// variables for difficulty
	char difficulty;

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

	unsigned short curentDeep;
};
