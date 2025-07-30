#pragma once
#include "Message.h"

class IRoomNotifier {
private:
public:
	virtual void notifyEnterPlayer(int playerId) = 0;
	virtual void notifyExitPlayer(int playerId) = 0;
	virtual void notifyPlayerReady(int playerId) = 0;
	virtual void notifyPlayerUnready(int playerId) = 0;
	virtual void notifyGameStart() = 0;

	virtual void notifyGameMessage(Message* message) = 0;

};