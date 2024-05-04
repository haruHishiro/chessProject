#include "deck.h"


int main() {
	// branch init
	deck* chessDeck = new deck(1);

	chessDeck->setupSteps();
	chessDeck->doMove(chessDeck->getBestStep());

	return 0;
}