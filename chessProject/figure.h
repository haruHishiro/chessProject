#pragma once
#include "step.h"


class figure {
public:
	figure();
	figure(char figureName, bool isWhite, char posX, char posY);
	figure(step** allocatedSteps, char stepsNumber, char figureName, bool isWhite, char posX, char posY);
	figure(step** allocatedSteps, char stepsNumber, char figureName, bool isWhite, char posX, char posY, int cost);
	~figure();

	char getFigureName();
	void setFigureName(char figureName);

	bool getIsWhite();
	void setIsWhite(bool isWhite);

	char getPosX();
	void setPosX(char posX);

	char getPosY();
	void setPosY(char posY);

	int getCost();
	void setCost(int cost);

	char getStepsNumber();

	char getStepsCount();
	void setStepsCOunt(char stepsCount);

	step** getAllocatedSteps();
	void setAllocatedSteps(step** allocatedSteps, char stepsNumber);

	void addStep(step* s);
	void printSteps();

	void setupSteps(char** deck, step* lastStep);
	void whiteSetup(char** deck, step* lastStep);
	void blackSetup(char** deck, step* lastStep);

	void whitePawnSetup(char** deck, step* lastStep);
	void blackPawnSetup(char** deck, step* lastStep);

	void whiteKnightSetup(char** deck, step* lastStep);
	void blackKnightSetup(char** deck, step* lastStep);

	void whiteBishopSetup(char** deck, step* lastStep);
	void blackBishopSetup(char** deck, step* lastStep);

	void whiteRookSetup(char** deck, step* lastStep);
	void blackRookSetup(char** deck, step* lastStep);

	void whiteQueenSetup(char** deck, step* lastStep);
	void blackQueenSetup(char** deck, step* lastStep);

	void whiteKingSetup(char** deck, step* lastStep);
	void blackKingSetup(char** deck, step* lastStep);

	figure* getNextFigure();
	void setNextFigure(figure* nextFigure);

private: // or protected or friend classes usage
	char figureName;
	bool isWhite;

	char posX;
	char posY;
	int cost;

	step** allocatedSteps;
	char stepsNumber;    // allocated steps length
	char stepsCount;    // curent number of steps

	figure* nextFigure;
};
