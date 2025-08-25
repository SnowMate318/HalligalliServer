#pragma once

#include "Message.h"
#include "IRoom.h"

class RoomInfoMessage : public Message {
	
private:
	int page;
	std::vector<IRoom*> rooms;

public:

	RoomInfoMessage(int page, std::vector<IRoom*> rooms) : page(page), rooms(rooms) {}
	~RoomInfoMessage() {}

	virtual json toJson()override;

};