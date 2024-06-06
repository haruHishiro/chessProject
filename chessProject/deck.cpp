#include "deck.h"


deck::deck(unsigned char difficulty) {
	deck::whiteFigures = new figuresList;
	deck::blackFigures = new figuresList;

	deck::notation = new stepList;

	deck::difficulty = difficulty;
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
	delete deck::whiteFigures;
	delete deck::blackFigures;

	delete notation;

	for (char i = 0; i < 8; i++) {
		if (deck::curentChessDeck[i] != nullptr) delete deck::curentChessDeck[i];
	}
	if (deck::curentChessDeck != nullptr) delete[] deck::curentChessDeck;
}

void deck::setupStartPosition() {
	deck::whiteFigures->addFigure('P', true, 0, 6);
	deck::whiteFigures->addFigure('P', true, 1, 6);
	deck::whiteFigures->addFigure('P', true, 2, 6);
	deck::whiteFigures->addFigure('P', true, 3, 6);
	deck::whiteFigures->addFigure('P', true, 4, 6);
	deck::whiteFigures->addFigure('P', true, 5, 6);
	deck::whiteFigures->addFigure('P', true, 6, 6);
	deck::whiteFigures->addFigure('P', true, 7, 6);

	deck::whiteFigures->addFigure('R', true, 0, 7);
	deck::whiteFigures->addFigure('N', true, 1, 7);
	deck::whiteFigures->addFigure('B', true, 2, 7);
	deck::whiteFigures->addFigure('Q', true, 3, 7);
	deck::whiteFigures->addFigure('K', true, 4, 7);
	deck::whiteFigures->addFigure('B', true, 5, 7);
	deck::whiteFigures->addFigure('N', true, 6, 7);
	deck::whiteFigures->addFigure('R', true, 7, 7);

	deck::whiteFiguresNumber = deck::whiteFigures->getFiguresNumber();

	deck::blackFigures->addFigure('P', false, 0, 1);
	deck::blackFigures->addFigure('P', false, 1, 1);
	deck::blackFigures->addFigure('P', false, 2, 1);
	deck::blackFigures->addFigure('P', false, 3, 1);
	deck::blackFigures->addFigure('P', false, 4, 1);
	deck::blackFigures->addFigure('P', false, 5, 1);
	deck::blackFigures->addFigure('P', false, 6, 1);
	deck::blackFigures->addFigure('P', false, 7, 1);

	deck::blackFigures->addFigure('R', false, 0, 0);
	deck::blackFigures->addFigure('N', false, 1, 0);
	deck::blackFigures->addFigure('B', false, 2, 0);
	deck::blackFigures->addFigure('Q', false, 3, 0);
	deck::blackFigures->addFigure('K', false, 4, 0);
	deck::blackFigures->addFigure('B', false, 5, 0);
	deck::blackFigures->addFigure('N', false, 6, 0);
	deck::blackFigures->addFigure('R', false, 7, 0);

	deck::blackFiguresNumber = deck::blackFigures->getFiguresNumber();

	deck::setupCurentDeck();
}

void deck::doMove(step* move) {
	//move->printStep();
	// writing move into notation
	deck::notation->pushBack(move);

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
				if (deck::blackFigures->getFigure(i)->getFigureName() == eatenName
					&& move->getPosXTo() == deck::blackFigures->getFigure(i)->getPosX()
					&& move->getPosYTo() == deck::blackFigures->getFigure(i)->getPosY()) {
					deck::blackFigures->remove(i);
					deck::blackFiguresNumber--;
				}
			}
		}
		else {
			for (char i = 0; i < deck::whiteFiguresNumber; i++) {
				if (deck::whiteFigures->getFigure(i)->getFigureName() == eatenName
					&& move->getPosXTo() == deck::whiteFigures->getFigure(i)->getPosX()
					&& move->getPosYTo() == deck::whiteFigures->getFigure(i)->getPosY()) {
					deck::whiteFigures->remove(i);
					deck::whiteFiguresNumber--;
				}
			}
		}
	}

	// update figures positions
	if (deck::isWhiteMove) {
		for (char i = 0; i < deck::whiteFiguresNumber; i++) {
			if (move->getPosXFrom() == deck::whiteFigures->getFigure(i)->getPosX()
				&& move->getPosYFrom() == deck::whiteFigures->getFigure(i)->getPosY()) {
				deck::whiteFigures->getFigure(i)->setPosX(move->getPosXTo());
				deck::whiteFigures->getFigure(i)->setPosY(move->getPosYTo());
			}
		}
	}
	else {
		for (char i = 0; i < deck::blackFiguresNumber; i++) {
			if (move->getPosXFrom() == deck::blackFigures->getFigure(i)->getPosX()
				&& move->getPosYFrom() == deck::blackFigures->getFigure(i)->getPosY()) {
				deck::blackFigures->getFigure(i)->setPosX(move->getPosXTo());
				deck::blackFigures->getFigure(i)->setPosY(move->getPosYTo());
			}
		}
	}

	// switch move
	deck::isWhiteMove = !deck::isWhiteMove;

	deck::allocatedSteps.clear();
}

bool deck::isCorrectMove(step* move) {
	//printf("here\n");
	//move->printStep();
	//printf("\n");

	bool retFlag;
	deck* breanch = new deck(deck::difficulty);
	breanch->setFigures(deck::whiteFigures, deck::whiteFigures);
	
	breanch->setNotation(deck::notation);
	breanch->setPosition(deck::curentChessDeck);
	breanch->setIsWhiteMove(deck::isWhiteMove);

	breanch->doMove(move);
	//breanch->printDeck();
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
	char** tempDeck;
	tempDeck = new char* [8];
	for (char i = 0; i < 8; i++) {
		tempDeck[i] = new char[8];
	}

	for (char i = 0; i < 8; i++) {
		for (char j = 0; j < 8; j++) {
			tempDeck[i][j] = 0;
		}
	}

	// prepare part
	for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
		deck::blackFigures->getFigure(i)->setupSteps(deck::curentChessDeck, notation->getLast());
		tempDeck[blackFigures->getFigure(i)->getPosX()][blackFigures->getFigure(i)->getPosY()] -= 64;
		for (unsigned char j = 0; j < deck::blackFigures->getFigure(i)->getStepsCount(); j++) {
			char X = blackFigures->getFigure(i)->getAllocatedSteps()[j]->getPosXTo();
			char Y = blackFigures->getFigure(i)->getAllocatedSteps()[j]->getPosYTo();
			tempDeck[X][Y]--;
		}
	}

	for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
		deck::whiteFigures->getFigure(i)->setupSteps(deck::curentChessDeck, notation->getLast());
		tempDeck[whiteFigures->getFigure(i)->getPosX()][whiteFigures->getFigure(i)->getPosY()] += 64;
		for (unsigned char j = 0; j < deck::whiteFigures->getFigure(i)->getStepsCount(); j++) {
			char X = whiteFigures->getFigure(i)->getAllocatedSteps()[j]->getPosXTo();
			char Y = whiteFigures->getFigure(i)->getAllocatedSteps()[j]->getPosYTo();
			tempDeck[X][Y]++;
		}
	}

	// scoring part
	int score = 0;
	char field_control_k = 10;

	for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
		score += deck::whiteFigures->getFigure(i)->getCost();
	}

	for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
		score += deck::blackFigures->getFigure(i)->getCost();
	}

	for (char i = 0; i < 8; i++) {
		for (char j = 0; j < 8; j++) {
			if (tempDeck[i][j] > 0) {
				score += field_control_k;
			}
			else if (tempDeck[i][j] < 0) {
				score -= field_control_k;
			}
		}
	}

	// clean
	for (char i = 0; i < 8; i++) {
		if (tempDeck[i] != nullptr) delete tempDeck[i];
	}
	if (tempDeck != nullptr) delete[] tempDeck;

	return score;
}

void deck::setupFiguresSteps() {
	// all steps initiation
	if (deck::isWhiteMove) {
		for (unsigned char i = 0; i < deck::whiteFiguresNumber; i++) {
			//deck::printDeck();
			deck::whiteFigures->getFigure(i)->setupSteps(deck::curentChessDeck, notation->getLast());
			//printf("%d:%c->",i, deck::whiteFigures[i]->getFigureName());
			//deck::whiteFigures[i]->printSteps();
			//printf("\n");
		}
	}
	else {
		for (unsigned char i = 0; i < deck::blackFiguresNumber; i++) {
			deck::blackFigures->getFigure(i)->setupSteps(deck::curentChessDeck, notation->getLast());
		}
	}
}

void deck::allocFiguresSteps() {
	deck::setupCheck();

	deck::allocatedStepsNumber = 0;
	if (deck::isWhiteMove) {
		for (unsigned i = 0; i < deck::whiteFiguresNumber; i++) {
			step** figureSteps = deck::whiteFigures->getFigure(i)->getAllocatedSteps();
			for (unsigned j = 0; j < deck::whiteFigures->getFigure(i)->getStepsCount(); j++) {
				if (isCorrectMove(figureSteps[j])) {
					deck::allocatedSteps.pushBack(figureSteps[j]);
					deck::allocatedStepsNumber++;
				}
			}
		}
	}
	else {
		for (unsigned i = 0; i < deck::blackFiguresNumber; i++) {
			step** figureSteps = deck::blackFigures->getFigure(i)->getAllocatedSteps();
			for (unsigned j = 0; j < deck::blackFigures->getFigure(i)->getStepsCount(); j++) {
				if (isCorrectMove(figureSteps[j])) {
					deck::allocatedSteps.pushBack(figureSteps[j]);
					deck::allocatedStepsNumber++;
				}
			}
		}
	}
}

void deck::newAnalize(char _curent, char _max) {
	deck::curentDeep = _curent;
	//printf("%d %d\n", deck::curentDeep, _max);
	//deck::printDeck();
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
		return;
	}

	if (deck::curentDeep == _max) {
		deck::bestStep = deck::notation->getLast();
		deck::positionScore = deck::getPositionScore();
		//deck::printDeck();
		return;
	}

	deck::deckTree = new deck * [deck::allocatedStepsNumber];

	unsigned short i = 0;

	for (unsigned short i = 0; i < deck::allocatedStepsNumber; i++) {
		//printf("step %d from %d \n",i, deck::allocatedStepsNumber);
		deck::deckTree[i] = new deck(deck::difficulty);
		deck::deckTree[i]->setIsWhiteMove(deck::isWhiteMove);
		deck::deckTree[i]->setFigures(deck::whiteFigures, deck::blackFigures);
		deck::deckTree[i]->setPosition(deck::curentChessDeck);
		deck::deckTree[i]->doMove(deck::allocatedSteps[i]);
		deck::deckTree[i]->setupFiguresSteps();
		deck::deckTree[i]->allocFiguresSteps();
		deck::deckTree[i]->newAnalize(deck::curentDeep + 1, deck::difficulty);
	}
	
	deck::bestStep = new step(
		deck::allocatedSteps[0]->getFigureName(),
		deck::allocatedSteps[0]->getIsWhiteStep(),
		deck::allocatedSteps[0]->getPosXFrom(), deck::allocatedSteps[0]->getPosYFrom(),
		deck::allocatedSteps[0]->getPosXTo(), deck::allocatedSteps[0]->getPosYTo(),
		deck::allocatedSteps[0]->getIsEat(), deck::allocatedSteps[0]->getEatenName(),
		deck::allocatedSteps[0]->getPwnOnLast(), deck::allocatedSteps[0]->getNewFigureName());
	deck::positionScore = deckTree[0]->getPositionScore();
	if (deck::isWhiteMove) {
		for (unsigned short i = 1; i < deck::allocatedStepsNumber; i++) {
			if (deckTree[i]->getPositionScore() > deck::positionScore) {
				deck::bestStep = new step(
					deck::allocatedSteps[i]->getFigureName(),
					deck::allocatedSteps[i]->getIsWhiteStep(),
					deck::allocatedSteps[i]->getPosXFrom(), deck::allocatedSteps[i]->getPosYFrom(),
					deck::allocatedSteps[i]->getPosXTo(), deck::allocatedSteps[i]->getPosYTo(),
					deck::allocatedSteps[i]->getIsEat(), deck::allocatedSteps[i]->getEatenName(),
					deck::allocatedSteps[i]->getPwnOnLast(), deck::allocatedSteps[i]->getNewFigureName());

				deck::positionScore = deckTree[i]->getPositionScore();
			}
		}
	}
	else {
		for (unsigned short i = 1; i < deck::allocatedStepsNumber; i++) {
			if (deckTree[i]->getPositionScore() < deck::positionScore) {
				deck::bestStep = new step(
					deck::allocatedSteps[i]->getFigureName(),
					deck::allocatedSteps[i]->getIsWhiteStep(),
					deck::allocatedSteps[i]->getPosXFrom(), deck::allocatedSteps[i]->getPosYFrom(),
					deck::allocatedSteps[i]->getPosXTo(), deck::allocatedSteps[i]->getPosYTo(),
					deck::allocatedSteps[i]->getIsEat(), deck::allocatedSteps[i]->getEatenName(),
					deck::allocatedSteps[i]->getPwnOnLast(), deck::allocatedSteps[i]->getNewFigureName());
				
				deck::positionScore = deckTree[i]->getPositionScore();
			}
		}
	}

	for (unsigned short i = 0; i < deck::allocatedStepsNumber; i++) {
		delete deckTree[i];
	}
	
	return;
}

void deck::newAnalize() {
	deck::newAnalize(0, difficulty);
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

void deck::setNotation(stepList* notation) {
	step* s = notation->getFirst();

	while (s) {
		deck::notation->pushBack(s);
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

void deck::setFigures(figuresList* whiteFigures, figuresList* blackFigures) {
	//printf("here 0\n");
	for (unsigned short i = 0; i < whiteFigures->getFiguresNumber(); i++) {
		deck::whiteFigures->addFigure(whiteFigures->getFigure(i)->getFigureName(), whiteFigures->getFigure(i)->getIsWhite(),
			whiteFigures->getFigure(i)->getPosX(), whiteFigures->getFigure(i)->getPosY());
	}
	//printf("here 1\n");
	for (unsigned short i = 0; i < blackFigures->getFiguresNumber(); i++) {
		deck::blackFigures->addFigure(blackFigures->getFigure(i)->getFigureName(), blackFigures->getFigure(i)->getIsWhite(),
			blackFigures->getFigure(i)->getPosX(), blackFigures->getFigure(i)->getPosY());
	}
	//printf("here 2\n");
	deck::whiteFiguresNumber = deck::whiteFigures->getFiguresNumber();
	deck::blackFiguresNumber = deck::blackFigures->getFiguresNumber();
	//printf("here 3\n");
	//printf("%d %d\n", whiteFiguresNumber, blackFiguresNumber);
}

void deck::setupCheck() {
	if (deck::isWhiteMove) {
		for (unsigned i = 0; i < deck::blackFiguresNumber; i++) {
			deck::blackFigures->getFigure(i)->setupSteps(deck::curentChessDeck, deck::getLast());
			for (unsigned j = 0; j < deck::blackFigures->getFigure(i)->getStepsCount(); j++)
				if (deck::blackFigures->getFigure(i)->getAllocatedSteps()[j]->getIsEat() && deck::blackFigures->getFigure(i)->getAllocatedSteps()[j]->getEatenName() == 'K') {
					deck::isCheck = 1;
					return;
				}
		}
	}
	else {
		for (unsigned i = 0; i < deck::whiteFiguresNumber; i++) {
			deck::whiteFigures->getFigure(i)->setupSteps(deck::curentChessDeck, deck::getLast());
			for (unsigned j = 0; j < deck::whiteFigures->getFigure(i)->getStepsCount(); j++)
				if (deck::whiteFigures->getFigure(i)->getAllocatedSteps()[j]->getIsEat() && deck::whiteFigures->getFigure(i)->getAllocatedSteps()[j]->getEatenName() == 'K') {
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
		if (deck::whiteFigures->getFigure(0)->getFigureName() == 'K') {
			char figureName = deck::whiteFigures->getFigure(1)->getFigureName();
			if (figureName == 'N' || figureName == 'B') {
				deck::isDraw = true;
				deck::isEndGame = true;
			}
		}
		else {
			char figureName = deck::whiteFigures->getFigure(0)->getFigureName();
			if (figureName == 'N' || figureName == 'B') {
				deck::isDraw = true;
				deck::isEndGame = true;
			}
		}
	}
	else if (deck::whiteFiguresNumber == 1 && deck::blackFiguresNumber == 2) {
		if (deck::blackFigures->getFigure(0)->getFigureName() == 'K') {
			char figureName = deck::blackFigures->getFigure(1)->getFigureName();
			if (figureName == 'N' || figureName == 'B') {
				deck::isDraw = true;
				deck::isEndGame = true;
			}
		}
		else {
			char figureName = deck::blackFigures->getFigure(0)->getFigureName();
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

void deck::printNotation() {
	deck::notation->printNotation();
}

step* deck::getLast() {
	return deck::notation->getLast();
}

step* deck::getBestStep() {
	deck::allocatedSteps.clear();

	deck::setupFiguresSteps();
	deck::allocFiguresSteps();
	deck::newAnalize();

	printf("pos score %d\n", deck::positionScore);
	bestStep->printStep();

	return deck::bestStep;
}

step* deck::getBestStepMove() {
	//deck::bestStep->printStep();
	return deck::bestStep;
}

void deck::setBestStep(step* best) {
	deck::bestStep = best;
}

bool deck::getIsWhiteMove() {
	return deck::isWhiteMove;
}

figuresList* deck::getBlackFiguresList() {
	return deck::blackFigures;
}

figuresList* deck::getWhiteFiguresList() {
	return deck::whiteFigures;
}

bool deck::IsValidMove(step* move) {
	deck::setupFiguresSteps();
	deck::allocFiguresSteps();

	for (short i = 0; i < deck::allocatedStepsNumber; i++) {
		if (move->getPosXFrom() == deck::allocatedSteps[i]->getPosXFrom() && move->getPosYFrom() == deck::allocatedSteps[i]->getPosYFrom() &&
			move->getPosXTo() == deck::allocatedSteps[i]->getPosXTo() && move->getPosYTo() == deck::allocatedSteps[i]->getPosYTo() &&
			move->getFigureName() == deck::allocatedSteps[i]->getFigureName()) {
			return true;
		}
	}

	return false;
}

void deck::setBotSide(bool side) {
	deck::botSideIsWhite = side;
}

bool deck::getBotSide() {
	return deck::botSideIsWhite;
}

void deck::printValidSteps() {
	deck::setupFiguresSteps();
	deck::allocFiguresSteps();

	for (short i = 0; i < deck::allocatedStepsNumber; i++) {
		deck::allocatedSteps[i]->printStep();
	}
}

void deck::setupCurentDeck() {
	for (char i = 0; i < 8; i++) {
		for (char j = 0; j < 8; j++) {
			deck::curentChessDeck[i][j] = 0;
		}
	}

	for (char i = 0; i < deck::whiteFiguresNumber; i++) {
		char figureNameNumber = 0;
		switch (whiteFigures->getFigure(i)->getFigureName()) {
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
		deck::curentChessDeck[deck::whiteFigures->getFigure(i)->getPosX()][deck::whiteFigures->getFigure(i)->getPosY()] = figureNameNumber;
	}

	for (char i = 0; i < deck::blackFiguresNumber; i++) {
		char figureNameNumber = 0;
		switch (blackFigures->getFigure(i)->getFigureName()) {
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
		deck::curentChessDeck[deck::blackFigures->getFigure(i)->getPosX()][deck::blackFigures->getFigure(i)->getPosY()] = figureNameNumber;
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
