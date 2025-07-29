#pragma once
#include "IDeck.h"

class DeckImpl : IDeck {
	virtual void mergeDeck(std::vector<IDeck> deck)override;
	virtual void takeCard(ICard card)override;
	virtual ICard giveCard()override;
	virtual int getCardCount()override;
	virtual ICard getDeckTopCard()override;
};