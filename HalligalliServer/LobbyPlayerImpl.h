#pragma once
#include "ILobbyPlayer.h"

class LobbyPlayerImpl : public ILobbyPlayer {
private:
	IPlayerManager* playerManager;
public:

	LobbyPlayerImpl(IPlayerManager* playerManager) : playerManager(playerManager) {}
	~LobbyPlayerImpl() {}

	virtual void findRooms(int page)override;
	virtual void createRoom(std::string roomName)override;
	virtual void deleteRoom(int roomId)override;
	virtual void enterRoom(int page, IRoomPlayer* roomPlayer)override;
};