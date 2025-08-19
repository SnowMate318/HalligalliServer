#pragma once
#include "IPlayerManager.h"
#include <utility>
#include <string>
#include "Role.h"

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

	virtual IGamePlayer* getGamePlayer()override;
	virtual ILobbyPlayer* getLobbyPlayer()override;
	virtual IRoomPlayer* getRoomPlayer()override;

	virtual int getPlayerId()override;

	virtual void sendMessageToUser(Message* message)override;
	virtual void executeCommand(RequestMessage* message)override;
	virtual void resetPlayerInfo(Role role)override;
	virtual void gameStart(std::pair<int, int> roomInfo)override;
};