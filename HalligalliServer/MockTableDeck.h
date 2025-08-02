#pragma once
#include "ITableDeck.h"

class MockTableDeck : public ITableDeck {

private:
	std::queue<ICard*> deck;
public:

	MockTableDeck();
	~MockTableDeck();

	virtual void addCard(ICard* card)override;
	virtual std::queue<ICard*> giveAllCard()override;
	bool isDeckEmpty();

}; 
