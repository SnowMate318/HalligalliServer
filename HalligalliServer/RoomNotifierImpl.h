#pragma once
#include "IRoomNotifier.h"
#include "IRoomPublisher.h"

class RoomNotifierImpl : IRoomNotifier, IRoomPublisher {
public:
	virtual void notifyEnterPlayer(int playerId)override;
	virtual void notifyExitPlayer(int playerId)override;
	virtual void notifyPlayerReady(int playerId)override;
	virtual void notifyPlayerUnready(int playerId)override;
	virtual void notifyNextTurn(int playerId)override;
	virtual void notifyBellWinner(int playerId)override;
	virtual void notifyPenalty(int playerId)override;
	virtual void notifyPlayerDie(int playerId)override;
	virtual void notifyGameWInner(int playerId)override;
	virtual void notifyBellActivate()override;

	virtual void notify()override;
	virtual void attach()override;
	virtual void detach()override;
};