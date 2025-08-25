#pragma once
#include "IPlayerManager.h"
#include "GamePlayerImpl.h"
#include "RoomPlayerImpl.h"
#include "SocketPlayerManager.h"
#include "Role.h"

#include <string>

class PlayerManagerImpl : public IPlayerManager {
private:
	int socketId;
	std::string playerName;

	IGamePlayer* gamePlayer;
	IRoomPlayer* roomPlayer;
	
public:

	PlayerManagerImpl(int socketId, std::string playerName);
		
	~PlayerManagerImpl();

	virtual IGamePlayer* getGamePlayer()override;
	virtual IRoomPlayer* getRoomPlayer()override;

	virtual int getSocketId()override;
	virtual std::string getPlayerName()override;

	virtual void sendMessageToSocket(Message* message)override;
	virtual void resetPlayerInfo(Role role)override;
	virtual void createGamePlayer(int roomId, int roomPlayerIndex, IGame* game)override;
	virtual void createRoomPlayer(IRoom* room)override;
};