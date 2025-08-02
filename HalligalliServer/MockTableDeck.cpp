#include "MockTableDeck.h"

MockTableDeck::MockTableDeck()
{
}

MockTableDeck::~MockTableDeck()
{
}

void
MockTableDeck::addCard(ICard* card)
{
    deck.push(card);
}

std::queue<ICard*>
MockTableDeck::giveAllCard()
{
    std::queue<ICard*> ret = this->deck;
    while (!this->deck.empty()) {
        this->deck.pop();
    }
    return ret;
}

bool MockTableDeck::isDeckEmpty()
{
    return this->deck.empty();
}
