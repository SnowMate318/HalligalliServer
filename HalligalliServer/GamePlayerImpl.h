#pragma once
#include "IGamePlayer.h"
#include "IPlayerDeck.h"
#include "IGameManager.h"

class GamePlayerImpl : IGamePlayer {
private:
	int playerId;
	int roomId;
	int roomPlayerId;
	bool isAlive;
	IPlayerDeck* playerDeck;
	ISocketPlayerManager* socketPlayerManager;
	IGameManager* gameManager;
	
	
public:

	GamePlayerImpl(
		int playerId, 
		int roomId, 
		int roomPlayerId, 
		ISocketPlayerManager* socketPlayerManager,
		IGameManager* gameManager
	);
	~GamePlayerImpl();

	virtual void playCard()override;
	virtual void penalty()override;
	virtual void pressBell(int diff)override;
	virtual void die()override;
	virtual bool isPlayerAlive()override;
	virtual int getRemainingCardCount()override;

	virtual void sendMessageToSocket(GameMessage message)override;
};