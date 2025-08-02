#pragma once
#include <queue>
#include "ICard.h"
class ITableDeck {

private:
	std::queue<ICard*> deck;

public:
	virtual void addCard(ICard* card) = 0;
	virtual std::queue<ICard*> giveAllCard() = 0;

};