#include "pawn.h"


void pawn::setupSteps(char** deck, step* lastStep) {
	if (pawn::isWhite) {
		pawn::whitePawnSetup(deck, lastStep);
	}
	else {
		pawn::blackPawnSetup(deck, lastStep);
	}
}

void pawn::whitePawnSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	// double move
	if (pawn::posY == 6) {
		if (deck[pawn::posX][pawn::posY - 1] == 0) {
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX, pawn::posY - 1, false, -1));
			if (deck[pawn::posX][pawn::posY - 2] == 0) {
				pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX, pawn::posY - 2, false, -1));
			}
		}
	}

	// default moving forward
	if (deck[pawn::posX][pawn::posY - 1] == 0) {
		if (pawn::posY - 1 > 0) {
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX, pawn::posY - 1, false, -1));
		}
		if (pawn::posY - 1 == 0) {
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX, pawn::posY - 1, false, -1, true, 'N'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX, pawn::posY - 1, false, -1, true, 'B'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX, pawn::posY - 1, false, -1, true, 'R'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX, pawn::posY - 1, false, -1, true, 'Q'));
		}
	}

	// eating on moove
	if (pawn::posY == 3 && lastStep->getFigureName() == 'P'
		&& (pawn::posX - 1 == lastStep->getPosXTo() || pawn::posX + 1 == lastStep->getPosXTo())
		&& lastStep->getPosYFrom() == 1
		&& lastStep->getPosYTo() == 3) {
		// body
		pawn::addStep(new step('P', true, pawn::posX, pawn::posY, lastStep->getPosXTo(), pawn::posY - 1, true, 'P'));
	}

	// default eating right
	if (pawn::posX + 1 < 8 && deck[pawn::posX + 1][pawn::posY - 1] < 0) {
		char fN = fArr[(deck[pawn::posX + 1][pawn::posY - 1]) * (-1)];
		if (pawn::posY - 1 > 0) {
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY - 1, true, fN));
		}
		else {
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY - 1, true, fN, true, 'N'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY - 1, true, fN, true, 'B'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY - 1, true, fN, true, 'R'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY - 1, true, fN, true, 'Q'));
		}
	}

	// default eating left
	if (pawn::posX - 1 >= 0 && deck[pawn::posX - 1][pawn::posY - 1] < 0) {
		char fN = fArr[(deck[pawn::posX - 1][pawn::posY - 1]) * (-1)];
		if (pawn::posY - 1 > 0) {
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY - 1, true, fN));
		}
		else {
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY - 1, true, fN, true, 'N'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY - 1, true, fN, true, 'B'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY - 1, true, fN, true, 'R'));
			pawn::addStep(new step('P', true, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY - 1, true, fN, true, 'Q'));
		}
	}
}

void pawn::blackPawnSetup(char** deck, step* lastStep) {
	const char fArr[] = "\0PNBRQK";
	// double move
	if (pawn::posY == 1) {
		if (deck[pawn::posX][pawn::posY + 1] == 0) {
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX, pawn::posY + 1, false, -1));
			if (deck[pawn::posX][pawn::posY + 2] == 0) {
				pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX, pawn::posY + 2, false, -1));
			}
		}
	}

	// default move forward
	if (deck[pawn::posX][pawn::posY + 1] == 0) {
		if (pawn::posY + 1 < 7) {
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX, pawn::posY + 1, false, -1));
		}
		if (pawn::posY + 1 == 7) {
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX, pawn::posY + 1, false, -1, true, 'N'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX, pawn::posY + 1, false, -1, true, 'B'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX, pawn::posY + 1, false, -1, true, 'R'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX, pawn::posY + 1, false, -1, true, 'Q'));
		}
	}

	// eating on moove
	if (pawn::posY == 4 && lastStep->getFigureName() == 'P'
		&& (pawn::posX - 1 == lastStep->getPosXTo() || pawn::posX + 1 == lastStep->getPosXTo())
		&& lastStep->getPosYFrom() == 6
		&& lastStep->getPosYTo() == 4) {
		// body
		pawn::addStep(new step('P', false, pawn::posX, pawn::posY, lastStep->getPosXTo(), pawn::posY + 1, true, 'P'));
	}

	// default eating right
	if (pawn::posX + 1 < 8 && deck[pawn::posX + 1][pawn::posY + 1] > 0) {
		char fN = fArr[(deck[pawn::posX + 1][pawn::posY + 1])];
		if (pawn::posY + 1 < 7) {
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY + 1, true, fN));
		}
		else {
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY + 1, true, fN, true, 'N'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY + 1, true, fN, true, 'B'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY + 1, true, fN, true, 'R'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX + 1, pawn::posY + 1, true, fN, true, 'Q'));
		}
	}

	// default eating left
	if (pawn::posX - 1 >= 0 && deck[pawn::posX - 1][posY + 1] > 0) {
		char fN = fArr[(deck[pawn::posX - 1][pawn::posY + 1])];
		if (pawn::posY + 1 < 7) {
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY + 1, true, fN));
		}
		else {
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY + 1, true, fN, true, 'N'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY + 1, true, fN, true, 'B'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY + 1, true, fN, true, 'R'));
			pawn::addStep(new step('P', false, pawn::posX, pawn::posY, pawn::posX - 1, pawn::posY + 1, true, fN, true, 'Q'));
		}
	}
}
