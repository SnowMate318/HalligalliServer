#pragma once
#include "IServer.h"
#include <iostream>
class SocketServer : public IServer {  

public:  
	SocketServer();  
	~SocketServer();  
	virtual void startServer() override;  
	virtual void stopServer() override;  

};