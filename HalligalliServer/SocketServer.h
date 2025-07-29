#pragma once
#include "IServer.h"
#include <iostream>
class SocketServer : IServer {

public:
	virtual void startServer()override;
	virtual void stopServer()override;

};