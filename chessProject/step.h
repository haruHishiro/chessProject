#pragma once


class step {
public:
	step();
	unsigned short getStepNumber();                      // step number
	void setStepNumber(unsigned short stepNumber);      //
	bool getIsWhiteStep();                             // white or black
	void setIsWhiteStep(bool isWhiteStep);            //
	char getFigureName();                            // figure name
	void setFigureName(char figureName);
	char getPosXFrom();
	void setPosXFrom(char posXFrom);
	char getPosYFrom();
	void setPosYFrom(char posYFrom);
	char getPosXTo();
	void setPosXTo(char posXTo);
	char getPosYTo();
	void setPosYTo(char posYTo);
	void setPosFrom(char X, char Y);
	void setPosTo(char X, char Y);
	bool getIsEat();
	void setIsEat(bool isEat);
	char getEatenName();
	void setEatenName(char eatenName);
	unsigned getScore();
	void setScore(unsigned score);
	step* getNextStep();
	void setNextStep(step* nextStep);
	step* getPrevStep();
	void setPrevStep(step* prevStep);
	char getNewFigureName();                      // only for pawn
	void setNewFigureName(char newFigureName);   // only for pawn
	bool getPwnOnLast();                        // if pawn more not pawn
	void setPwnOnLast(bool pwnOnLast);

	// for all figures
	step(char figureName, bool isWhiteStep, char fromX, char fromY, char toX, char toY, bool isEat, char eatenName);
	// only for pawn
	step(char figureName, bool isWhiteStep, char fromX, char fromY, char toX, char toY, bool isEat, char eatenName, bool pwnOnLast, char newFigureName);

private:
	unsigned short stepNumber;      // more than 255 steps?
	bool isWhiteStep;              // step side
	char figureName;              // P R N B Q K
	char posXFrom;               // 0 : 7
	char posYFrom;              // 0 : 7
	char posXTo;               // 0 : 7
	char posYTo;              // 0 : 7
	bool isEat;              // was eating
	char eatenName;         // name of eaten figure
	unsigned score;        // step's score; Mb reduce to uShort
	bool pwnOnLast;       // now this is a figure
	char newFigureName;  // name of new Figure
	step* nextStep;
	step* prevStep;
};

