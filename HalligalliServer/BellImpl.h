#pragma once
#include "IBell.h"
#include "IGamePublisher.h"

class BellImpl : IBell, IGamePublisher {
	virtual void ringBell(int playerId, int timeDiff)override;
	virtual void notifyWInner(int playerId)override;

	virtual void notify()override;
	virtual void attach()override;
	virtual void detach()override;
};