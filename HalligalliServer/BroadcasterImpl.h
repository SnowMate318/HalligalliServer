#pragma once
#include "IBroadcaster.h"

class BroadcasterImpl : IBroadcaster {

public:
	virtual void update()override;
	virtual void sendToPlayer(int playerId)override;
	virtual void sendToAll()override;

};