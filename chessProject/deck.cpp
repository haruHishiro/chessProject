#include "deck.h"


deck::deck(unsigned char difficulty) {
	deck::difficulty = difficulty;
	deck::setDificulty(difficulty);
	deck::curentDeep = 0;

	deck::deckTree = new deck * [deck::alfaBeta_k];
	if (deck::curentDeep == deck::deep) {
		if (deck::enableAlfaBeta) {
			for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
				deck::deckTree[i] = nullptr;
			}
		}
	}
	else {
		if (deck::enableAlfaBeta) {
			for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
				deck::deckTree[i] = new deck(difficulty, deck::curentDeep + 1);
			}
		}
	}

	deck::setupFlags();

	deck::curentChessDeck = new char* [8];
	for (char i = 0; i < 8; i++) {
		deck::curentChessDeck[i] = new char[8];
	}
}

deck::deck(unsigned char difficulty, unsigned char curentDeep) {
	deck::difficulty = difficulty;
	deck::curentDeep = curentDeep;
	deck::setDificulty(difficulty);

	deck::deckTree = new deck* [deck::alfaBeta_k];
	if (curentDeep == deck::deep) {
		if (deck::enableAlfaBeta) {
			for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
				deck::deckTree[i] = nullptr;
			}
		}
	}
	else {
		if (deck::enableAlfaBeta) {
			for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
				deck::deckTree[i] = new deck(difficulty, curentDeep + 1);
			}
		}
	}

	deck::setupFlags();

	deck::curentChessDeck = new char* [8];
	for (char i = 0; i < 8; i++) {
		deck::curentChessDeck[i] = new char[8];
	}
}

deck::~deck() {
	deck::whiteFigures.clear();
	deck::blackFigures.clear();

	for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
		delete deck::deckTree[i];
	}
	
	for (char i = 0; i < 8; i++) {
		delete deck::curentChessDeck[i];
	}
	delete deck::curentChessDeck;

	delete deck::deckTree;
}

void deck::setDificulty(unsigned char difficulty) {
	// if you want to add custom difficulty without alfa-beta you should to
	// get move for analyze
	// count all steps what we can with this move.
	// else use alfa-beta

	switch (difficulty) {
	case 1:
		deck::enableAlfaBeta = true;
		deck::alfaBeta_k = 3;
		deck::deep = 3;
		break;
	case 2:
		deck::enableAlfaBeta = true;
		deck::alfaBeta_k = 5;
		deck::deep = 7;
		break;
	case 3:
		// request on master fide
		deck::enableAlfaBeta = true;
		deck::alfaBeta_k = 10;
		deck::deep = 15;
		break;
	default:
		deck::enableAlfaBeta = true;
		deck::alfaBeta_k = 5;
		deck::deep = 5;
	}
}

void deck::doMove(step* move) {
	// writing move into notation
	deck::notation.pushBack(move);

	// free field
	deck::curentChessDeck[move->getPosXFrom()][move->getPosYFrom()] = 0;

	// set figure on new position
	switch (move->getFigureName()) {
	case 'P':
		if (move->getIsWhiteStep()) {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = 1;
		}
		else {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = -1;
		}
		break;
	case 'N':
		if (move->getIsWhiteStep()) {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = 2;
		}
		else {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = -2;
		}
		break;
	case 'B':
		if (move->getIsWhiteStep()) {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = 3;
		}
		else {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = -3;
		}
		break;
	case 'R':
		if (move->getIsWhiteStep()) {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = 4;
		}
		else {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = -4;
		}
		break;
	case 'Q':
		if (move->getIsWhiteStep()) {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = 5;
		}
		else {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = -5;
		}
		break;
	case 'K':
		if (move->getIsWhiteStep()) {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = 6;
		}
		else {
			deck::curentChessDeck[move->getPosXTo()][move->getPosYTo()] = -6;
		}
		break;
	default:
		break;
	}
	
	// if was eating delete eaten figure
	if (move->getIsEat()) {
		char eatenName = move->getEatenName();
		if (deck::isWhiteMove) {
			for (char i = 0; i < deck::blackFiguresNumber; i++) {
				if (deck::blackFigures[i]->getFigureName() == eatenName
					&& move->getPosXTo() == deck::blackFigures[i]->getPosX()
					&& move->getPosYTo() == deck::blackFigures[i]->getPosY()) {
					deck::blackFigures.remove(i);
					deck::blackFiguresNumber--;
				}
			}
		}
		else {
			for (char i = 0; i < deck::whiteFiguresNumber; i++) {
				if (deck::whiteFigures[i]->getFigureName() == eatenName
					&& move->getPosXTo() == deck::whiteFigures[i]->getPosX()
					&& move->getPosYTo() == deck::whiteFigures[i]->getPosY()) {
					deck::whiteFigures.remove(i);
					deck::whiteFiguresNumber--;
				}
			}
		}
	}

	// switch move
	deck::isWhiteMove = !deck::isWhiteMove;
}

int deck::getPositionScore() {
	     // position scoring function
	    // criteries:
	   // 1 - how many fields under white side control
	  // 2 - how many fields under black side control
	 // 3 - white figures cost
	// 4 - black figures cost

	int score = 0;
	char field_control_k = 10;

	for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
		score += field_control_k * deck::whiteFigures[i]->getStepsNumber();
		score += deck::whiteFigures[i]->getCost();
	}

	for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
		score -= field_control_k * deck::blackFigures[i]->getStepsNumber();
		score -= deck::blackFigures[i]->getCost();
	}

	return score;
}

void deck::setupSteps() {
	// all steps initiation
	if (deck::isWhiteMove) {
		for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
			deck::whiteFigures[i]->setupSteps(deck::curentChessDeck, notation.getLast());
		}
	}
	else {
		for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
			deck::blackFigures[i]->setupSteps(deck::curentChessDeck, notation.getLast());
		}
	}

	 // allocated steps initiation

}

step* deck::getBestStep() {
	// alfa-beta - number of steps what we check
	/*
	step** stepsArray = new step*[deck::alfaBeta_k];

	if (deck::curentDeep < deck::deep) {
		for (unsigned char i = 0; i < alfaBeta_k; i++) {
			stepsArray[i] = deck::deckTree[i]->getBestStep();
		}
	}

	unsigned char bestStepIndex = 0; 
	for (unsigned char i = 1; i < alfaBeta_k; i++) {
		if (deck::allocatedSteps[i]->getScore() > deck::allocatedSteps[bestStepIndex]->getScore()) {
			bestStepIndex = i;
		}
	}

	return deck::allocatedSteps[bestStepIndex];
	*/
}

void deck::setNotation(stepList notation) {
	step* s = notation.getFirst();

	while (s) {
		deck::notation.pushBack(s);
		s = s->getNextStep();
	}
}

void deck::setupFlags() {
	deck::isWhiteMove = true;
	deck::isCheck = false;
	deck::isDraw = false;
	deck::isEndGame = false;
}

void deck::clearTreeStatement() {
	for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
		delete deck::deckTree[i];
	}

	// from constructor
	if (deck::curentDeep == deck::deep) {
		if (deck::enableAlfaBeta) {
			for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
				deck::deckTree[i] = nullptr;
			}
		}
	}
	else {
		if (deck::enableAlfaBeta) {
			for (unsigned char i = 0; i < deck::alfaBeta_k; i++) {
				deck::deckTree[i] = new deck(deck::difficulty, deck::curentDeep + 1);
			}
		}
	}
}
