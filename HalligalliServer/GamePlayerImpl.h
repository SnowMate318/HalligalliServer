#pragma once
#include "IGamePlayer.h"

class GamePlayerImpl : public IGamePlayer {

private:
	IPlayerManager* playerManager;
	int roomId;
	int roomPlayerIndex;
	bool alive;


public:

	GamePlayerImpl(IPlayerManager* playerManager, std::pair<int, int> roomInfo)
		: playerManager(playerManager), roomId(roomId), roomPlayerIndex(roomPlayerIndex) {
		alive = true;
	};
	~GamePlayerImpl() {}

	virtual bool playTurn()override;
	virtual void ringBell(int press_time_diff)override;
	virtual void penalty()override;

	virtual void die()override;
	virtual bool isAlive()override;

};