#pragma once
#include "Fruit.h"
class ICard {
private:
	Fruit fruit;
	int fruit_cnt;
public:
	virtual int getCardNum() = 0;

};