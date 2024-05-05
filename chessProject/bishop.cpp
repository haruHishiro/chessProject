#include "bishop.h"


void bishop::setupSteps(char** deck, step* lastStep) {
	if (bishop::isWhite) {
		bishop::whiteBishopSetup(deck, lastStep);
	}
	else {
		bishop::blackBishopSetup(deck, lastStep);
	}
}
