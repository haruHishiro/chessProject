#pragma once
#include "figure.h"


class king final : protected figure {
public:
	void setupSteps(char** deck, step* lastStep) override;
private:
	void whiteKingSetup(char** deck, step* lastStep);
	void blackKingSetup(char** deck, step* lastStep);
};
