#pragma once
#include "ISocket.h"
#include "Request.h"
#include <winsock2.h>
#include <string>
#include <iostream>
#include <json.hpp>

#include "CardRevealed.h"
#include "CreateRoom.h"
#include "ExitRoom.h"
#include "FindRoom.h"
#include "GameStart.h"
#include "JoinRoom.h"
#include "PenaltyGiven.h"
#include "PlayerEnter.h"
#include "PlayerExit.h"
#include "PressBell.h"
#include "Ready.h"
#include "Unready.h"

using nlohmann::json;

class TcpSocket : public ISocket {
	int socketId;
	std::string username;
	SOCKET clientSock;
	sockaddr_storage addr;

	json messageToJson(Message* message);
	Request* getRequest(char bytes[]);
	void executeCommand(char bytes[]);

public:

	TcpSocket(int socketId, SOCKET clientSock, sockaddr_storage addr) : socketId(socketId), clientSock(clientSock), addr(addr) {}
	~TcpSocket();

	virtual void setUsername(std::string username)override;
	virtual std::string getUsername()override;

	virtual void startListening()override;
	virtual void jsonSend(ResponseMessage* message)override;

};

