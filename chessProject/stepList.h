#pragma once

#include "step.h"
#include <stdio.h>


class stepList {
public:
	stepList();
	~stepList();
	bool isEmpty();
	void pushBack(bool isWhite, char figureName, char posXFrom, char posYFrom, char posXTo, char posYTo, bool isEat, char eatenName, unsigned score, bool pwnOnLast, char newFigureName);
	void pushBack(step* s);
	void removeFirst();
	void removeLast();
	void clear();
	void printNotation();

	step* operator[] (const unsigned short index);
	step* getFirst();
	step* getLast();
private:
	step* firstStep;
	step* lastStep;
};

