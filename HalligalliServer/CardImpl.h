#pragma once
#include "ICard.h"

class CardImpl : ICard {
private:
	enum fruit;

public:
	virtual int getCardNum()override;
};