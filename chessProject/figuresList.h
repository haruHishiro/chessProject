#pragma once

#include "figure.h"


class figuresList {
public:
	figuresList();
	~figuresList();

	figure* operator[] (const unsigned short index);

	char getFiguresNumber();
	figure* getFigure(unsigned short index);

	bool isEmpty();
	void addFigure(char figureName, bool isWhite, char posX, char posY);

	void removeFirst();
	void remove(const unsigned short index);
	void clear();
	void printFigures();

	figure* getFirst();
	figure* getLast();
private:
	figure* firstFigure;
};

