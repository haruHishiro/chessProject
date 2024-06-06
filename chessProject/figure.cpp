#include "figure.h"
#include <stdio.h>


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
	//figure::printSteps();
	//printf("%d\n", figure::stepsNumber);
	for (char i = 0; i < figure::stepsCount; i++) {
		if (allocatedSteps[i] != nullptr) delete figure::allocatedSteps[i];
		//printf("");
	}
	if (allocatedSteps != nullptr) delete figure::allocatedSteps;
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
	//printf("%c", s->getFigureName());
	if (figure::stepsCount + 1 >= figure::stepsNumber) {
		figure::stepsNumber += 30;
		figure::allocatedSteps = new step*[figure::stepsNumber];
	}
	figure::allocatedSteps[stepsCount] = s;
	figure::stepsCount++;

	//printf("%d\n", figure::stepsCount);
	//printf("%c%c%d->%c%d\n", s->getFigureName(), (s->getPosYFrom() + 'a'), s->getPosXFrom(), (s->getPosYTo() + 'a'), s->getPosXTo());
}

void figure::printSteps() {
	for (unsigned i = 0; i < figure::stepsCount; i++) {
		figure::allocatedSteps[i]->printStep();
	}
}

void figure::setupSteps(char** deck, step* lastStep){
	// clear
	for (char i = 0; i < figure::stepsCount; i++) {
		if (allocatedSteps[i] != nullptr) delete figure::allocatedSteps[i];
	}
	figure::stepsCount = 0;

	// adding
	if (figure::isWhite) {
		figure::whiteSetup(deck, lastStep);
	}
	else {
		figure::blackSetup(deck, lastStep);
	}
}

void figure::whiteSetup(char** deck, step* lastStep) {
	switch (figure::figureName) {
	case 'P':
		figure::whitePawnSetup(deck, lastStep);
		break;
	case 'N':
		figure::whiteKnightSetup(deck, lastStep);
		break;
	case 'B':
		figure::whiteBishopSetup(deck, lastStep);
		break;
	case 'R':
		figure::whiteRookSetup(deck, lastStep);
		break;
	case 'Q':
		figure::whiteQueenSetup(deck, lastStep);
		break;
	case 'K':
		figure::whiteKingSetup(deck, lastStep);
		break;
	}
}

void figure::blackSetup(char** deck, step* lastStep) {
	switch (figure::figureName) {
	case 'P':
		figure::blackPawnSetup(deck, lastStep);
		break;
	case 'N':
		figure::blackKnightSetup(deck, lastStep);
		break;
	case 'B':
		figure::blackBishopSetup(deck, lastStep);
		break;
	case 'R':
		figure::blackRookSetup(deck, lastStep);
		break;
	case 'Q':
		figure::blackQueenSetup(deck, lastStep);
		break;
	case 'K':
		figure::blackKingSetup(deck, lastStep);
		break;
	}
}

void figure::whitePawnSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	
	if (figure::posY == 6) {
		// double move
		if (deck[figure::posX][figure::posY - 1] == 0) {
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, -1));
			if (deck[figure::posX][figure::posY - 2] == 0) {
				figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX, figure::posY - 2, false, -1));
			}
		}
	}
	else {
		// default moving forward
		if (deck[figure::posX][figure::posY - 1] == 0) {
			if (figure::posY - 1 > 0) {
				figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, -1));
			}
			if (figure::posY - 1 == 0) {
				figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, -1, true, 'N'));
				figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, -1, true, 'B'));
				figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, -1, true, 'R'));
				figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, -1, true, 'Q'));
			}
		}
	}

	// eating on moove
	if (lastStep != nullptr) {
		if (figure::posY == 3 && lastStep && lastStep->getFigureName() == 'P'
			&& (figure::posX - 1 == lastStep->getPosXTo() || figure::posX + 1 == lastStep->getPosXTo())
			&& lastStep->getPosYFrom() == 1
			&& lastStep->getPosYTo() == 3) {
			// body
			figure::addStep(new step('P', true, figure::posX, figure::posY, lastStep->getPosXTo(), figure::posY - 1, true, 'P'));
		}
	}

	// default eating right
	if (figure::posX + 1 < 8 && deck[figure::posX + 1][figure::posY - 1] < 0) {
		char fN = fArr[(deck[figure::posX + 1][figure::posY - 1]) * (-1)];
		if (figure::posY - 1 > 0) {
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, true, fN));
		}
		else {
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, true, fN, true, 'N'));
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, true, fN, true, 'B'));
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, true, fN, true, 'R'));
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, true, fN, true, 'Q'));
		}
	}

	// default eating left
	if (figure::posX - 1 >= 0 && deck[figure::posX - 1][figure::posY - 1] < 0) {
		char fN = fArr[(deck[figure::posX - 1][figure::posY - 1]) * (-1)];
		if (figure::posY - 1 > 0) {
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, true, fN));
		}
		else {
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, true, fN, true, 'N'));
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, true, fN, true, 'B'));
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, true, fN, true, 'R'));
			figure::addStep(new step('P', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, true, fN, true, 'Q'));
		}
	}
}

void figure::blackPawnSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	
	if (figure::posY == 1) {
		// double move
		if (deck[figure::posX][figure::posY + 1] == 0) {
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, -1));
			if (deck[figure::posX][figure::posY + 2] == 0) {
				figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX, figure::posY + 2, false, -1));
			}
		}
	}
	else {
		// default move forward
		if (deck[figure::posX][figure::posY + 1] == 0) {
			if (figure::posY + 1 < 7) {
				figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, -1));
			}
			if (figure::posY + 1 == 7) {
				figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, -1, true, 'N'));
				figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, -1, true, 'B'));
				figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, -1, true, 'R'));
				figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, -1, true, 'Q'));
			}
		}
	}

	if (lastStep != nullptr) {
		// eating on moove
		if (figure::posY == 4 && lastStep->getFigureName() == 'P'
			&& (figure::posX - 1 == lastStep->getPosXTo() || figure::posX + 1 == lastStep->getPosXTo())
			&& lastStep->getPosYFrom() == 6
			&& lastStep->getPosYTo() == 4) {
			// body
			figure::addStep(new step('P', false, figure::posX, figure::posY, lastStep->getPosXTo(), figure::posY + 1, true, 'P'));
		}
	}

	// default eating right
	if (figure::posX + 1 < 8 && deck[figure::posX + 1][figure::posY + 1] > 0) {
		char fN = fArr[(deck[figure::posX + 1][figure::posY + 1])];
		if (figure::posY + 1 < 7) {
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, true, fN));
		}
		else {
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, true, fN, true, 'N'));
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, true, fN, true, 'B'));
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, true, fN, true, 'R'));
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, true, fN, true, 'Q'));
		}
	}

	// default eating left
	if (figure::posX - 1 >= 0 && deck[figure::posX - 1][posY + 1] > 0) {
		char fN = fArr[(deck[figure::posX - 1][figure::posY + 1])];
		if (figure::posY + 1 < 7) {
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, fN));
		}
		else {
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, fN, true, 'N'));
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, fN, true, 'B'));
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, fN, true, 'R'));
			figure::addStep(new step('P', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, fN, true, 'Q'));
		}
	}
}

void figure::whiteKnightSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;
	if (figure::posX + 2 < 8 && figure::posY + 1 < 8) {
		if (deck[figure::posX + 2][figure::posY + 1] < 0) {
			fN = fArr[(deck[figure::posX + 2][figure::posY + 1]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 2, figure::posY + 1, true, fN));
		}
		if (deck[figure::posX + 2][figure::posY + 1] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 2, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posX + 2 < 8 && figure::posY - 1 >= 0) {
		if (deck[figure::posX + 2][figure::posY - 1] < 0) {
			fN = fArr[(deck[figure::posX + 2][figure::posY - 1]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 2, figure::posY - 1, true, fN));
		}
		if (deck[figure::posX + 2][figure::posY - 1] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 2, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY + 2 < 8) {
		if (deck[figure::posX + 1][figure::posY + 2] < 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY + 2]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 1, figure::posY + 2, true, fN));
		}
		if (deck[figure::posX + 1][figure::posY + 2] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 1, figure::posY + 2, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY - 2 >= 0) {
		if (deck[figure::posX + 1][figure::posY - 2] < 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY - 1]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 2, true, fN));
		}
		if (deck[figure::posX + 1][figure::posY - 2] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 2, false, '\0'));
		}
	}

	if (figure::posX - 2 >= 0 && figure::posY - 1 >= 0) {
		if (deck[figure::posX - 2][figure::posY - 1] < 0) {
			fN = fArr[(deck[figure::posX - 2][figure::posY - 1]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 2, figure::posY - 1, true, fN));
		}
		if (deck[figure::posX - 2][figure::posY - 1] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 2, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX - 2 >= 0 && figure::posY + 1 < 8) {
		if (deck[figure::posX - 2][figure::posY + 1] < 0) {
			fN = fArr[(deck[figure::posX - 2][figure::posY + 1]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 2, figure::posY + 1, true, fN));
		}
		if (deck[figure::posX - 2][figure::posY + 1] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 2, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY - 2 >= 0) {
		if (deck[figure::posX - 1][figure::posY - 2] < 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY - 2]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 2, true, fN));
		}
		if (deck[figure::posX - 1][figure::posY - 2] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 2, false, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY + 2 < 8) {
		if (deck[figure::posX - 1][figure::posY + 2] < 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY + 2]) * (-1)];
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 1, figure::posY + 2, true, fN));
		}
		if (deck[figure::posX - 1][figure::posY + 2] == 0) {
			figure::addStep(new step('N', true, figure::posX, figure::posY, figure::posX - 1, figure::posY + 2, false, '\0'));
		}
	}
}

void figure::blackKnightSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;
	if (figure::posX + 2 < 8 && figure::posY + 1 < 8) {
		if (deck[figure::posX + 2][figure::posY + 1] > 0) {
			fN = fArr[(deck[figure::posX + 2][figure::posY + 1])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 2, figure::posY + 1, true, fN));
		}
		if (deck[figure::posX + 2][figure::posY + 1] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 2, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posX + 2 < 8 && figure::posY - 1 >= 0) {
		if (deck[figure::posX + 2][figure::posY - 1] > 0) {
			fN = fArr[(deck[figure::posX + 2][figure::posY - 1])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 2, figure::posY - 1, true, fN));
		}
		if (deck[figure::posX + 2][figure::posY - 1] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 2, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY + 2 < 8) {
		if (deck[figure::posX + 1][figure::posY + 2] > 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY + 2])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 2, true, fN));
		}
		if (deck[figure::posX + 1][figure::posY + 2] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 2, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY - 2 >= 0) {
		if (deck[figure::posX + 1][figure::posY - 2] > 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY - 1])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 1, figure::posY - 2, true, fN));
		}
		if (deck[figure::posX + 1][figure::posY - 2] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX + 1, figure::posY - 2, false, '\0'));
		}
	}

	if (figure::posX - 2 >= 0 && figure::posY - 1 >= 0) {
		if (deck[figure::posX - 2][figure::posY - 1] > 0) {
			fN = fArr[(deck[figure::posX - 2][figure::posY - 1])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 2, figure::posY - 1, true, fN));
		}
		if (deck[figure::posX - 2][figure::posY - 1] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 2, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX - 2 >= 0 && figure::posY + 1 < 8) {
		if (deck[figure::posX - 2][figure::posY + 1] > 0) {
			fN = fArr[(deck[figure::posX - 2][figure::posY + 1])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 2, figure::posY + 1, true, fN));
		}
		if (deck[figure::posX - 2][figure::posY + 1] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 2, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY - 2 >= 0) {
		if (deck[figure::posX - 1][figure::posY - 2] > 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY - 2])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 1, figure::posY - 2, true, fN));
		}
		if (deck[figure::posX - 1][figure::posY - 2] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 1, figure::posY - 2, false, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY + 2 < 8) {
		if (deck[figure::posX - 1][figure::posY + 2] > 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY + 2])];
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 2, true, fN));
		}
		if (deck[figure::posX - 1][figure::posY + 2] == 0) {
			figure::addStep(new step('N', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 2, false, '\0'));
		}
	}
}

void figure::whiteBishopSetup(char** deck, step* lastStep) {

	const char fArr[] = "\0PNBRQK";
	char fN;
	for (char i = 1; figure::posX + i < 8 && figure::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY + i] < 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY + i]) * (-1)];
				//printf("here");
				figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX + i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			//printf("here");
			figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX + i, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY - i] < 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY - i]) * (-1)];
				//printf("here");
				figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX - i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			//printf("here\n%d %d\n",posX -i, posY -i);
			figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX - i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX + i < 8 && figure::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY - i] < 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY - i]) * (-1)];
				//printf("here");
				figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX + i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			//printf("here");
			figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX + i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY + i] < 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY + i]) * (-1)];
				//printf("here");
				figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX - i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			//printf("here");
			figure::addStep(new step('B', true, figure::posX, figure::posY, figure::posX - i, figure::posY + i, false, '\0'));
		}
	}
}

void figure::blackBishopSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	for (char i = 1; figure::posX + i < 8 && figure::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY + i] > 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY + i])];
				figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX + i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX + i, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY - i] > 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY - i])];
				figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX - i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX - i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX + i < 8 && figure::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY - i] > 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY - i])];
				figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX + i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX + i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY + i] > 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY + i])];
				figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX - i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('B', false, figure::posX, figure::posY, figure::posX - i, figure::posY + i, false, '\0'));
		}
	}
}

void figure::whiteRookSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	for (char i = 1; figure::posX + i < 8; i++) {
		if (deck[figure::posX + i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY] < 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY]) * (-1)];
				figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX + i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX + i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0; i++) {
		if (deck[figure::posX - i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY] < 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY]) * (-1)];
				figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX - i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX - i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posY + i < 8; i++) {
		if (deck[figure::posX][figure::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY + i] < 0) {
				fN = fArr[(deck[figure::posX][figure::posY + i]) * (-1)];
				figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posY - i >= 0; i++) {
		if (deck[figure::posX][figure::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY - i] < 0) {
				fN = fArr[(deck[figure::posX][figure::posY - i]) * (-1)];
				figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', true, figure::posX, figure::posY, figure::posX, figure::posY - i, false, '\0'));
		}
	}
}

void figure::blackRookSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	for (char i = 1; figure::posX + i < 8; i++) {
		if (deck[figure::posX + i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY] > 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY])];
				figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX + i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX + i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0; i++) {
		if (deck[figure::posX - i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY] > 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY])];
				figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX - i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX - i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posY + i < 8; i++) {
		if (deck[figure::posX][figure::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY + i] > 0) {
				fN = fArr[(deck[figure::posX][figure::posY + i])];
				figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posY - i >= 0; i++) {
		if (deck[figure::posX][figure::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY - i] > 0) {
				fN = fArr[(deck[figure::posX][figure::posY - i])];
				figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('R', false, figure::posX, figure::posY, figure::posX, figure::posY - i, false, '\0'));
		}
	}
}

void figure::whiteQueenSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	// like bishop
	for (char i = 1; figure::posX + i < 8 && figure::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY + i] < 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY + i]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX + i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX + i, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY - i] < 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY - i]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX - i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX - i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX + i < 8 && figure::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY - i] < 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY - i]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX + i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX + i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY + i] < 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY + i]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX - i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX - i, figure::posY + i, false, '\0'));
		}
	}

	// like rook
	for (char i = 1; figure::posX + i < 8; i++) {
		if (deck[figure::posX + i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY] < 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX + i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX + i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0; i++) {
		if (deck[figure::posX - i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY] < 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX - i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX - i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posY + i < 8; i++) {
		if (deck[figure::posX][figure::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY + i] < 0) {
				fN = fArr[(deck[figure::posX][figure::posY + i]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posY - i >= 0; i++) {
		if (deck[figure::posX][figure::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY - i] < 0) {
				fN = fArr[(deck[figure::posX][figure::posY - i]) * (-1)];
				figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', true, figure::posX, figure::posY, figure::posX, figure::posY - i, false, '\0'));
		}
	}
}

void figure::blackQueenSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	// like bishop
	for (char i = 1; figure::posX + i < 8 && figure::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY + i] > 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY + i])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX + i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX + i, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY - i] > 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY - i])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX - i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX - i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX + i < 8 && figure::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY - i] > 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY - i])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX + i, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX + i, figure::posY - i, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0 && figure::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY + i] > 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY + i])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX - i, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX - i, figure::posY + i, false, '\0'));
		}
	}

	// like rook
	for (char i = 1; figure::posX + i < 8; i++) {
		if (deck[figure::posX + i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX + i][figure::posY] > 0) {
				fN = fArr[(deck[figure::posX + i][figure::posY])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX + i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX + i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posX - i >= 0; i++) {
		if (deck[figure::posX - i][figure::posY] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX - i][figure::posY] > 0) {
				fN = fArr[(deck[figure::posX - i][figure::posY])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX - i, figure::posY, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX - i, figure::posY, false, '\0'));
		}
	}

	for (char i = 1; figure::posY + i < 8; i++) {
		if (deck[figure::posX][figure::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY + i] > 0) {
				fN = fArr[(deck[figure::posX][figure::posY + i])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX, figure::posY + i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX, figure::posY + i, false, '\0'));
		}
	}

	for (char i = 1; figure::posY - i >= 0; i++) {
		if (deck[figure::posX][figure::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[figure::posX][figure::posY - i] > 0) {
				fN = fArr[(deck[figure::posX][figure::posY - i])];
				figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX, figure::posY - i, true, fN));
			}
			break;
		}
		else {
			figure::addStep(new step('Q', false, figure::posX, figure::posY, figure::posX, figure::posY - i, false, '\0'));
		}
	}
}

void figure::whiteKingSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	if (figure::posX + 1 < 8) {
		if (deck[figure::posX + 1][figure::posY] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX + 1, figure::posY, false, '\0'));
		}

		if (deck[figure::posX + 1][figure::posY] < 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX + 1, figure::posY, true, fN));
		}
	}

	if (figure::posX - 1 >= 0) {
		if (deck[figure::posX - 1][figure::posY] < 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX - 1, figure::posY, true, fN));
		}

		if (deck[figure::posX - 1][figure::posY] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX - 1, figure::posY, false, '\0'));
		}
	}

	if (figure::posY + 1 < 8) {
		if (deck[figure::posX][figure::posY + 1] < 0) {
			fN = fArr[(deck[figure::posX][figure::posY + 1]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX, figure::posY + 1, true, fN));
		}

		if (deck[figure::posX][figure::posY + 1] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posY - 1 >= 0) {
		if (deck[figure::posX][figure::posY - 1] < 0) {
			fN = fArr[(deck[figure::posX][figure::posY - 1]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, true, fN));
		}

		if (deck[figure::posX][figure::posY - 1] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY + 1 < 8) {
		if (deck[figure::posX + 1][figure::posY + 1] < 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY + 1]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, true, fN));
		}

		if (deck[figure::posX + 1][figure::posY + 1] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY - 1 >= 0) {
		if (deck[figure::posX + 1][figure::posY - 1] < 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY - 1]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, true, fN));
		}

		if (deck[figure::posX + 1][figure::posY - 1] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY + 1 < 8) {
		if (deck[figure::posX - 1][figure::posY + 1] < 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY + 1]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, fN));
		}

		if (deck[figure::posX - 1][figure::posY + 1] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY - 1 >= 0) {
		if (deck[figure::posX - 1][figure::posY - 1] < 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY - 1]) * (-1)];
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, true, fN));
		}

		if (deck[figure::posX - 1][figure::posY - 1] == 0) {
			figure::addStep(new step('K', true, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, false, '\0'));
		}
	}
}

void figure::blackKingSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	if (figure::posX + 1 < 8) {
		if (deck[figure::posX + 1][figure::posY] > 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX + 1, figure::posY, true, fN));
		}

		if (deck[figure::posX + 1][figure::posY] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX + 1, figure::posY, false, '\0'));
		}
	}

	if (figure::posX - 1 >= 0) {
		if (deck[figure::posX - 1][figure::posY] > 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX - 1, figure::posY, true, fN));
		}

		if (deck[figure::posX - 1][figure::posY] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX - 1, figure::posY, false, '\0'));
		}
	}

	if (figure::posY + 1 < 8) {
		if (deck[figure::posX][figure::posY + 1] > 0) {
			fN = fArr[(deck[figure::posX][figure::posY + 1])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, true, fN));
		}

		if (deck[figure::posX][figure::posY + 1] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posY - 1 >= 0) {
		if (deck[figure::posX][figure::posY - 1] > 0) {
			fN = fArr[(deck[figure::posX][figure::posY - 1])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX, figure::posY - 1, true, fN));
		}

		if (deck[figure::posX][figure::posY - 1] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY + 1 < 8) {
		if (deck[figure::posX + 1][figure::posY + 1] > 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY + 1])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, true, fN));
		}

		if (deck[figure::posX + 1][figure::posY + 1] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX + 1, figure::posY + 1, false, '\0'));
		}
	}

	if (figure::posX + 1 < 8 && figure::posY - 1 >= 0) {
		if (deck[figure::posX + 1][figure::posY - 1] > 0) {
			fN = fArr[(deck[figure::posX + 1][figure::posY - 1])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, true, fN));
		}

		if (deck[figure::posX + 1][figure::posY - 1] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX + 1, figure::posY - 1, false, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY + 1 < 8) {
		if (deck[figure::posX - 1][figure::posY + 1] > 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY + 1])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, fN));
		}

		if (deck[figure::posX - 1][figure::posY + 1] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX - 1, figure::posY + 1, true, '\0'));
		}
	}

	if (figure::posX - 1 >= 0 && figure::posY - 1 >= 0) {
		if (deck[figure::posX - 1][figure::posY - 1] > 0) {
			fN = fArr[(deck[figure::posX - 1][figure::posY - 1])];
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, true, fN));
		}

		if (deck[figure::posX - 1][figure::posY - 1] == 0) {
			figure::addStep(new step('K', false, figure::posX, figure::posY, figure::posX - 1, figure::posY - 1, false, '\0'));
		}
	}
}

figure* figure::getNextFigure() { return figure::nextFigure; }
void figure::setNextFigure(figure* next) { figure::nextFigure = next; }
