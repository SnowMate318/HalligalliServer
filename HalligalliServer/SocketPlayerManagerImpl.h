#pragma once
#include "ISocketPlayerManager.h"


class SocketPlayerManagerImpl : ISocketPlayerManager {

private:

public:

	SocketPlayerManagerImpl();
	~SocketPlayerManagerImpl();

	virtual void sendPlayerToSocket(Message message)override;
	virtual Message sendSocketToPlayer()override;

};