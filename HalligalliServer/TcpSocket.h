#pragma once
#include "ISocket.h"
#include "RequestMessage.h"
#include <winsock2.h>
#include <string>
#include <iostream>
#include <json.hpp>

using nlohmann::json;

class TcpSocket : public ISocket {
	int id;
	std::string username;
	SOCKET clientSock;
	sockaddr_storage addr;

	json parsing(char bytes[]);
	RequestMessage* jsonToMessage(json message);
	json messageToJson(Message* message);


	void commandExecute(char bytes[]);

public:

	TcpSocket(int id, SOCKET clientSock, sockaddr_storage addr) : id(id), clientSock(clientSock), addr(addr) {}
	~TcpSocket();

	virtual void setUsername(std::string username)override;
	virtual std::string getUsername()override;

	virtual void startListening()override;
	virtual void send(ResponseMessage* message)override;

};

