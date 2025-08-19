#pragma once
#include "Player.h"
#include "IRoom.h"

class IRoomPlayer : Player {

public:

	virtual void ready() = 0;
	virtual void unready() = 0;
	virtual bool getReady() = 0;
	virtual void startGame(int roomId, int roomPlayerIndex) = 0;
	virtual void exitRoom() = 0;
	virtual void setRoomInfo(int roomId, int roomPlayerIndex) = 0;
};