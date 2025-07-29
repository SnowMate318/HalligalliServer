#pragma once
#pragma once
#include "ISocket.h"
class UdpSocket : ISocket {

public:
	virtual void sendJson(std::string)override;
	virtual std::string receiveJson()override;

};