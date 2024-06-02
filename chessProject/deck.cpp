#include "deck.h"


deck::deck(unsigned char difficulty) {
	deck::setDificulty(difficulty);
	deck::curentDeep = 0;
	deck::botSideIsWhite = false;
	deck::setupFlags();
	deck::allocatedStepsNumber = 0;

	deck::curentChessDeck = new char* [8];
	for (char i = 0; i < 8; i++) {
		deck::curentChessDeck[i] = new char[8];
	}

	deck::bestStep = nullptr;
}

deck::deck(unsigned char curentDeep, unsigned char maxDeep) {
	deck::maxDeep = maxDeep;
	deck::curentDeep = curentDeep;
	deck::botSideIsWhite = false;
	deck::setupFlags();

	deck::allocatedStepsNumber = 0;

	deck::curentChessDeck = new char* [8];
	for (char i = 0; i < 8; i++) {
		deck::curentChessDeck[i] = new char[8];
	}

	deck::bestStep = nullptr;
}

deck::~deck() {
	//deck::whiteFigures.printFigures();
	deck::whiteFigures.clear();
	//deck::blackFigures.printFigures();
	deck::blackFigures.clear();

	//printf("hi");

	for (char i = 0; i < 8; i++) {
		if (deck::curentChessDeck[i] != nullptr) delete deck::curentChessDeck[i];
	}
	if (deck::curentChessDeck != nullptr) delete deck::curentChessDeck;
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

void deck::setupStartPosition() {
	deck::whiteFigures.addFigure('P', true , 0, 6);
	deck::whiteFigures.addFigure('P', true , 1, 6);
	deck::whiteFigures.addFigure('P', true , 2, 6);
	deck::whiteFigures.addFigure('P', true , 3, 6);
	deck::whiteFigures.addFigure('P', true , 4, 6);
	deck::whiteFigures.addFigure('P', true , 5, 6);
	deck::whiteFigures.addFigure('P', true , 6, 6);
	deck::whiteFigures.addFigure('P', true , 7, 6);

	deck::whiteFigures.addFigure('R', true, 0, 7);
	deck::whiteFigures.addFigure('N', true, 1, 7);
	deck::whiteFigures.addFigure('B', true, 2, 7);
	deck::whiteFigures.addFigure('Q', true, 3, 7);
	deck::whiteFigures.addFigure('K', true, 4, 7);
	deck::whiteFigures.addFigure('B', true, 5, 7);
	deck::whiteFigures.addFigure('N', true, 6, 7);
	deck::whiteFigures.addFigure('R', true, 7, 7);

	deck::whiteFiguresNumber = deck::whiteFigures.getFiguresNumber();

	deck::blackFigures.addFigure('P', false, 0, 1);
	deck::blackFigures.addFigure('P', false, 1, 1);
	deck::blackFigures.addFigure('P', false, 2, 1);
	deck::blackFigures.addFigure('P', false, 3, 1);
	deck::blackFigures.addFigure('P', false, 4, 1);
	deck::blackFigures.addFigure('P', false, 5, 1);
	deck::blackFigures.addFigure('P', false, 6, 1);
	deck::blackFigures.addFigure('P', false, 7, 1);

	deck::blackFigures.addFigure('R', false, 0, 0);
	deck::blackFigures.addFigure('N', false, 1, 0);
	deck::blackFigures.addFigure('B', false, 2, 0);
	deck::blackFigures.addFigure('Q', false, 3, 0);
	deck::blackFigures.addFigure('K', false, 4, 0);
	deck::blackFigures.addFigure('B', false, 5, 0);
	deck::blackFigures.addFigure('N', false, 6, 0);
	deck::blackFigures.addFigure('R', false, 7, 0);

	deck::blackFiguresNumber = deck::blackFigures.getFiguresNumber();

	deck::setupCurentDeck();
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

	// update figures positions
	if (deck::isWhiteMove) {
		for (char i = 0; i < deck::whiteFiguresNumber; i++) {
			if (move->getPosXFrom() == deck::whiteFigures[i]->getPosX()
				&& move->getPosYFrom() == deck::whiteFigures[i]->getPosY()) {
				deck::whiteFigures[i]->setPosX(move->getPosXTo());
				deck::whiteFigures[i]->setPosY(move->getPosYTo());
			}
		}
	}
	else {
		for (char i = 0; i < deck::blackFiguresNumber; i++) {
			if (move->getPosXFrom() == deck::blackFigures[i]->getPosX()
				&& move->getPosYFrom() == deck::blackFigures[i]->getPosY()) {
				deck::blackFigures[i]->setPosX(move->getPosXTo());
				deck::blackFigures[i]->setPosY(move->getPosYTo());
			}
		}
	}

	// switch move
	deck::isWhiteMove = !deck::isWhiteMove;

}

bool deck::isCorrectMove(step* move) {
	//printf("here\n");
	//move->printStep();
	//printf("\n");

	bool retFlag;
	deck* breanch = new deck(deck::curentDeep, deck::maxDeep);
	breanch->setupStartPosition();
	breanch->setNotation(deck::notation);
	breanch->setPosition(deck::curentChessDeck);
	breanch->setIsWhiteMove(deck::isWhiteMove);

	breanch->doMove(move);
	breanch->setIsWhiteMove(deck::isWhiteMove);
	breanch->setupCheck();
	if (!(breanch->getIsCheck())) {
		retFlag = true;
	}
	else {
		retFlag = false;
	}

	delete breanch;
	return retFlag;
}

int deck::getPositionScore() {
	 // position scoring function
    // criteries:
   // 1 - how many fields under whites side control
  // 2 - how many fields under blacks side control
 // 3 - white figures cost
// 4 - black figures cost
	
	for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
		deck::blackFigures[i]->setupSteps(deck::curentChessDeck, notation.getLast());
	}
	for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
		deck::whiteFigures[i]->setupSteps(deck::curentChessDeck, notation.getLast());
	}
	

	int score = 0;
	char field_control_k = 10;

	for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
		score += (field_control_k * deck::whiteFigures[i]->getStepsCount());
		score += deck::whiteFigures[i]->getCost();
	}

	for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
		score -= (field_control_k * deck::blackFigures[i]->getStepsCount());
		score += deck::blackFigures[i]->getCost();
	}

	return score;
}

void deck::setupFiguresSteps() {
	// all steps initiation
	if (deck::isWhiteMove) {		
		for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
			//deck::printDeck();
			deck::whiteFigures[i]->setupSteps(deck::curentChessDeck, notation.getLast());
			//printf("%d:%c->",i, deck::whiteFigures[i]->getFigureName());
			//deck::whiteFigures[i]->printSteps();
			//printf("\n");
		}
	}
	else {
		for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
			deck::blackFigures[i]->setupSteps(deck::curentChessDeck, notation.getLast());
		}
	}
}

void deck::allocFiguresSteps() {
	deck::setupCheck();
	
	deck::allocatedStepsNumber = 0;
	if (deck::isWhiteMove) {
		for (unsigned i = 0; i < deck::whiteFiguresNumber; i++) {
			step** figureSteps = deck::whiteFigures[i]->getAllocatedSteps();
			for (unsigned j = 0; j < deck::whiteFigures[i]->getStepsCount(); j++) {
				if (isCorrectMove(figureSteps[j])) {
					deck::allocatedSteps.pushBack(figureSteps[j]);
					deck::allocatedStepsNumber++;
				}
			}
		}
	}
	else {
		for (unsigned i = 0; i < deck::blackFiguresNumber; i++) {
			step** figureSteps = deck::blackFigures[i]->getAllocatedSteps();
			for (unsigned j = 0; j < deck::blackFigures[i]->getStepsCount(); j++) {
				if (isCorrectMove(figureSteps[j])) {
					deck::allocatedSteps.pushBack(figureSteps[j]);
					deck::allocatedStepsNumber++;
				}
			}
		}
	}
}

int deck::analyze() {
	
	if (deck::curentDeep == deck::maxDeep) {
		
		deck::printDeck();
		deck::setupPositionScore();
		return deck::positionScore;
	}
	

	if (deck::allocatedStepsNumber < 1) {
		
		// check endGame flags and return
		if (deck::isDraw) {
			// no moves = draw
			deck::positionScore = 0;
		}
		if (deck::isCheck && isWhiteMove) {
			// white must move, but can not -> black wins
			deck::positionScore = -100000;
		}
		else {
			deck::positionScore = 100000;
		}
		deck::isEndGame = true;
		return deck::positionScore;
	}
	

	deck::deckTree = new deck * [deck::allocatedStepsNumber];

	for (unsigned short i = 0; i < allocatedStepsNumber; i++) {
		printf("\nmove: %d\n", i);
		deck::deckTree[i] = new deck(deck::difficulty, deck::curentDeep + 1);
		deck::deckTree[i]->setIsWhiteMove(deck::isWhiteMove);
		deck::deckTree[i]->setFigures(whiteFigures, blackFigures);
		deck::deckTree[i]->setPosition(curentChessDeck);

		deck::allocatedSteps[i]->printStep();
		
		deck::deckTree[i]->doMove(deck::allocatedSteps[i]);
		deck::deckTree[i]->printDeck();
		deck::deckTree[i]->setupPositionScore();
		
		printf("score: %d", deck::deckTree[i]->getPositionScore());
	}

	if (deck::curentDeep + 1 < deck::maxDeep) {
		// deeper and deeper
		// check endgame flags before
		if (deck::isEndGame) {
			if (deck::isDraw) {
				// no moves = draw
				deck::positionScore = 0;
			}
			if (deck::isCheck && isWhiteMove) {
				// white must move, but can not -> black wins
				deck::positionScore = -100000;
			}
			else {
				deck::positionScore = 100000;
			}
			return deck::positionScore;
		}

		for (unsigned short i = 0; i < allocatedStepsNumber; i++) {
			// setup allocated steps array
			deck::deckTree[i]->setupFiguresSteps();
			// continue analize
			deck::deckTree[i]->analyze();
		}
	}
	else {
		// return score
		deck::positionScore = deck::deckTree[0]->getPositionScore();
		deck::bestStep = deck::deckTree[0]->getLastMove();
		// setup best step
		for (unsigned short i = 1; i < allocatedStepsNumber; i++) {
			if (deck::isWhiteMove) {
				// whites move - find max positive (max)
				printf("pos score: %d > %d?", deck::deckTree[i]->getPositionScore(), deck::positionScore);
				if (deck::deckTree[i]->getPositionScore() > deck::positionScore) {
					deck::positionScore = deck::deckTree[i]->getPositionScore();
					deck::bestStep = deck::deckTree[i]->getLastMove();
				}
			}
			else {
				// blacks move - find max negative (min)
				if (deck::deckTree[i]->getPositionScore() < deck::positionScore) {
					deck::positionScore = deck::deckTree[i]->getPositionScore();
					deck::bestStep = deck::deckTree[i]->getLastMove();
				}
			}
		}
	}
}

void deck::setIsWhiteMove(bool isWhiteMove) {
	deck::isWhiteMove = isWhiteMove;
}

void deck::setupPositionScore() {
	deck::positionScore = deck::getPositionScore();
}

void deck::setPositionScore(int positionScore) {
	deck::positionScore = positionScore;
}

void deck::setNotation(stepList notation) {
	step* s = notation.getFirst();

	while (s) {
		deck::notation.pushBack(s);
		s = s->getNextStep();
	}
}

step* deck::getLastMove() {
	return deck::notation.getLast();
}

void deck::setPosition(char** chessDeck) {
	for (char i = 0; i < 8; i++) {
		for (char j = 0; j < 8; j++) {
			deck::curentChessDeck[i][j] = chessDeck[i][j];
		}
	}
}

void deck::setFigures(figuresList whiteFigures, figuresList blackFigures) {
	//printf("here 0\n");
	for (unsigned short i = 0; i < whiteFigures.getFiguresNumber(); i++) {
		deck::whiteFigures.addFigure(whiteFigures[i]->getFigureName(), whiteFigures[i]->getIsWhite(), whiteFigures[i]->getPosX(), whiteFigures[i]->getPosY());
	}
	//printf("here 1\n");
	for (unsigned short i = 0; i < blackFigures.getFiguresNumber(); i++) {
		deck::blackFigures.addFigure(blackFigures[i]->getFigureName(), blackFigures[i]->getIsWhite(), blackFigures[i]->getPosX(), blackFigures[i]->getPosY());
	}
	//printf("here 2\n");
	deck::whiteFiguresNumber = deck::whiteFigures.getFiguresNumber();
	deck::blackFiguresNumber = deck::blackFigures.getFiguresNumber();
	//printf("here 3\n");
	//printf("%d %d\n", whiteFiguresNumber, blackFiguresNumber);
	return;
}

void deck::setupCheck() {
	if (deck::isWhiteMove) {
		for (unsigned i = 0; i < deck::blackFiguresNumber; i++) {
			deck::blackFigures[i]->setupSteps(deck::curentChessDeck, deck::getLastMove());
			for (unsigned j = 0; j < deck::blackFigures[i]->getStepsCount(); j++)
				if (deck::blackFigures[i]->getAllocatedSteps()[j]->getIsEat() && deck::blackFigures[i]->getAllocatedSteps()[j]->getEatenName() == 'K') {
					deck::isCheck = 1;
					return;
				}
		}
	}
	else {
		for (unsigned i = 0; i < deck::whiteFiguresNumber; i++) {
			deck::whiteFigures[i]->setupSteps(deck::curentChessDeck, deck::getLastMove());
			for (unsigned j = 0; j < deck::whiteFigures[i]->getStepsCount(); j++)
				if (deck::whiteFigures[i]->getAllocatedSteps()[j]->getIsEat() && deck::whiteFigures[i]->getAllocatedSteps()[j]->getEatenName() == 'K') {
					deck::isCheck = 1;
					return;
				}
		}
	}

	deck::isCheck = 0;
}

void deck::setupDraw() {
	if (deck::isEndGame) {
		return;
	}

	deck::isDraw = 0;

	if (deck::whiteFiguresNumber == 1 && deck::blackFiguresNumber == 1) {
		deck::isDraw = true;
		deck::isEndGame = true;
	}
	else if (deck::whiteFiguresNumber == 2 && deck::blackFiguresNumber == 1) {
		if (deck::whiteFigures[0]->getFigureName() == 'K') {
			char figureName = deck::whiteFigures[1]->getFigureName();
			if (figureName == 'N' || figureName == 'B') {
				deck::isDraw = true;
				deck::isEndGame = true;
			}
		}
		else {
			char figureName = deck::whiteFigures[0]->getFigureName();
			if (figureName == 'N' || figureName == 'B') {
				deck::isDraw = true;
				deck::isEndGame = true;
			}
		}
	}
	else if (deck::whiteFiguresNumber == 1 && deck::blackFiguresNumber == 2) {
		if (deck::blackFigures[0]->getFigureName() == 'K') {
			char figureName = deck::blackFigures[1]->getFigureName();
			if (figureName == 'N' || figureName == 'B') {
				deck::isDraw = true;
				deck::isEndGame = true;
			}
		}
		else {
			char figureName = deck::blackFigures[0]->getFigureName();
			if (figureName == 'N' || figureName == 'B') {
				deck::isDraw = true;
				deck::isEndGame = true;
			}
		}
	}
}

void deck::setupIsEndGame() {
	if (!deck::allocatedStepsNumber) {
		deck::isEndGame = true;
	}
}

bool deck::getIsCheck() {
	return deck::isCheck;
}

bool deck::getIsDraw() {
	return deck::isDraw;
}

bool deck::getIsEndGame() {
	return deck::isEndGame;
}

void deck::printDeck() {
	for (char i = 0; i < 8; i++) {
		for (char j = 0; j < 8; j++) {
			switch (deck::curentChessDeck[j][i]) {
			case 1:
				printf("P");
				break;
			case 2:
				printf("N");
				break;
			case 3:
				printf("B");
				break;
			case 4:
				printf("R");
				break;
			case 5:
				printf("Q");
				break;
			case 6:
				printf("K");
				break;
			case -1:
				printf("\033[1;31mP\033[1;0m");
				break;
			case -2:
				printf("\033[1;31mN\033[1;0m");
				break;
			case -3:
				printf("\033[1;31mB\033[1;0m");
				break;
			case -4:
				printf("\033[1;31mR\033[1;0m");
				break;
			case -5:
				printf("\033[1;31mQ\033[1;0m");
				break;
			case -6:
				printf("\033[1;31mK\033[1;0m");
				break;
			default:
				printf(".");
				break;
			}
		}
		printf("\n");
	}
}

step* deck::getBestStep() {
	deck::setupFiguresSteps();
	deck::allocFiguresSteps();
	deck::analyze();
	//step* bestStep = deck::allocatedSteps[0];
	//deck::allocatedSteps.printNotation();

	return bestStep;
}

void deck::setupCurentDeck() {
	for (char i = 0; i < 8; i++) {
		for (char j = 0; j < 8; j++) {
			deck::curentChessDeck[i][j] = 0;
		}
	}

	for (char i = 0; i < deck::whiteFiguresNumber; i++) {
		char figureNameNumber = 0;
		switch (whiteFigures[i]->getFigureName()) {
		case 'P':
			figureNameNumber = 1;
			break;
		case 'N':
			figureNameNumber = 2;
			break;
		case 'B':
			figureNameNumber = 3;
			break;
		case 'R':
			figureNameNumber = 4;
			break;
		case 'Q':
			figureNameNumber = 5;
			break;
		case 'K':
			figureNameNumber = 6;
			break;
		}
		deck::curentChessDeck[deck::whiteFigures[i]->getPosX()][deck::whiteFigures[i]->getPosY()] = figureNameNumber;
	}

	for (char i = 0; i < deck::blackFiguresNumber; i++) {
		char figureNameNumber = 0;
		switch (blackFigures[i]->getFigureName()) {
		case 'P':
			figureNameNumber = -1;
			break;
		case 'N':
			figureNameNumber = -2;
			break;
		case 'B':
			figureNameNumber = -3;
			break;
		case 'R':
			figureNameNumber = -4;
			break;
		case 'Q':
			figureNameNumber = -5;
			break;
		case 'K':
			figureNameNumber = -6;
			break;
		}
		deck::curentChessDeck[deck::blackFigures[i]->getPosX()][deck::blackFigures[i]->getPosY()] = figureNameNumber;
	}
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
