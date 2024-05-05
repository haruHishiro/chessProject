#pragma once
#include "figure.h"


class bishop final : protected figure {
public:
	void setupSteps(char** deck, step* lastStep) override;
private:
	void whiteBishopSetup(char** deck, step* lastStep);
	void blackBishopSetup(char** deck, step* lastStep);
};
