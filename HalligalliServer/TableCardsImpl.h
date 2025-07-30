#pragma once
#include "ITableCards.h"
#include "GameStatus.h"
#include "ITable.h"
#include "IDeck.h"
#include <unordered_map>
class TableCardsImpl : public ITableCards {
private:
	int player_count;
	std::vector<IDeck*> playerDecks;
	std::vector<ICard*> frontCards;
	std::vector<bool> activate;

	IDeck* tableDeck;
	ITable* table;
	int current_turn_player;

	std::unordered_map<Fruit, int> numbersOfEachFruit;

	void initTable(int player_count);
	void initDeck(int player_count);
	bool checkFrontCardCount();

public:
	TableCardsImpl(int player_count);
	~TableCardsImpl();

	virtual void playCard(int playerId)override;
	virtual void processPenalty(int playerId)override;
	virtual void giveRewardToWinner(int playerId)override;

	virtual void notifyBellActivate(int next_turn_player)override;
	virtual void notifyPlayerDie(int playerId, int next_turn_player)override;
	virtual void notifyBellWinner(int playerId)override;
	virtual void notifyNextTurn(int next_turn_player)override;

};