#pragma once
#include <queue>
#include "IPlayerDeck.h"
class PlayerDeckImpl : public IPlayerDeck {

private:
	std::queue<ICard*> deck;
public:
	PlayerDeckImpl();
	~PlayerDeckImpl();

	virtual ICard* giveCard()override;
	virtual void takeCard(ICard* card)override;
	virtual int getCardCount()override;
	virtual void mergeCard(std::queue<ICard*> targetDeck)override;

};