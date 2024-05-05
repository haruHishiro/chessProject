#include "queen.h"

void queen::setupSteps(char** deck, step* lastStep) {
	if (queen::isWhite) {
		queen::whiteQueenSetup(deck, lastStep);
	}
	else {
		queen::blackQueenSetup(deck, lastStep);
	}
}

void queen::whiteQueenSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	// like bishop
	for (char i = 1; queen::posX + i < 8 && queen::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX + i][queen::posY + i] < 0) {
				fN = fArr[(deck[queen::posX + i][queen::posY + i]) * (-1)];
				queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX + i, queen::posY + i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX + i, queen::posY + i, false, '\0'));
		}
	}

	for (char i = 1; queen::posX - i >= 0 && queen::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX - i][queen::posY - i] < 0) {
				fN = fArr[(deck[queen::posX - i][queen::posY - i]) * (-1)];
				queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX - i, queen::posY - i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX - i, queen::posY - i, false, '\0'));
		}
	}

	for (char i = 1; queen::posX + i < 8 && queen::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX + i][queen::posY - i] < 0) {
				fN = fArr[(deck[queen::posX + i][queen::posY - i]) * (-1)];
				queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX + i, queen::posY - i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX + i, queen::posY - i, false, '\0'));
		}
	}

	for (char i = 1; queen::posX - i >= 0 && queen::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX - i][queen::posY + i] < 0) {
				fN = fArr[(deck[queen::posX - i][queen::posY + i]) * (-1)];
				queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX - i, queen::posY + i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', true, queen::posX, queen::posY, queen::posX - i, queen::posY + i, false, '\0'));
		}
	}

	// like rook
	for (char i = 1; queen::posX + i < 8; i++) {
		if (deck[queen::posX + i][queen::posY] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX + i][queen::posY] < 0) {
				fN = fArr[(deck[queen::posX + i][queen::posY]) * (-1)];
				queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX + i, queen::posY, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX + i, queen::posY, false, '\0'));
		}
	}

	for (char i = 1; queen::posX - i >= 0; i++) {
		if (deck[queen::posX - i][queen::posY] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX - i][queen::posY] < 0) {
				fN = fArr[(deck[queen::posX - i][queen::posY]) * (-1)];
				queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX - i, queen::posY, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX - i, queen::posY, false, '\0'));
		}
	}

	for (char i = 1; queen::posY + i < 8; i++) {
		if (deck[queen::posX][queen::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX][queen::posY + i] < 0) {
				fN = fArr[(deck[queen::posX][queen::posY + i]) * (-1)];
				queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX, queen::posY + i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX, queen::posY + i, false, '\0'));
		}
	}

	for (char i = 1; queen::posY - i >= 0; i++) {
		if (deck[queen::posX][queen::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX][queen::posY - i] < 0) {
				fN = fArr[(deck[queen::posX][queen::posY - i]) * (-1)];
				queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX, queen::posY - i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', true, queen::posX, queen::posY, queen::posX, queen::posY - i, false, '\0'));
		}
	}
}

void queen::blackQueenSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	// like bishop
	for (char i = 1; queen::posX + i < 8 && queen::posY + i < 8; i++) {
		if (deck[posX + i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX + i][queen::posY + i] > 0) {
				fN = fArr[(deck[queen::posX + i][queen::posY + i])];
				queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX + i, queen::posY + i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX + i, queen::posY + i, false, '\0'));
		}
	}

	for (char i = 1; queen::posX - i >= 0 && queen::posY - i >= 0; i++) {
		if (deck[posX - i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX - i][queen::posY - i] > 0) {
				fN = fArr[(deck[queen::posX - i][queen::posY - i])];
				queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX - i, queen::posY - i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX - i, queen::posY - i, false, '\0'));
		}
	}

	for (char i = 1; queen::posX + i < 8 && queen::posY - i >= 0; i++) {
		if (deck[posX + i][posY - i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX + i][queen::posY - i] > 0) {
				fN = fArr[(deck[queen::posX + i][queen::posY - i])];
				queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX + i, queen::posY - i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX + i, queen::posY - i, false, '\0'));
		}
	}

	for (char i = 1; queen::posX - i >= 0 && queen::posY + i < 8; i++) {
		if (deck[posX - i][posY + i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX - i][queen::posY + i] > 0) {
				fN = fArr[(deck[queen::posX - i][queen::posY + i])];
				queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX - i, queen::posY + i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('B', false, queen::posX, queen::posY, queen::posX - i, queen::posY + i, false, '\0'));
		}
	}

	// like rook
	for (char i = 1; queen::posX + i < 8; i++) {
		if (deck[queen::posX + i][queen::posY] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX + i][queen::posY] > 0) {
				fN = fArr[(deck[queen::posX + i][queen::posY])];
				queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX + i, queen::posY, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX + i, queen::posY, false, '\0'));
		}
	}

	for (char i = 1; queen::posX - i >= 0; i++) {
		if (deck[queen::posX - i][queen::posY] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX - i][queen::posY] > 0) {
				fN = fArr[(deck[queen::posX - i][queen::posY])];
				queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX - i, queen::posY, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX - i, queen::posY, false, '\0'));
		}
	}

	for (char i = 1; queen::posY + i < 8; i++) {
		if (deck[queen::posX][queen::posY + i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX][queen::posY + i] > 0) {
				fN = fArr[(deck[queen::posX][queen::posY + i])];
				queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX, queen::posY + i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX, queen::posY + i, false, '\0'));
		}
	}

	for (char i = 1; queen::posY - i >= 0; i++) {
		if (deck[queen::posX][queen::posY - i] != 0) {
			// can not continue moving to this side
			if (deck[queen::posX][queen::posY - i] > 0) {
				fN = fArr[(deck[queen::posX][queen::posY - i])];
				queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX, queen::posY - i, true, fN));
			}
			break;
		}
		else {
			queen::addStep(new step('R', false, queen::posX, queen::posY, queen::posX, queen::posY - i, false, '\0'));
		}
	}
}
