#pragma once
#include "Player.h"
class ILobbyPlayer : Player {

private:
	IPlayerManager* playerManager;
public:
	virtual void findRooms(int page) = 0;
	virtual void createRoom(std::string roomName) = 0;
	virtual void deleteRoom(int roomId) = 0;
	virtual void enterRoom(int page, IRoomPlayer* roomPlayer) = 0;

};