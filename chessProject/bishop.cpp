#include "bishop.h"


void bishop::setupSteps(char** deck, step* lastStep) {
	if (bishop::isWhite) {
		bishop::whiteBishopSetup(deck, lastStep);
	}
	else {
		bishop::blackBishopSetup(deck, lastStep);
	}
}

void bishop::whiteBishopSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;
	for (char i = 1; bishop::posX + i < 8 && bishop::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX + i][bishop::posY + i] < 0) {
				fN = fArr[(deck[bishop::posX + i][bishop::posY + i]) * (-1)];
				bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY + i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY + i, false, '\0'));
		}
	}

	for (char i = 1; bishop::posX - i >= 0 && bishop::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX - i][bishop::posY - i] < 0) {
				fN = fArr[(deck[bishop::posX - i][bishop::posY - i]) * (-1)];
				bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY - i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY - i, false, '\0'));
		}
	}

	for (char i = 1; bishop::posX + i < 8 && bishop::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX + i][bishop::posY - i] < 0) {
				fN = fArr[(deck[bishop::posX + i][bishop::posY - i]) * (-1)];
				bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY - i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY - i, false, '\0'));
		}
	}

	for (char i = 1; bishop::posX - i >= 0 && bishop::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX - i][bishop::posY + i] < 0) {
				fN = fArr[(deck[bishop::posX - i][bishop::posY + i]) * (-1)];
				bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY + i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', true, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY + i, false, '\0'));
		}
	}
}

void bishop::blackBishopSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	for (char i = 1; bishop::posX + i < 8 && bishop::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX + i][bishop::posY + i] > 0) {
				fN = fArr[(deck[bishop::posX + i][bishop::posY + i])];
				bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY + i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY + i, false, '\0'));
		}
	}

	for (char i = 1; bishop::posX - i >= 0 && bishop::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX - i][bishop::posY - i] > 0) {
				fN = fArr[(deck[bishop::posX - i][bishop::posY - i])];
				bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY - i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY - i, false, '\0'));
		}
	}

	for (char i = 1; bishop::posX + i < 8 && bishop::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX + i][bishop::posY - i] > 0) {
				fN = fArr[(deck[bishop::posX + i][bishop::posY - i])];
				bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY - i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX + i, bishop::posY - i, false, '\0'));
		}
	}

	for (char i = 1; bishop::posX - i >= 0 && bishop::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[bishop::posX - i][bishop::posY + i] > 0) {
				fN = fArr[(deck[bishop::posX - i][bishop::posY + i])];
				bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY + i, true, fN));
			}
			break;
		}
		else {
			bishop::addStep(new step('B', false, bishop::posX, bishop::posY, bishop::posX - i, bishop::posY + i, false, '\0'));
		}
	}
}
