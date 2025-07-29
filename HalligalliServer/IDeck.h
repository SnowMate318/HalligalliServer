#pragma once
#include <vector>
#include "ICard.h"
class IDeck {
	
	virtual void mergeDeck(std::vector<IDeck> deck) = 0;
	virtual void takeCard(ICard card) = 0;
	virtual ICard giveCard() = 0;
	virtual int getCardCount() = 0;
	virtual ICard getDeckTopCard() = 0;

};

