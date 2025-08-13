#pragma once
#include "IGamePlayer.h"

class GamePlayerImpl : public IGamePlayer {

private:
	IPlayerManager* playerManager;

public:

	GamePlayerImpl(IPlayerManager* playerManager) : playerManager(playerManager) {}
	~GamePlayerImpl() {}

	virtual bool playCard() = 0;
	virtual void ringBell(int press_time_diff) = 0;
	virtual void penalty() = 0;

};