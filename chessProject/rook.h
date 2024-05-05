#pragma once
#include "figure.h"


class rook final : protected figure {
public:
	void setupSteps(char** deck, step* lastStep) override;
private:
	void whiteRookSetup(char** deck, step* lastStep);
	void blackRookSetup(char** deck, step* lastStep);
};
