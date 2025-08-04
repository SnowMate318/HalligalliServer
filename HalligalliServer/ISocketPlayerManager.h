#pragma once
#include "GameMessage.h"

class ISocketPlayerManager {

public:
	virtual void sendMessage(GameMessage message) = 0;
};