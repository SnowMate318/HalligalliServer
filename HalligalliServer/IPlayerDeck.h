#pragma once
#include <queue>
#include "ICard.h"
class IPlayerDeck {

private:
	std::queue<ICard*> deck;
public:
	virtual ICard* giveCard() = 0;
	virtual void takeCard(ICard* card) = 0;
	virtual int getCardCount() = 0;
	virtual void mergeCard(std::queue<ICard*> targetDeck) = 0;

};