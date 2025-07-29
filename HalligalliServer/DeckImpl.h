#pragma once
#include "IDeck.h"
class DeckImpl : IDeck {

private:
	std::queue<ICard*> cards;

public:
	
	DeckImpl() {};
	~DeckImpl() {};

	virtual void mergeDeck(IDeck* anotherDeck)override;
	virtual void takeCard(ICard* card)override;
	virtual ICard* giveCard()override;
	virtual int getCardCount()override;
	virtual std::queue<ICard*> getCards()override;
};