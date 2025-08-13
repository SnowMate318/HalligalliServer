#pragma once
#include "ILobby.h"
#include "IRoom.h"
#include <vector>
class LobbyImpl : ILobby {

public:

	virtual void createRoom(int id, std::string roomName)override;
	virtual void deleteRoom(int id)override;
	virtual std::vector<IRoom*> getRooms(int page)override;

};