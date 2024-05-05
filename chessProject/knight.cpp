#include "knight.h"

void knight::setupSteps(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	if (knight::isWhite) {
		knight::whiteKnightSetup(deck, lastStep);
	}
	else {
		knight::blackKnightSetup(deck, lastStep);
	}
}

void knight::whiteKnightSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;
	if (knight::posX + 2 < 8 && knight::posY + 1 < 8) {
		if (deck[knight::posX + 2][knight::posY + 1] < 0) {
			fN = fArr[(deck[knight::posX + 2][knight::posY + 1]) * (-1)];
			knight::addStep(new step('N',true, knight::posX, knight::posY, knight::posX + 2, knight::posY + 1,true, fN));
		}
		if (deck[knight::posX + 2][knight::posY + 1] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX + 2, knight::posY + 1, false, '\0'));
		}
	}

	if (knight::posX + 2 < 8 && knight::posY - 1 >= 0) {
		if (deck[knight::posX + 2][knight::posY - 1] < 0) {
			fN = fArr[(deck[knight::posX + 2][knight::posY - 1]) * (-1)];
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX + 2, knight::posY - 1, true, fN));
		}
		if (deck[knight::posX + 2][knight::posY - 1] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX + 2, knight::posY - 1, false, '\0'));
		}
	}

	if (knight::posX + 1 < 8 && knight::posY + 2 < 8) {
		if (deck[knight::posX + 1][knight::posY + 2] < 0) {
			fN = fArr[(deck[knight::posX + 1][knight::posY + 2]) * (-1)];
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX + 1, knight::posY + 2, true, fN));
		}
		if (deck[knight::posX + 1][knight::posY + 2] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX + 1, knight::posY + 2, false, '\0'));
		}
	}

	if (knight::posX + 1 < 8 && knight::posY - 2 >= 0) {
		if (deck[knight::posX + 1][knight::posY - 2] < 0) {
			fN = fArr[(deck[knight::posX + 1][knight::posY - 1]) * (-1)];
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX + 1, knight::posY - 2, true, fN));
		}
		if (deck[knight::posX + 1][knight::posY - 2] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX + 1, knight::posY - 2, false, '\0'));
		}
	}

	if (knight::posX - 2 >= 0 && knight::posY - 1 >= 0) {
		if (deck[knight::posX - 2][knight::posY - 1] < 0) {
			fN = fArr[(deck[knight::posX - 2][knight::posY - 1]) * (-1)];
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 2, knight::posY - 1, true, fN));
		}
		if (deck[knight::posX - 2][knight::posY - 1] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 2, knight::posY - 1, false, '\0'));
		}
	}

	if (knight::posX - 2 >= 0 && knight::posY + 1 < 8) {
		if (deck[knight::posX - 2][knight::posY + 1] < 0) {
			fN = fArr[(deck[knight::posX - 2][knight::posY + 1]) * (-1)];
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 2, knight::posY + 1, true, fN));
		}
		if (deck[knight::posX - 2][knight::posY + 1] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 2, knight::posY + 1, false, '\0'));
		}
	}

	if (knight::posX - 1 >= 0 && knight::posY - 2 >= 0) {
		if (deck[knight::posX - 1][knight::posY - 2] < 0) {
			fN = fArr[(deck[knight::posX - 1][knight::posY - 2]) * (-1)];
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 1, knight::posY - 2, true, fN));
		}
		if (deck[knight::posX - 1][knight::posY - 2] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 1, knight::posY - 2, false, '\0'));
		}
	}

	if (knight::posX - 1 >= 0 && knight::posY + 2 < 8) {
		if (deck[knight::posX - 1][knight::posY + 2] < 0) {
			fN = fArr[(deck[knight::posX - 1][knight::posY + 2]) * (-1)];
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 1, knight::posY + 2, true, fN));
		}
		if (deck[knight::posX - 1][knight::posY + 2] == 0) {
			knight::addStep(new step('N', true, knight::posX, knight::posY, knight::posX - 1, knight::posY + 2, false, '\0'));
		}
	}
}

void knight::blackKnightSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;
	if (knight::posX + 2 < 8 && knight::posY + 1 < 8) {
		if (deck[knight::posX + 2][knight::posY + 1] > 0) {
			fN = fArr[(deck[knight::posX + 2][knight::posY + 1])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 2, knight::posY + 1, true, fN));
		}
		if (deck[knight::posX + 2][knight::posY + 1] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 2, knight::posY + 1, false, '\0'));
		}
	}

	if (knight::posX + 2 < 8 && knight::posY - 1 >= 0) {
		if (deck[knight::posX + 2][knight::posY - 1] > 0) {
			fN = fArr[(deck[knight::posX + 2][knight::posY - 1])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 2, knight::posY - 1, true, fN));
		}
		if (deck[knight::posX + 2][knight::posY - 1] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 2, knight::posY - 1, false, '\0'));
		}
	}

	if (knight::posX + 1 < 8 && knight::posY + 2 < 8) {
		if (deck[knight::posX + 1][knight::posY + 2] > 0) {
			fN = fArr[(deck[knight::posX + 1][knight::posY + 2])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 1, knight::posY + 2, true, fN));
		}
		if (deck[knight::posX + 1][knight::posY + 2] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 1, knight::posY + 2, false, '\0'));
		}
	}

	if (knight::posX + 1 < 8 && knight::posY - 2 >= 0) {
		if (deck[knight::posX + 1][knight::posY - 2] > 0) {
			fN = fArr[(deck[knight::posX + 1][knight::posY - 1])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 1, knight::posY - 2, true, fN));
		}
		if (deck[knight::posX + 1][knight::posY - 2] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX + 1, knight::posY - 2, false, '\0'));
		}
	}

	if (knight::posX - 2 >= 0 && knight::posY - 1 >= 0) {
		if (deck[knight::posX - 2][knight::posY - 1] > 0) {
			fN = fArr[(deck[knight::posX - 2][knight::posY - 1])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 2, knight::posY - 1, true, fN));
		}
		if (deck[knight::posX - 2][knight::posY - 1] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 2, knight::posY - 1, false, '\0'));
		}
	}

	if (knight::posX - 2 >= 0 && knight::posY + 1 < 8) {
		if (deck[knight::posX - 2][knight::posY + 1] > 0) {
			fN = fArr[(deck[knight::posX - 2][knight::posY + 1])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 2, knight::posY + 1, true, fN));
		}
		if (deck[knight::posX - 2][knight::posY + 1] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 2, knight::posY + 1, false, '\0'));
		}
	}

	if (knight::posX - 1 >= 0 && knight::posY - 2 >= 0) {
		if (deck[knight::posX - 1][knight::posY - 2] > 0) {
			fN = fArr[(deck[knight::posX - 1][knight::posY - 2])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 1, knight::posY - 2, true, fN));
		}
		if (deck[knight::posX - 1][knight::posY - 2] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 1, knight::posY - 2, false, '\0'));
		}
	}

	if (knight::posX - 1 >= 0 && knight::posY + 2 < 8) {
		if (deck[knight::posX - 1][knight::posY + 2] > 0) {
			fN = fArr[(deck[knight::posX - 1][knight::posY + 2])];
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 1, knight::posY + 2, true, fN));
		}
		if (deck[knight::posX - 1][knight::posY + 2] == 0) {
			knight::addStep(new step('N', false, knight::posX, knight::posY, knight::posX - 1, knight::posY + 2, false, '\0'));
		}
	}
}
