#pragma once
#include <random>
#include "TableCardsImpl.h"
#include "DeckImpl.h"
#include "CardImpl.h"
#include "GameMessage.h"

TableCardsImpl::TableCardsImpl(int player_count)
{
	initTable(player_count);
	initDeck(player_count);
}

TableCardsImpl::~TableCardsImpl()
{
	for (int i = 0; i < player_count; i++) {
		while (playerDecks[i]->getCardCount() != 0) {
			ICard* card = playerDecks[i]->giveCard();
			delete card;
		}
		delete playerDecks[i];
	}
	while (tableDeck->getCardCount() != 0) {
		ICard* card = tableDeck->giveCard();
		delete card;
	}
	delete tableDeck;
}


void
TableCardsImpl::initTable(int player_count)
{
	this->player_count = player_count;
    this->playerDecks = std::vector<IDeck*>(player_count);
	this->activate = std::vector<bool>(player_count, true);

	for (int i = 0; i < player_count; i++) {
		playerDecks[i] = new DeckImpl(); // new 키워드로 생성 책임 부여
	}
	this->tableDeck = new DeckImpl(); // new 키워드로 생성 책임 부여

	numbersOfEachFruit[Fruit::APPLE] = 0;
	numbersOfEachFruit[Fruit::BANANA] = 0;
	numbersOfEachFruit[Fruit::GRAPE] = 0;
	numbersOfEachFruit[Fruit::WATERMELON] = 0;

	this->current_turn_player = 0;
}

void
TableCardsImpl::initDeck(int player_count) {
	int number_of_cards_per_number_of_fruits[20] = { 5,4,3,1,1,5,4,3,1,1,5,4,3,1,1,5,4,3,1,1 }; // 카드번호 별 카드 갯수

	std::vector<ICard*> cards(56);
	int idx = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < number_of_cards_per_number_of_fruits[i]; j++) {
			cards[idx++] = new CardImpl(i);
		}
	}

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(cards.begin(), cards.end(), g); // 카드 섞기

	int player_idx = 0;
	for (int i = 0; i < 56; i++) {
		this->playerDecks[player_idx]->takeCard(cards[i]);
		player_idx = (player_idx + 1) % player_count;
	}
}

bool 
TableCardsImpl::checkFrontCardCount()
{
	Fruit fruits[4] = {
		Fruit::APPLE,
		Fruit::BANANA,
		Fruit::GRAPE,
		Fruit::WATERMELON
	};

	for (int i = 0; i < 4; i++) {
		if (numbersOfEachFruit[fruits[i]] == 5) {
			return true;
		}
	}
	return false;
}

void 
TableCardsImpl::playCard(int playerId)
{
	int next_turn_player = (current_turn_player + 1) % player_count;

	if (playerDecks[playerId]->getCardCount() == 0) {
		notifyPlayerDie(playerId, next_turn_player); // 테이블에게 플레이어 죽은 정보 전달
		current_turn_player = next_turn_player;
		return;
	}

	ICard* card = playerDecks[playerId]->giveCard();
	frontCards[playerId] = card;
	tableDeck->takeCard(card);

	if (checkFrontCardCount()) {
		notifyBellActivate(next_turn_player); // 벨 활성화 정보 전달
		current_turn_player = next_turn_player;
		return;
	}
	
	notifyNextTurn(next_turn_player);
	current_turn_player = next_turn_player;
}

void 
TableCardsImpl::processPenalty(int playerId)
{
	int idx = (playerId + 1) % player_count;
	for (int i = 0; i < player_count-1; i++) {
		if (!activate[idx]) continue;
		ICard* card = playerDecks[playerId]->giveCard();


		if (card == nullptr) {
			if (playerId == current_turn_player) {
				current_turn_player = (current_turn_player + 1) % player_count;
			}
			notifyPlayerDie(playerId, current_turn_player); // 테이블에게 플레이어 죽은 정보 전달
			
			return;
		}

		playerDecks[idx]->takeCard(card);
	}
}

void 
TableCardsImpl::giveRewardToWinner(int playerId)
{
	playerDecks[playerId]->mergeDeck(tableDeck);
}

void 
TableCardsImpl::notifyBellActivate(int next_turn_player)
{
	// 메세지 형태로 테이블에 전달?
	Message* message = new GameMessage(GameStatus::BELL_ACTIVATE, this->frontCards, next_turn_player);
	table->notifyGameStatus(message);
}

void 
TableCardsImpl::notifyPlayerDie(int playerId, int next_turn_player)
{
	Message* message = new GameMessage(GameStatus::PLAYER_DIE, this->frontCards, next_turn_player, playerId);
	table->notifyGameStatus(message);
}

void TableCardsImpl::notifyBellWinner(int playerId)
{
	Message* message = new GameMessage(GameStatus::BELL_WIN, this->frontCards, current_turn_player, playerId);
	table->notifyGameStatus(message);
}

void TableCardsImpl::notifyNextTurn(int next_turn_player)
{
	Message* message = new GameMessage(GameStatus::NEXT_TURN, this->frontCards, next_turn_player);
	table->notifyGameStatus(message);
}

