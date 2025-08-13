#pragma once
#include "Player.h"
#include "IPlayerManager.h"
class IGamePlayer : Player{

private:
	IPlayerManager* playerManager;

public:
	virtual bool playCard() = 0;
	virtual void ringBell(int press_time_diff) = 0;
	virtual void penalty() = 0;

};