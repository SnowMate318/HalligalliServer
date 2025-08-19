#pragma once
#include <string>
#include "ResponseMessage.h"
#include "ISocketManager.h"
class ISocket {

public:
	virtual void setUsername(std::string username) = 0;
	virtual std::string getUsername() = 0;
	
	virtual void startListening() = 0;
	virtual void send(ResponseMessage* message) = 0;
};