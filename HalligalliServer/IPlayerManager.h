#pragma once
#include "Message.h"
#include "RequestMessage.h"
#include "IGamePlayer.h"
#include "ILobbyPlayer.h"
#include "ISocketManager.h"
#include "IRoomPlayer.h"
#include "Role.h"

class IPlayerManager {

private:
	int playerId;
	std::string playerName;

	ISocketManager* socketManager;

	IGamePlayer* gamePlayer;
	ILobbyPlayer* lobbyPlayer;
	IRoomPlayer* roomPlayer;


public:

	virtual IGamePlayer* getGamePlayer() = 0;
	virtual ILobbyPlayer* getLobbyPlayer() = 0;
	virtual IRoomPlayer* getRoomPlayer() = 0;

	virtual void sendMessageToUser(Message* message) = 0;
	virtual void executeCommand(RequestMessage* message) = 0;
	virtual void resetPlayerInfo(Role role) = 0;
};