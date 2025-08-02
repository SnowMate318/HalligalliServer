#pragma once
#include "IFrontCards.h"
#include <vector>
#include <unordered_map>

class FrontCardsImpl : IFrontCards {

private:
	std::vector<ICard*> cards;
	std::unordered_map<Fruit, int> fruitCounts;
public:
	FrontCardsImpl(int playerCount);
	~FrontCardsImpl();
	virtual void updateCard(int playerId, ICard* card) override;
	virtual void resetCard(int playerId)override;
	virtual bool checkFiveFruit()override;
};