#pragma once
#include "figure.h"


class knight final : protected figure {
	void setupSteps(char** deck, step* lastStep) override;
};
