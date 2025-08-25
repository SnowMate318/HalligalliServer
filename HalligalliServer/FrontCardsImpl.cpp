#include "FrontCardsImpl.h"
#include "Exception.h"

FrontCardsImpl::FrontCardsImpl()
{
	cards = std::unordered_map<int, ICard*>();
	fruitCounts[Fruit::APPLE] = 0;
	fruitCounts[Fruit::BANANA] = 0;
	fruitCounts[Fruit::GRAPE] = 0;
	fruitCounts[Fruit::WATERMELON] = 0;
}

FrontCardsImpl::~FrontCardsImpl()
{
}

void 
FrontCardsImpl::updateCard(int playerId, ICard* card)
{

	this->cards[playerId] = card;
	this->fruitCounts[card->getFruit()] += card->getFruitCnt();
}

void 
FrontCardsImpl::resetCard(int playerId)
{

	this->fruitCounts[this->cards[playerId]->getFruit()] -= this->cards[playerId]->getFruitCnt();
	this->cards[playerId] = nullptr;
}

bool 
FrontCardsImpl::checkFiveFruit()
{
	if (fruitCounts[Fruit::APPLE] == 5) return true;
	if (fruitCounts[Fruit::BANANA] == 5) return true;
	if (fruitCounts[Fruit::GRAPE] == 5) return true;
	if (fruitCounts[Fruit::WATERMELON] == 5) return true;

	return false;
}

ICard* FrontCardsImpl::getFrontCardById(int playerId)
{
	return nullptr;
}
