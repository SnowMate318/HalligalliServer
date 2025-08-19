#pragma once
#include "ILobbyPlayer.h"
#include "LobbyImpl.h"

class LobbyPlayerImpl : public ILobbyPlayer {
private:
	int playerId;
	IPlayerManager* playerManager;
	ILobby* lobby;
public:

	LobbyPlayerImpl(IPlayerManager* playerManager, int playerId) : playerManager(playerManager), playerId(playerId){
		lobby = LobbyImpl::instance();
	}
	~LobbyPlayerImpl() {}

	virtual int getPlayerId()override;

};