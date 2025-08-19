#pragma once
#include "IRoom.h"
#include "ILobbyPlayer.h"
#include <string>
#include <vector>

class ILobby {

public:
	virtual ~ILobby() = default;

	virtual void enterLobbyPlayer(int playerId, ILobbyPlayer* lobbyPlayer) = 0;
	virtual void exitLobbyPlayer(int playerId) = 0;

	virtual IRoom* createRoom( std::string roomName) = 0;
	virtual void deleteRoom(int id) = 0;
	virtual std::vector<IRoom*> getRooms(int page) = 0;
	virtual IRoom* getRoomById(int roomId) = 0;
};