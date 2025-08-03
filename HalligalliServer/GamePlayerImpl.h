#pragma once
#include "IGamePlayer.h"
#include "IPlayerDeck.h"

class GamePlayerImpl : IGamePlayer {
private:
	int playerId;
	int roomId;
	int roomPlayerId;
	bool isAlive;
	IPlayerDeck* playerDeck;
	
public:

	GamePlayerImpl(int playerId, int roomId, int roomPlayerId);
	~GamePlayerImpl();

	virtual void playCard()override;
	virtual void penalty()override;
	virtual void pressBell(int diff)override;
	virtual void die()override;
};