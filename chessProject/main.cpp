#define _CRT_SECURE_NO_WARNINGS

#include "deck.h"
#include <stdlib.h>


step* createMove(char mass[6], deck* chessDeck) {
	char figureName, fromX, fromY, toX, toY, eatenName = 'Z';
	bool isWhiteStep, isEat = 0;
	char str[8] = { 7,6,5,4,3,2,1,0 };
	if (mass[0] == 'P' || mass[0] == 'B' || mass[0] == 'N' || mass[0] == 'R' || mass[0] == 'Q' || mass[0] == 'K')
		figureName = mass[0];
	if (mass[1] >= 'a' && mass[1] <= 'h')
		fromX = mass[1] - 'a';
	if (mass[2] >= '1' && mass[2] <= '8')
		fromY = str[mass[2] - '1'];
	if (mass[3] >= 'a' && mass[3] <= 'h')
		toX = mass[3] - 'a';
	if (mass[4] >= '1' && mass[4] <= '8')
		toY = str[mass[4] - '1'];
	isWhiteStep = chessDeck->getIsWhiteMove();
	if (isWhiteStep) {
		figuresList* blackFigures = chessDeck->getBlackFiguresList();
		for (char i = 0; i < blackFigures->getFiguresNumber(); i++) {
			if (blackFigures->getFigure(i)->getPosX() == toX && blackFigures->getFigure(i)->getPosY() == toY) {
				isEat = true;
				eatenName = blackFigures->getFigure(i)->getFigureName();
				break;
			}
		}
	}
	else {
		figuresList* whiteFigures = chessDeck->getWhiteFiguresList();
		for (char i = 0; i < whiteFigures->getFiguresNumber(); i++) {
			if (whiteFigures->getFigure(i)->getPosX() == toX && whiteFigures->getFigure(i)->getPosY() == toY) {
				isEat = true;
				eatenName = whiteFigures->getFigure(i)->getFigureName();
				break;
			}
		}
	}
	step* returned = new step(figureName, isWhiteStep, fromX, fromY, toX, toY, isEat, eatenName);
	return returned;
}

bool check(char mass[6]) {
	if (mass[0] == 'P' || mass[0] == 'B' || mass[0] == 'N' || mass[0] == 'R' || mass[0] == 'Q' || mass[0] == 'K')
		if (mass[1] >= 'a' && mass[1] <= 'h')
			if (mass[2] >= '1' && mass[2] <= '8')
				if (mass[3] >= 'a' && mass[3] <= 'h')
					if (mass[4] >= '1' && mass[4] <= '8')
						return true;
	return false;
}

int main() {
	// branch init
	deck* chessDeck = new deck(1);

	chessDeck->setupStartPosition();
	chessDeck->setBotSide(false);

	if (chessDeck->getBotSide()) {
		chessDeck->doMove(chessDeck->getBestStep());
	}

	step* userStep;
	char tmp[6];

	while (!chessDeck->getIsEndGame()) {
		do {
			do {
				system("cls");
				chessDeck->printDeck();
				printf("you can play:\n");

				chessDeck->printValidSteps();
				printf("enter your move: ");
				scanf("%s", tmp);
			} while (!check(tmp));

			userStep = createMove(tmp, chessDeck);
		} while (!(chessDeck->IsValidMove(userStep)));

		chessDeck->doMove(userStep);
		system("cls");
		chessDeck->printDeck();
		chessDeck->doMove(chessDeck->getBestStep());
	}

	return 0;
}