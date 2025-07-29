#pragma once
#include <json.hpp>
#include "ISocket.h"
#include "ICommander.h"
#include "ICommandMediator.h"
#include "IMessageParser.h"

class CommandMediatorImpl : ICommandMediator{

private:
	ISocket* socket;
	ICommander* commander;
	IMessageParser* messageParser;
public:
	virtual void sendToPlayer(nlohmann::json)override;
	virtual void sendToSocket(nlohmann::json)override;

};