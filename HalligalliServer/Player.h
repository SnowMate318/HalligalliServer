#pragma once
#include "Message.h"
#include "IGame.h"


class Player {
public:
	virtual ~Player() = default;
	//virtual void sendMessageToPlayerManager(Message* message) = 0;
};