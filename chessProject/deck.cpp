#include "deck.h"

deck::deck(unsigned char difficulty) {
	deck::setDificulty(difficulty);
	deck::curentDeep = 0;
	deck::botSideIsWhite = false;
	deck::setupFlags();
	
	deck::curentChessDeck = new char* [8];
	for (char i = 0; i < 8; i++) {
		deck::curentChessDeck[i] = new char[8];
	}
}

deck::deck(unsigned char curentDeep, unsigned char maxDeep) {
	deck::maxDeep = maxDeep;
	deck::curentDeep = curentDeep;
	deck::botSideIsWhite = false;
	deck::setupFlags();

	deck::curentChessDeck = new char* [8];
	for (char i = 0; i < 8; i++) {
		deck::curentChessDeck[i] = new char[8];
	}
}

deck::~deck() {
	deck::whiteFigures.clear();
	deck::blackFigures.clear();

	for (unsigned char i = 0; i < deck::allocatedStepsNumber; i++) {
		delete deck::deckTree[i];
	}
	
	for (char i = 0; i < 8; i++) {
		delete deck::curentChessDeck[i];
	}
	delete deck::curentChessDeck;

	delete deck::deckTree;
}

void deck::setDificulty(unsigned char difficulty) {
	switch (difficulty) {
	case 1:
		deck::maxDeep = 1;
		break;
	case 2:
		deck::maxDeep = 5;
		break;
	case 3:
		// request on master fide
		deck::maxDeep = 15;
		break;
	default:
		deck::maxDeep = 1;
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

void deck::setupFiguresSteps() {
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

int deck::analyze() {
	if (deck::curentDeep == deck::maxDeep) return;
	if (deck::allocatedStepsNumber < 1) {
		// check endGame flags and return
	}
	deck::deckTree = new deck* [deck::allocatedStepsNumber];
	
	for (unsigned short i = 0; i < allocatedStepsNumber; i++) {
		deck::deckTree[i] = new deck(deck::difficulty, deck::curentDeep + 1);
		deck::deckTree[i]->setIsWhiteMove(deck::isWhiteMove);
		deck::deckTree[i]->doMove(deck::allocatedSteps[i]);
		deck::deckTree[i]->setupPositionScore();
	}

	if (deck::curentDeep + 1 < deck::maxDeep) {
		// deeper and deeper
		for (unsigned short i = 0; i < allocatedStepsNumber; i++) {
			deck::deckTree[i]->setupFiguresSteps();
			deck::deckTree[i]->analyze();
		}
	}
	else {
		// return score
		deck::positionScore = deck::deckTree[0]->getPositionScore();
		for (unsigned short i = 0; i < allocatedStepsNumber; i++) {
			// find max value
		}
		 // set gettet max value to pos score
		// return max value
	}
}

void deck::setIsWhiteMove(bool isWhiteMove) {
	deck::isWhiteMove = isWhiteMove;
}

void deck::setupPositionScore() {
	deck::positionScore = deck::getPositionScore();
}

void deck::setNotation(stepList notation) {
	step* s = notation.getFirst();

	while (s) {
		deck::notation.pushBack(s);
		s = s->getNextStep();
	}
}

void deck::setPosition(char** chessDeck) {
	for (char i = 0; i < 8; i++) {
		for (char j = 0; j < 8; j++) {
			deck::curentChessDeck[i][j] = chessDeck[i][j];
		}
	}
}

void deck::setFigures(figuresList whiteFigures, figuresList blackFigures) {
	deck::whiteFigures = whiteFigures;
	deck::blackFigures = blackFigures;
}

void deck::setupFlags() {
	deck::isWhiteMove = true;
	deck::isCheck = false;
	deck::isDraw = false;
	deck::isEndGame = false;
}

void deck::clearTreeStatement() {
	for (unsigned char i = 0; i < deck::allocatedStepsNumber; i++) {
		delete deck::deckTree[i];
	}
}
