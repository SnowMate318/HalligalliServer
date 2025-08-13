#pragma once
#include "IRoomPlayer.h"

class RoomPlayerImpl : public IRoomPlayer {
private:
	IPlayerManager* playerManager;
public:

	RoomPlayerImpl(IPlayerManager* playerManager) : playerManager(playerManager) {}
	~RoomPlayerImpl() {}

	virtual void ready()override;
	virtual void unready()override;
	virtual void gameStart()override;
};