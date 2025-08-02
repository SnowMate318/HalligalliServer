#include "TableDeckImpl.h"

TableDeckImpl::TableDeckImpl()
{
}

TableDeckImpl::~TableDeckImpl()
{
}

void 
TableDeckImpl::addCard(ICard* card)  
{  
    deck.push(card);
}

std::queue<ICard*> 
TableDeckImpl::giveAllCard()
{
    std::queue<ICard*> ret = this->deck;
    while (!this->deck.empty()) {
        this->deck.pop();
    }
    return ret;
}
