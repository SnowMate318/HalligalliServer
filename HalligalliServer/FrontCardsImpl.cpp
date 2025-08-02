#include "FrontCardsImpl.h"
#include "Exception.h"
FrontCardsImpl::FrontCardsImpl(int playerCount)
{
	cards = std::vector<ICard*>(playerCount, nullptr);
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
	if (playerId >= cards.size()) {
		throw Exception("잘못된 인덱스 오류");
	}

	this->cards[playerId] = card;
	this->fruitCounts[card->getFruit()] += card->getFruitCnt();
}

void 
FrontCardsImpl::resetCard(int playerId)
{

	if (playerId >= cards.size()) {
		throw Exception("잘못된 인덱스 오류");
	}

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
