#include "queen.h"

void queen::setupSteps(char** deck, step* lastStep) {
	if (queen::isWhite) {
		queen::whiteQueenSetup(deck, lastStep);
	}
	else {
		queen::blackQueenSetup(deck, lastStep);
	}
}
