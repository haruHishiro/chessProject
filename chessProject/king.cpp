#include "king.h"

void king::setupSteps(char** deck, step* lastStep) {
	if (king::isWhite) {
		king::whiteKingSetup(deck, lastStep);
	}
	else {
		king::blackKingSetup(deck, lastStep);
	}
}
