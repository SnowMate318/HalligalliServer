#pragma once
#include "IRoom.h"
#include "IGameObserver.h"
class HalligalliRoom : IRoom, IGameObserver {
private:
	IGamePlayer* gamePlayers[4];
	IRoomNotifier* roomNotifier;
public:
	virtual void playerEnter(int playerId)override;
	virtual void playerExit(int playerId)override;

	virtual void playerReady(int playerId)override;
	virtual void playerUnready(int playerId)override;
	virtual void gameStart()override;
	virtual void ringBell(int playerId, int timeDiff)override;
	virtual void playCard(int playerId)override;
	virtual void getPenalty(int playerId)override;

	virtual void update()override;
};