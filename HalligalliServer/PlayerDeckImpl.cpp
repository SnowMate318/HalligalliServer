#include "PlayerDeckImpl.h"

PlayerDeckImpl::PlayerDeckImpl()
{
}

PlayerDeckImpl::~PlayerDeckImpl()
{
}

ICard* 
PlayerDeckImpl::giveCard()
{
	if (deck.empty()) return nullptr;
	ICard* card = deck.front();
	deck.pop();

	return card;
}

void 
PlayerDeckImpl::takeCard(ICard* card)
{
	deck.push(card);
}

int 
PlayerDeckImpl::getCardCount()
{
	return deck.size();
}

void 
PlayerDeckImpl::mergeCard(std::queue<ICard*> targetDeck)
{
	while (!targetDeck.empty()) {
		deck.push(targetDeck.front());
		targetDeck.pop();
	}
}
