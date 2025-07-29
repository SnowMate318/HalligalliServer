#include "DeckImpl.h"

DeckImpl::DeckImpl() {

}
DeckImpl::~DeckImpl() {

}

void
DeckImpl::mergeDeck(IDeck* anotherDeck) {
	std::queue<ICard*> deck = anotherDeck->giveAllCards();
	
	while (!deck.empty()) {
		this->cards.push(deck.front());
		deck.pop();
	}
}

void
DeckImpl::takeCard(ICard* card) {
	if (card == nullptr) return; // 카드를 주려는 상대가 카드를 모두 소진한 경우
	this->cards.push(card);
}

ICard*
DeckImpl::giveCard() {

	if (this->cards.empty()) {
		return nullptr;
	}
	ICard* front = this->cards.front();
	this->cards.pop();
	return front;
}

int
DeckImpl::getCardCount() {
	return this->cards.size();
}

std::queue<ICard*>
DeckImpl::giveAllCards() {
	std::queue<ICard*> ret = this->cards;
	this->cards = std::queue<ICard*>();
	return ret;
}