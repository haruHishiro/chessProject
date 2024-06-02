#include "deck.h"


int main() {
	// branch init
	deck* chessDeck = new deck(1);

	chessDeck->setupStartPosition();
	chessDeck->printDeck();

	chessDeck->getBestStep();

	return 0;
}