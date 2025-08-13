#pragma once
#include "IRoom.h"
#include "IGameCreator.h"
#include "ILobby.h"
#include <vector>
#include <string>
class RoomImpl : public IRoom {

private:
	int roomId;
	std::string roomName;
	int playerCount;
	bool gameStarted;
	
	std::vector<IRoomPlayer*> players;
	IGameCreator* gameCreator;
	ILobby* lobby;

public:

	RoomImpl(int roomId, std::string roomName);
	~RoomImpl();

	virtual int addPlayer(IRoomPlayer* player)override;
	virtual void removePlayer(int playerId)override;
	virtual void gameStart()override;

	virtual int getRoomId()override;
	virtual std::string getRoomName()override;
	virtual int getPlayerCount()override;
	virtual bool getGameStarted()override;
};