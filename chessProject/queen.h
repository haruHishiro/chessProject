#pragma once
#include "figure.h"


class queen final : protected figure {
public:
	void setupSteps(char** deck, step* lastStep) override;
private:
	void whiteQueenSetup(char** deck, step* lastStep);
	void blackQueenSetup(char** deck, step* lastStep);
};
