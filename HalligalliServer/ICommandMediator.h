#pragma once
#include <json.hpp>
#include "ISocket.h"

class ICommandMediator {

private:
	ISocket* socket;
public:
	virtual void sendToPlayer(nlohmann::json) = 0;
	virtual void sendToSocket(nlohmann::json) = 0;

};