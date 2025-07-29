#include "MockDeck.h"
#include <iostream>

MockDeck::MockDeck() {
    std::cout << "[MockDeck] ������ ȣ���" << std::endl;
}

MockDeck::~MockDeck() {
    std::cout << "[MockDeck] �Ҹ��� ȣ���" << std::endl;
}

void MockDeck::mergeDeck(IDeck* anotherDeck) {
    std::cout << "[MockDeck] mergeDeck ȣ���" << std::endl;
}

void MockDeck::takeCard(ICard* card) {
    std::cout << "[MockDeck] takeCard ȣ���" << std::endl;
}

ICard* MockDeck::giveCard() {
    std::cout << "[MockDeck] giveCard ȣ���" << std::endl;
    return nullptr;  // ����� ���� ����
}

int MockDeck::getCardCount() {
    std::cout << "[MockDeck] getCardCount ȣ���" << std::endl;
    return 0;
}

std::queue<ICard*> MockDeck::giveAllCards() {
    std::cout << "[MockDeck] giveAllCards ȣ���" << std::endl;
    return std::queue<ICard*>();  // �� ť ��ȯ
}