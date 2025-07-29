#pragma once
#include "IGamePlayer.h"
#include "IRoomNotifier.h"
class IRoom {

private:
	IGamePlayer* gamePlayers[4];
	IRoomNotifier* roomNotifier;
public:
	virtual void playerEnter(int playerId) = 0;
	virtual void playerExit(int playerId) = 0;

	virtual void playerReady(int playerId) = 0;
	virtual void playerUnready(int playerId) = 0;
	virtual void gameStart() = 0;
	virtual void ringBell(int playerId, int timeDiff) = 0;
	virtual void playCard(int playerId) = 0;
	virtual void getPenalty(int playerId) = 0;

};