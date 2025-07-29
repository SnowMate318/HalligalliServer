#pragma once
#include "ICard.h"

class CardImpl : ICard {
private:
	Fruit fruit;
	int fruit_cnt;
	int card_num;

public:
	CardImpl(int card_num);
	~CardImpl();
	virtual Fruit getFruit()override;
	virtual int getFruitCnt()override;
	virtual int getCardNum()override;
};