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

	virtual void setupSteps(char** deck, step* lastStep);

protected: // or protected or friend classes usage
	char figureName;
	bool isWhite;

	char posX;
	char posY;
	int cost;

	step** allocatedSteps;
	char stepsNumber;    // allocated steps length
	char stepsCount;    // curent number of steps
};
