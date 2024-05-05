#include "figure.h"


figure::figure() {
	figure::stepsNumber = 0;
	figure::allocatedSteps = nullptr;
	figure::figureName = -1;
	figure::isWhite = true;
	figure::posX = -1;
	figure::posY = -1;
	figure::cost = 0;
	figure::stepsCount = figure::stepsNumber;
	figure::nextFigure = nullptr;
}

figure::figure(char figureName, bool isWhite, char posX, char posY) {
	figure::figureName = figureName;
	figure::isWhite = isWhite;
	figure::posX = posX;
	figure::posY = posY;

	figure::stepsNumber = 0;
	figure::allocatedSteps = nullptr;
	figure::stepsCount = figure::stepsNumber;

	figure::nextFigure = nullptr;

	switch (figure::figureName) {
	case 'P':
		if (isWhite) {
			figure::cost = 100;
		}
		else {
			figure::cost = -100;
		}
		break;
	case 'R':
		if (isWhite) {
			figure::cost = 500;
		}
		else {
			figure::cost = -500;
		}
		break;
	case 'N':
		if (isWhite) {
			figure::cost = 275;
		}
		else {
			figure::cost = -275;
		}
		break;
	case 'B':
		if (isWhite) {
			figure::cost = 325;
		}
		else {
			figure::cost = -325;
		}
		break;
	case 'Q':
		if (isWhite) {
			figure::cost = 900;
		}
		else {
			figure::cost = -900;
		}
		break;
	case 'K':
		if (isWhite) {
			figure::cost = 100000;
		}
		else {
			figure::cost = -100000;
		}
		break;
	default:
		figure::cost = 0;
		break;
	}
}

figure::figure(step** allocatedSteps, char stepsNumber, char figureName, bool isWhite, char posX, char posY) {
	figure::stepsNumber = stepsNumber;
	figure::allocatedSteps = new step*[stepsNumber];
	figure::figureName = figureName;
	figure::isWhite = isWhite;
	figure::posX = posX;
	figure::posY = posY;
	figure::cost = 0;
	figure::stepsCount = stepsNumber;
	for (char i = 0; i < stepsNumber; i++) {
		figure::allocatedSteps[i] = allocatedSteps[i];
	}
	figure::nextFigure = nullptr;
}

figure::figure(step** allocatedSteps, char stepsNumber, char figureName, bool isWhite, char posX, char posY, int cost) {
	figure::stepsNumber = stepsNumber;
	figure::allocatedSteps = new step*[stepsNumber];
	figure::figureName = figureName;
	figure::isWhite = isWhite;
	figure::posX = posX;
	figure::posY = posY;
	figure::cost = cost;
	figure::stepsCount = stepsNumber;
	for (char i = 0; i < stepsNumber; i++) {
		figure::allocatedSteps[i] = allocatedSteps[i];
	}
	figure::nextFigure = nullptr;
}

figure::~figure() {
	for (char i = 0; i < figure::stepsNumber; i++) {
		delete figure::allocatedSteps[i];
	}
	delete figure::allocatedSteps;
}

char figure::getFigureName() { return figure::figureName; }
void figure::setFigureName(char figureName) { figure::figureName = figureName; }
bool figure::getIsWhite() { return figure::isWhite; }
void figure::setIsWhite(bool isWhite) { figure::isWhite = isWhite; }
char figure::getPosX() { return figure::posX; }
void figure::setPosX(char posX) { figure::posX = posX; }
char figure::getPosY() { return figure::posY; }
void figure::setPosY(char posY) { figure::posY = posY; }
int figure::getCost() { return figure::cost; }
void figure::setCost(int cost) { figure::cost = cost; }
char figure::getStepsNumber() { return figure::stepsNumber; }
char figure::getStepsCount() { return figure::stepsCount; }
void figure::setStepsCOunt(char stepsCount) { figure::stepsCount = stepsCount; }
step** figure::getAllocatedSteps() { return figure::allocatedSteps; }

void figure::setAllocatedSteps(step** allocatedSteps, char stepsNumber) {
	figure::stepsNumber = stepsNumber;
	figure::allocatedSteps = new step*[stepsNumber];
	for (unsigned i = 0; i < stepsNumber; i++) {
		figure::allocatedSteps[i] = allocatedSteps[i];
	}
	figure::stepsCount = stepsNumber;
}

void figure::addStep(step* s) {
	if (figure::stepsCount + 1 >= figure::stepsNumber) {
		figure::stepsNumber += 4;
		figure::allocatedSteps = new step*[figure::stepsNumber];
	}
	figure::allocatedSteps[stepsCount] = s;
	figure::stepsCount++;
}

void figure::setupSteps(char** deck, step* lastStep){
	          // must be overrited in child classses
		     // const deck size [8][8]
	        // 0 - free field
	       // 1 - pawn
	      // 2 - knight
	     // 3 - bishop
	    // 4 - rook
	   // 5 - queen
	  // 6 - king
	 // if value < 0 that means black figure
	// if value > 0 that means white figure
}

figure* figure::getNextFigure() { return figure::nextFigure; }
void figure::setNextFigure(figure* nextFigure) { figure::nextFigure = nextFigure; }
