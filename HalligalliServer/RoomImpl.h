#pragma once
#include "IRoom.h"

class HalligalliRoom : IRoom {
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

	virtual std::vector<IGamePlayer*> getRoomPlayers()override;
	virtual std::vector<int> getAlivePlayerIndexes()override;
};