#pragma once
#include "ISocket.h"
class TcpSocket : ISocket {

public:
	TcpSocket();
	~TcpSocket();
	virtual void sendJson(std::string json)override;
	virtual std::string receiveJson()override;

};