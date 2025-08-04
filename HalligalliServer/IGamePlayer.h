#pragma once
#include "GameMessage.h"
#include "IPlayerDeck.h"
#include "ISocketPlayermanager.h"
class IGamePlayer {
private:
	int playerId;
	int roomId;
	int roomPlayerId;
	bool isAlive;
	IPlayerDeck* playerDeck;
	ISocketPlayerManager* socketPlayerManager;
public:
	virtual void playCard() = 0;
	virtual void penalty() = 0;
	virtual void pressBell(int diff) = 0;
	virtual void die() = 0;
	virtual bool isPlayerAlive() = 0;
	virtual int getRemainingCardCount() = 0;

	virtual void sendMessageToSocket(GameMessage message) = 0;

};