#pragma once
#include "IGameManager.h"

class GameManagerImpl : IGameManager {
private:
	std::vector<IGamePlayer*> players;
	std::vector<IPlayerDeck*> playerDecks;
	int playerCount;
	IBell* bell;
	ITableDeck* tableDeck;
	IFrontCards* frontCards;
	IGameStatusManager* gameStatusManager;

	virtual GameMessage createInfoMessage()override;

public:

	GameManagerImpl(
		std::vector<IGamePlayer*> players,
		std::vector<IPlayerDeck*> playerDecks,
		int playerCount,
		IBell* bell,
		ITableDeck* tableDeck,
		IFrontCards* frontCards,
		IGameStatusManager* gameStatusManager
	);
	~GameManagerImpl();

	virtual void playCard(int playerId)override;
	virtual void penalty(int playerId)override;
	virtual void playerDie(int playerId)override;
	virtual void pressBell(int playerId, int timeDiff)override;
	virtual void giveRewardToBellWinner(int playerId)override;
	virtual void sendMessageToPlayer(int playerId)override;
	virtual void sendMessageToAll()override;
};