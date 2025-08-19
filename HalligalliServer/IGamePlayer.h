#pragma once
#include "Player.h"
#include "IPlayerManager.h"
class IGamePlayer : Player{

public:
	virtual bool playTurn() = 0;
	virtual void ringBell(int press_time_diff) = 0;
	virtual void penalty() = 0;

	virtual void die() = 0;
	virtual bool isAlive() = 0;

};