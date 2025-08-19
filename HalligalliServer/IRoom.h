#pragma once
#include <string>

class IRoomPlayer;

class IRoom {

public:
	virtual bool addPlayer(IRoomPlayer* player) = 0;
	virtual void removePlayer(int playerId) = 0;
	virtual bool checkAllPlayersReady() = 0;
	virtual void gameStart() = 0;

	virtual int getRoomId() = 0;
	virtual std::string getRoomName() = 0;
	virtual int getPlayerCount() = 0;

	virtual bool getGameStarted() = 0;
};