#pragma once
class IBroadcaster {

public:
	virtual void update() = 0;
	virtual void sendToPlayer(int playerId) = 0;
	virtual void sendToAll() = 0;

};