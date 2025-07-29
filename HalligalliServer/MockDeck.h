#pragma once
#include "IDeck.h"
class MockDeck : public IDeck {

private:
	std::queue<ICard*> cards;

public:

	MockDeck();
	~MockDeck();

	virtual void mergeDeck(IDeck* anotherDeck)override;
	virtual void takeCard(ICard* card)override;
	virtual ICard* giveCard()override;
	virtual int getCardCount()override;
	virtual std::queue<ICard*> giveAllCards()override;
};