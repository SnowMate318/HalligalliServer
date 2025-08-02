#pragma once
#include "ITableDeck.h"

class TableDeckImpl : public ITableDeck {

private:
	std::queue<ICard*> deck;
public:

	TableDeckImpl();
	~TableDeckImpl();

	virtual void addCard(ICard* card)override;
	virtual std::queue<ICard*> giveAllCard()override;

};