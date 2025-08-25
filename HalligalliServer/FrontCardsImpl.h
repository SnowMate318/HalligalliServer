#pragma once
#include "IFrontCards.h"
#include <vector>
#include <unordered_map>

class FrontCardsImpl : public IFrontCards {

private:
	std::unordered_map<int,ICard*> cards;
	std::unordered_map<Fruit, int> fruitCounts;
public:
	FrontCardsImpl();
	~FrontCardsImpl();
	virtual void updateCard(int playerId, ICard* card) override;
	virtual void resetCard(int playerId)override;
	virtual bool checkFiveFruit()override;
	virtual ICard* getFrontCardById(int playerId)override;
};