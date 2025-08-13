#pragma once
#include "IPlayerManager.h"
class PlayerManagerImpl : public IPlayerManager {
private:
	int playerId;
	std::string playerName;

	ISocketManager* socketManager;

	IGamePlayer* gamePlayer;
	ILobbyPlayer* lobbyPlayer;
	IRoomPlayer* roomPlayer;

public:

	PlayerManagerImpl(int playerId, std::string playerName, ISocketManager* socketManager);
		
	~PlayerManagerImpl();

	virtual void sendMessageToUser(Message* message)override;
	virtual void executeCommand(RequestMessage* message)override;
	virtual void resetPlayerInfo(Role role)override;
};