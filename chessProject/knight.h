#pragma once
#include "figure.h"


class knight final : protected figure {
public:
	void setupSteps(char** deck, step* lastStep) override;
private:
	void whiteKnightSetup(char** deck, step* lastStep);
	void blackKnightSetup(char** deck, step* lastStep);
};
