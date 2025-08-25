#pragma once
#include "IGamePlayer.h"

class GamePlayerImpl : public IGamePlayer {

private:
	IPlayerManager* playerManager;
	IPlayerDeck* playerDeck;
	IGame* game;

	int roomId;
	int roomPlayerIndex;
	bool alive;


public:

	GamePlayerImpl(IPlayerManager* playerManager, IGame* game, int roomId, int roomPlayerIndex)
		: playerManager(playerManager), game(game), roomId(roomId), roomPlayerIndex(roomPlayerIndex) {
		playerDeck = new PlayerDeckImpl();
		alive = true;
	}

	~GamePlayerImpl() {
	
		delete playerDeck;
	}

	//virtual void setGame(IGame* game) override;

	virtual void playTurn() override;
	virtual void ringBell(int pressTimeDiff) override;
	virtual void penalty() override;
	virtual void die() override;

	virtual bool isAlive() override;
	virtual int getPlayerId() override;
	virtual std::string getPlayerName() override;

	virtual IPlayerDeck* getDeck() override;

};