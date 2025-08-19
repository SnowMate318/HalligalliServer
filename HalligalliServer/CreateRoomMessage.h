#pragma once
#include "RequestMessage.h"

class CreateRoomMessage : public RequestMessage {

	std::string roomName;
	int playerId;
public:

	CreateRoomMessage(std::string roomName, int playerId) : roomName(roomName), playerId(playerId) {};
	~CreateRoomMessage() {}

	virtual void messageExecute(IPlayerManager* playerManager)override;
};