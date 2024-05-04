#pragma once
#include "figure.h"


class pawn final : protected figure {
public:
	void setupSteps(char** deck, step* lastStep) override;  // check cpp file
};
