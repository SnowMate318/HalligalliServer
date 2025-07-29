#pragma once
#include "ICard.h"

class CardImpl : ICard {
private:
	Fruit fruit;
	int fruit_cnt;

public:
	CardImpl(int card_num);
	~CardImpl();
	virtual int getCardNum()override;
};