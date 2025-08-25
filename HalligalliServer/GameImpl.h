#pragma once
#include "IGame.h"
#include "Player.h"
#include "CardImpl.h"
#include "FrontCardsImpl.h"

class GameMessage;

class GameImpl : public IGame {
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

	GameImpl(
		int playerCount,
		IBell* bell,
		ITableDeck* tableDeck,
		IFrontCards* frontCards,
		IGameStatusManager* gameStatusManager
	) : playerCount(playerCount), 
		bell(bell), 
		tableDeck(tableDeck), 
		frontCards(frontCards), 
		gameStatusManager(gameStatusManager) {
	
	}

	~GameImpl() {
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