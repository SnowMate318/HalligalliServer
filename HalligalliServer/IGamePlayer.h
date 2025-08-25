#pragma once
#include "Player.h"
#include "IPlayerManager.h"
#include "PlayerDeckImpl.h"

class IGamePlayer : public Player{

public:
	virtual void playTurn() = 0;
	virtual void ringBell(int pressTimeDiff) = 0;
	virtual void penalty() = 0;

	virtual void die() = 0;
	virtual bool isAlive() = 0;
	virtual int getPlayerId() = 0;

	//virtual void setGame(IGame* game) = 0;

	virtual std::string getPlayerName() = 0;

	virtual IPlayerDeck* getDeck() = 0;


}; 