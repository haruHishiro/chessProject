#include "rook.h"

void rook::setupSteps(char** deck, step* lastStep) {
	if (rook::isWhite) {
		rook::whiteRookSetup(deck, lastStep);
	}
	else {
		rook::blackRookSetup(deck, lastStep);
	}
}

void rook::whiteRookSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;
	
	for (char i = 1; rook::posX + i < 8; i++) {
		if (deck[rook::posX + i][rook::posY] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX + i][rook::posY] < 0) {
				fN = fArr[(deck[rook::posX + i][rook::posY]) * (-1)];
				rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX + i, rook::posY, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX + i, rook::posY, false, '\0'));
		}
	}

	for (char i = 1; rook::posX - i >= 0; i++) {
		if (deck[rook::posX - i][rook::posY] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX - i][rook::posY] < 0) {
				fN = fArr[(deck[rook::posX - i][rook::posY]) * (-1)];
				rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX - i, rook::posY, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX - i, rook::posY, false, '\0'));
		}
	}

	for (char i = 1; rook::posY + i < 8; i++) {
		if (deck[rook::posX][rook::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX][rook::posY + i] < 0) {
				fN = fArr[(deck[rook::posX][rook::posY + i]) * (-1)];
				rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX, rook::posY + i, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX, rook::posY + i, false, '\0'));
		}
	}

	for (char i = 1; rook::posY - i >= 0; i++) {
		if (deck[rook::posX][rook::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX][rook::posY - i] < 0) {
				fN = fArr[(deck[rook::posX][rook::posY - i]) * (-1)];
				rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX, rook::posY - i, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', true, rook::posX, rook::posY, rook::posX, rook::posY - i, false, '\0'));
		}
	}
}

void rook::blackRookSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	for (char i = 1; rook::posX + i < 8; i++) {
		if (deck[rook::posX + i][rook::posY] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX + i][rook::posY] > 0) {
				fN = fArr[(deck[rook::posX + i][rook::posY])];
				rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX + i, rook::posY, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX + i, rook::posY, false, '\0'));
		}
	}

	for (char i = 1; rook::posX - i >= 0; i++) {
		if (deck[rook::posX - i][rook::posY] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX - i][rook::posY] > 0) {
				fN = fArr[(deck[rook::posX - i][rook::posY])];
				rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX - i, rook::posY, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX - i, rook::posY, false, '\0'));
		}
	}

	for (char i = 1; rook::posY + i < 8; i++) {
		if (deck[rook::posX][rook::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX][rook::posY + i] > 0) {
				fN = fArr[(deck[rook::posX][rook::posY + i])];
				rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX, rook::posY + i, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX, rook::posY + i, false, '\0'));
		}
	}

	for (char i = 1; rook::posY - i >= 0; i++) {
		if (deck[rook::posX][rook::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[rook::posX][rook::posY - i] > 0) {
				fN = fArr[(deck[rook::posX][rook::posY - i])];
				rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX, rook::posY - i, true, fN));
			}
			break;
		}
		else {
			rook::addStep(new step('R', false, rook::posX, rook::posY, rook::posX, rook::posY - i, false, '\0'));
		}
	}
}
