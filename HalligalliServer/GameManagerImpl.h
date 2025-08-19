#pragma once
#include "IGameManager.h"
#include "Player.h"

class GameMessage;

class GameManagerImpl : public IGameManager {
private:
	std::unordered_map<int, IGamePlayer*> players;
	std::unordered_map<int, IPlayerDeck*> playerDecks;
	int playerCount;
	IBell* bell;
	ITableDeck* tableDeck;
	IFrontCards* frontCards;
	IGameStatusManager* gameStatusManager;

	GameMessage createInfoMessage();

public:

	GameManagerImpl(
		int playerCount,
		IBell* bell,
		ITableDeck* tableDeck,
		IFrontCards* frontCards,
		IGameStatusManager* gameStatusManager
	) : playerCount(playerCount), 
		bell(bell), 
		tableDeck(tableDeck), 
		frontCards(frontCards), 
		gameStatusManager(gameStatusManager) { }
	~GameManagerImpl() {
		//Todo: 플레이어 카드 딜리트
	}

	virtual void addPlayers(int roomPlayerIndex, IGamePlayer* gamePlayer)override;

	virtual void playCard(int playerId)override;
	virtual void penalty(int playerId)override;
	virtual void playerDie(int playerId)override;
	virtual void pressBell(int playerId, int timeDiff)override;
	virtual void giveRewardToBellWinner(int playerId)override;
	virtual void sendMessageToPlayer(int playerId)override;
	virtual void sendMessageToAll()override;
};