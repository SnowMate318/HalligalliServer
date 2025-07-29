#pragma once
#include "Fruit.h"
class ICard {
private:
	Fruit fruit;
	int fruit_cnt;
public:

	virtual Fruit getFruit() = 0;
	virtual int getFruitCnt() = 0;
	virtual int getCardNum() = 0;

};