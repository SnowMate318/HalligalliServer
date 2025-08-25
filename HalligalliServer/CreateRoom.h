#pragma once
#include "Request.h"
#include "Lobby.h"

class CreateRoom : public Request {

	int socketId;
	std::string roomName;

public:

	CreateRoom(int socketId, std::string roomName) : socketId(socketId), roomName(roomName) {};
	~CreateRoom() {}

	virtual void execute()override;
};