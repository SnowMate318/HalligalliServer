#pragma once
#include "Player.h"
#include "IRoom.h"
class IRoomPlayer : Player {

private:
	IRoom* room;
	IPlayerManager* playerManager;
public:

	virtual void ready() = 0;
	virtual void unready() = 0;
	virtual void gameStart() = 0;
	virtual void exitRoom() = 0;

};