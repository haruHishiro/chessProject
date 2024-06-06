#include "deck.h"


int main() {
	// branch init
	deck* chessDeck = new deck(2);

	chessDeck->setupStartPosition();

	//chessDeck->getBestStep()->printStep();

	chessDeck->doMove(chessDeck->getBestStep());
	
	chessDeck->printDeck();
	//chessDeck->printNotation();

	chessDeck->doMove(chessDeck->getBestStep());
	chessDeck->printDeck();

	chessDeck->doMove(chessDeck->getBestStep());
	chessDeck->printDeck();

	chessDeck->doMove(chessDeck->getBestStep());
	chessDeck->printDeck();

	chessDeck->doMove(chessDeck->getBestStep());
	chessDeck->printDeck();

	return 0;
}