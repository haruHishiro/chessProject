#include "step.h"
#include <stdio.h>


step::step() {
	step::stepNumber = 0;
	step::isWhiteStep = true;
	step::figureName = 0;
	step::posXFrom = -1;
	step::posYFrom = -1;
	step::posXTo = -1;
	step::posYTo = -1;
	step::isEat = false;
	step::eatenName = 0;
	step::score = 0;
	step::nextStep = nullptr;
	step::prevStep = nullptr;
	step::pwnOnLast = false;
	step::newFigureName = -1;
}

step::step(char figureName, bool isWhiteStep, char fromX, char fromY, char toX, char toY, bool isEat, char eatenName) {
	step::figureName = figureName;
	step::isWhiteStep = isWhiteStep;
	step::posXFrom = fromX;
	step::posYFrom = fromY;
	step::posXTo = toX;
	step::posYTo = toY;
	step::isEat = isEat;
	step::eatenName = eatenName;
	step::nextStep = nullptr;
	step::prevStep = nullptr;
	step::stepNumber = 0;
	step::score = 0;
	step::pwnOnLast = false;
	step::newFigureName = -1;
}

step::step(char figureName, bool isWhiteStep, char fromX, char fromY, char toX, char toY, bool isEat, char eatenName, bool pwnOnLast, char newFigureName) {
	step::figureName = figureName;
	step::isWhiteStep = isWhiteStep;
	step::posXFrom = fromX;
	step::posYFrom = fromY;
	step::posXTo = toX;
	step::posYTo = toY;
	step::isEat = isEat;
	step::eatenName = eatenName;
	step::nextStep = nullptr;
	step::prevStep = nullptr;
	step::stepNumber = 0;
	step::score = 0;
	step::pwnOnLast = pwnOnLast;
	step::newFigureName = newFigureName;
}

unsigned short step::getStepNumber() { return step::stepNumber; }
void step::setStepNumber(unsigned short stepNumber) { step::stepNumber = stepNumber; }
bool step::getIsWhiteStep() { return step::isWhiteStep; }
void step::setIsWhiteStep(bool isWhiteStep) { step::isWhiteStep = isWhiteStep; }
char step::getFigureName() { return step::figureName; }
void step::setFigureName(char figureName) { step::figureName = figureName; }
char step::getPosXFrom() { return step::posXFrom; }
void step::setPosXFrom(char posXFrom) { step::posXFrom = posXFrom; }
char step::getPosYFrom() { return step::posYFrom; }
void step::setPosYFrom(char posYFrom) { step::posYFrom = posYFrom; }
char step::getPosXTo() { return step::posXTo; }
void step::setPosXTo(char posXTo) { step::posXTo = posXTo; }
char step::getPosYTo() { return step::posYTo; }
void step::setPosYTo(char posYTo) { step::posYTo = posYTo; }
void step::setPosFrom(char X, char Y) { step::posXFrom = X; step::posYFrom = Y; }
void step::setPosTo(char X, char Y) { step::posXTo = X; step::posYTo = Y; }
bool step::getIsEat() { return step::isEat; }
void step::setIsEat(bool isEat) { step::isEat = isEat; }
char step::getEatenName() { return step::eatenName; }
void step::setEatenName(char eatenName) { step::eatenName = eatenName; }
unsigned step::getScore() { return step::score; }
void step::setScore(unsigned score) { step::score = score; }
step* step::getNextStep() { return step::nextStep; }
void step::setNextStep(step* nextStep) { step::nextStep = nextStep; }
step* step::getPrevStep() { return step::prevStep; }
void step::setPrevStep(step* prevStep) { step::prevStep = prevStep; }
char step::getNewFigureName() { return step::figureName; }
void step::setNewFigureName(char newFigureName) { step::newFigureName = newFigureName; }
bool step::getPwnOnLast() { return step::pwnOnLast; }
void step::setPwnOnLast(bool pwnOnLast) { step::pwnOnLast = pwnOnLast; }

void step::printStep() {
	if (step::getIsWhiteStep()) {
		printf(" %d. %c%c%d->%c%d",step::stepNumber, step::figureName, (step::posXFrom + 'a'), step::posYFrom, (step::posXTo + 'a'), step::posYTo);
	}
	else {
		printf(" %c%c%d->%c%d\n",step::figureName, (step::posXFrom + 'a'), step::posYFrom, (step::posXTo + 'a'), step::posYTo);
	}
}
