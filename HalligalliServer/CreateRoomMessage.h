#pragma once
#include "RequestMessage.h"

class CreateRoomMessage : public RequestMessage {

	std::string room_title;
	int player_id;
public:

	CreateRoomMessage(std::string room_title, int player_id) : room_title(room_title), player_id(player_id) {};
	~CreateRoomMessage() {}

	virtual void messageExecute(IPlayerManager* playerManager)override;
};