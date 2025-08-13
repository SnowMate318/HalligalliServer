#pragma once
#include "IRoom.h"
#include <string>
#include <vector>

class ILobby {

public:

	virtual void createRoom( std::string roomName) = 0;
	virtual void deleteRoom(int id) = 0;
	virtual std::vector<IRoom*> getRooms(int page) = 0;
	virtual IRoom* getRoomById(int roomId) = 0;
	virtual bool playerEnterRoom(int playerId, int roomId) = 0;
};