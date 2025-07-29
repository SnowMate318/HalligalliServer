#pragma once
#include <queue>
#include "ICard.h"
class IDeck {
private:
	std::queue<ICard*> cards;
public:
	virtual void mergeDeck(IDeck* anotherDeck) = 0;
	virtual void takeCard(ICard* card) = 0;
	virtual ICard* giveCard() = 0;
	virtual int getCardCount() = 0;
	virtual std::queue<ICard*> giveAllCards() = 0;

};

