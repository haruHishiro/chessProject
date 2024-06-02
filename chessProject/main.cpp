#include "deck.h"


int main() {
	// branch init
	deck* chessDeck = new deck(2);

	chessDeck->setupStartPosition();
	chessDeck->printDeck();

	chessDeck->getBestStep()->printStep();

	return 0;
}