#include "king.h"

void king::setupSteps(char** deck, step* lastStep) {
	if (king::isWhite) {
		king::whiteKingSetup(deck, lastStep);
	}
	else {
		king::blackKingSetup(deck, lastStep);
	}
}

void king::whiteKingSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	if (king::posX + 1 < 8) {
		if (deck[king::posX + 1][king::posY] < 0) {
			fN = fArr[(deck[king::posX + 1][king::posY]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY, true, fN));
		}

		if (deck[king::posX + 1][king::posY] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY, false, '\0'));
		}
	}

	if (king::posX - 1 >= 0) {
		if (deck[king::posX - 1][king::posY] < 0) {
			fN = fArr[(deck[king::posX - 1][king::posY]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY, true, fN));
		}

		if (deck[king::posX - 1][king::posY] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY, false, '\0'));
		}
	}

	if (king::posY + 1 < 8) {
		if (deck[king::posX][king::posY + 1] < 0) {
			fN = fArr[(deck[king::posX][king::posY + 1]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY + 1, true, fN));
		}

		if (deck[king::posX][king::posY + 1] = 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY + 1, false, '\0'));
		}
	}

	if (king::posY - 1 >= 0) {
		if (deck[king::posX][king::posY - 1] < 0) {
			fN = fArr[(deck[king::posX][king::posY - 1]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY - 1, true, fN));
		}

		if (deck[king::posX][king::posY - 1] = 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY - 1, false, '\0'));
		}
	}

	if (king::posX + 1 < 8 && king::posY + 1 < 8) {
		if (deck[king::posX + 1][king::posY + 1] < 0) {
			fN = fArr[(deck[king::posX + 1][king::posY + 1]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY + 1, true, fN));
		}

		if (deck[king::posX + 1][king::posY + 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY + 1, false, '\0'));
		}
	}

	if (king::posX + 1 < 8 && king::posY - 1 >= 0) {
		if (deck[king::posX + 1][king::posY - 1] < 0) {
			fN = fArr[(deck[king::posX + 1][king::posY - 1]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY - 1, true, fN));
		}

		if (deck[king::posX + 1][king::posY - 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY - 1, false, '\0'));
		}
	}

	if (king::posX - 1 >= 0 && king::posY + 1 < 8) {
		if (deck[king::posX - 1][king::posY + 1] < 0) {
			fN = fArr[(deck[king::posX - 1][king::posY + 1]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY + 1, true, fN));
		}

		if (deck[king::posX - 1][king::posY + 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY + 1, true, '\0'));
		}
	}

	if (king::posX - 1 >= 0 && king::posY - 1 >= 0) {
		if (deck[king::posX - 1][king::posY - 1] < 0) {
			fN = fArr[(deck[king::posX - 1][king::posY - 1]) * (-1)];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY - 1, true, fN));
		}

		if (deck[king::posX - 1][king::posY - 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY - 1, false, '\0'));
		}
	}
}

void king::blackKingSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	char fN;

	if (king::posX + 1 < 8) {
		if (deck[king::posX + 1][king::posY] > 0) {
			fN = fArr[(deck[king::posX + 1][king::posY])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY, true, fN));
		}

		if (deck[king::posX + 1][king::posY] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY, false, '\0'));
		}
	}

	if (king::posX - 1 >= 0) {
		if (deck[king::posX - 1][king::posY] > 0) {
			fN = fArr[(deck[king::posX - 1][king::posY])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY, true, fN));
		}

		if (deck[king::posX - 1][king::posY] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY, false, '\0'));
		}
	}

	if (king::posY + 1 < 8) {
		if (deck[king::posX][king::posY + 1] > 0) {
			fN = fArr[(deck[king::posX][king::posY + 1])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY + 1, true, fN));
		}

		if (deck[king::posX][king::posY + 1] = 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY + 1, false, '\0'));
		}
	}

	if (king::posY - 1 >= 0) {
		if (deck[king::posX][king::posY - 1] > 0) {
			fN = fArr[(deck[king::posX][king::posY - 1])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY - 1, true, fN));
		}

		if (deck[king::posX][king::posY - 1] = 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX, king::posY - 1, false, '\0'));
		}
	}

	if (king::posX + 1 < 8 && king::posY + 1 < 8) {
		if (deck[king::posX + 1][king::posY + 1] > 0) {
			fN = fArr[(deck[king::posX + 1][king::posY + 1])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY + 1, true, fN));
		}

		if (deck[king::posX + 1][king::posY + 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY + 1, false, '\0'));
		}
	}

	if (king::posX + 1 < 8 && king::posY - 1 >= 0) {
		if (deck[king::posX + 1][king::posY - 1] > 0) {
			fN = fArr[(deck[king::posX + 1][king::posY - 1])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY - 1, true, fN));
		}

		if (deck[king::posX + 1][king::posY - 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX + 1, king::posY - 1, false, '\0'));
		}
	}

	if (king::posX - 1 >= 0 && king::posY + 1 < 8) {
		if (deck[king::posX - 1][king::posY + 1] > 0) {
			fN = fArr[(deck[king::posX - 1][king::posY + 1])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY + 1, true, fN));
		}

		if (deck[king::posX - 1][king::posY + 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY + 1, true, '\0'));
		}
	}

	if (king::posX - 1 >= 0 && king::posY - 1 >= 0) {
		if (deck[king::posX - 1][king::posY - 1] > 0) {
			fN = fArr[(deck[king::posX - 1][king::posY - 1])];
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY - 1, true, fN));
		}

		if (deck[king::posX - 1][king::posY - 1] == 0) {
			king::addStep(new step('K', true, king::posX, king::posY, king::posX - 1, king::posY - 1, false, '\0'));
		}
	}
}
