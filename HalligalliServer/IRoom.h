#pragma once
#include "IRoomPlayer.h"

class IRoom {
private:
	int roomId;
	std::string roomName;
	int playerCount;
	bool gameStarted;
public:
	virtual int addPlayer(IRoomPlayer* player) = 0;
	virtual void removePlayer(int playerId) = 0;
	virtual void gameStart() = 0;

	virtual int getRoomId() = 0;
	virtual std::string getRoomName() = 0;
	virtual int getPlayerCount() = 0;
	virtual bool getGameStarted() = 0;
};