#pragma once
#include "IRoomNotifier.h"
#include "IRoomPublisher.h"

class RoomNotifierImpl : IRoomNotifier, IRoomPublisher {

private:
	virtual void notify()override;
	virtual void attach()override;
	virtual void detach()override;

public:
	RoomNotifierImpl();
	~RoomNotifierImpl();

	virtual void notifyEnterPlayer(int playerId)override;
	virtual void notifyExitPlayer(int playerId)override;
	virtual void notifyPlayerReady(int playerId)override;
	virtual void notifyPlayerUnready(int playerId)override;
	virtual void notifyGameStart()override;

	virtual void notifyGameMessage(Message* message)override;

	
};