#include "stepList.h"


stepList::stepList() {
	stepList::firstStep = nullptr;
	stepList::lastStep = nullptr;
}

stepList::~stepList() {
	stepList::clear();
}

bool stepList::isEmpty() { return stepList::firstStep == nullptr; }

void stepList::pushBack(bool isWhite, char figureName, char posXFrom, char posYFrom, char posXTo, char posYTo, bool isEat, char eatenName, unsigned score) {
	step* s = new step();
	if (stepList::isEmpty()) {
		stepList::firstStep = s;
		stepList::lastStep = s;
	}
	else {
		s->setPrevStep(stepList::lastStep);
		stepList::lastStep->setNextStep(s);
		stepList::lastStep = s;
	}
}

void stepList::removeFirst() {
	if (stepList::isEmpty()) return;
	step* s = stepList::firstStep;
	stepList::firstStep = s->getNextStep();
	delete s;
}

void stepList::removeLast() {
	if (stepList::isEmpty()) return;
	if (stepList::firstStep == stepList::lastStep) {
		stepList::removeFirst();
		return;
	}
	step* s = stepList::lastStep->getPrevStep();
	s->setNextStep(nullptr);
	delete stepList::lastStep;
	stepList::lastStep = s;
}

void stepList::clear() {
	if (stepList::isEmpty()) return;
	step* buf = stepList::firstStep;
	step* toDelete;

	do {
		toDelete = buf;
		buf = toDelete->getNextStep();
		delete toDelete;
	} while (buf);

	stepList::firstStep = nullptr;
	stepList::lastStep = nullptr;
}

void stepList::printNotation() {
	if (stepList::isEmpty()) return;
	char deckChars[] = "ABCDEFGH";
	step* s = stepList::firstStep;
	for (unsigned short i = 0; i < stepList::lastStep->getStepNumber(); i++) {
		if (s->getIsWhiteStep()) {
			printf("%d. %c%c%d-%c%d",
				s->getStepNumber(),
				s->getFigureName(), deckChars[s->getPosXFrom()], s->getPosYFrom() + 1,
				deckChars[s->getPosXTo()], s->getPosYTo() + 1);
		}
		else {
			printf(" %c%c%d-%c%d  ",
				s->getFigureName(), deckChars[s->getPosXFrom()], s->getPosYFrom() + 1,
				deckChars[s->getPosXTo()], s->getPosYTo() + 1);
		}
		s = s->getNextStep();
	}
}

step* stepList::operator[](const unsigned short index) {
	if (stepList::isEmpty()) return nullptr;
	step* s = stepList::firstStep;
	for (unsigned short i = 0; i < index; i++) {
		s = s->getNextStep();
		if (!s) return nullptr;
	}
	return s;
}

step* stepList::getFirst() { return stepList::firstStep; }
step* stepList::getLast() { return stepList::lastStep; }
