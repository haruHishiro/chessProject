#pragma once
#include "figure.h"


class pawn final : protected figure {
public:
	void setupSteps(char** deck, step* lastStep) override;  // check cpp file
private:
	void whitePawnSetup(char** deck, step* lastStep);
	void blackPawnSetup(char** deck, step* lastStep);
};
