#pragma once

#include "Role.h"
#include "IRoom.h"
#include <string>

class IGame;
class Message;
class IGamePlayer;
class ILobbyPlayer;
class IRoomPlayer;
class Request;   // ← 전방 선언
class ISocketManager;

class IPlayerManager {
private:
	int socketId;
	std::string playerName;

public:

	virtual IGamePlayer* getGamePlayer() = 0;
	virtual IRoomPlayer* getRoomPlayer() = 0; 

	virtual int getSocketId() = 0;
	virtual std::string getPlayerName() = 0;

	virtual void sendMessageToUser(Message* message) = 0;
	virtual void resetPlayerInfo(Role role) = 0;
	virtual void createGamePlayer(int roomId, int roomPlayerIndex, IGame* game) = 0;
	virtual void createRoomPlayer(IRoom* room) = 0;


};