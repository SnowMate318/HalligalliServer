#include "MockDeck.h"
#include <iostream>

MockDeck::MockDeck() {
    std::cout << "[MockDeck] »ý¼ºÀÚ È£ÃâµÊ" << std::endl;
}

MockDeck::~MockDeck() {
    std::cout << "[MockDeck] ¼Ò¸êÀÚ È£ÃâµÊ" << std::endl;
}

void MockDeck::mergeDeck(IDeck* anotherDeck) {
    std::cout << "[MockDeck] mergeDeck È£ÃâµÊ" << std::endl;
}

void MockDeck::takeCard(ICard* card) {
    std::cout << "[MockDeck] takeCard È£ÃâµÊ" << std::endl;
}

ICard* MockDeck::giveCard() {
    std::cout << "[MockDeck] giveCard È£ÃâµÊ" << std::endl;
    return nullptr;  // ±â´ÉÀº ÇÏÁö ¾ÊÀ½
}

int MockDeck::getCardCount() {
    std::cout << "[MockDeck] getCardCount È£ÃâµÊ" << std::endl;
    return 0;
}

std::queue<ICard*> MockDeck::giveAllCards() {
    std::cout << "[MockDeck] giveAllCards È£ÃâµÊ" << std::endl;
    return std::queue<ICard*>();  // ºó Å¥ ¹ÝÈ¯
}