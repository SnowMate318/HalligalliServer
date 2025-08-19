#pragma once

#include "Role.h"
#include <utility>
#include <string>

class Message;
class IGamePlayer;
class ILobbyPlayer;
class IRoomPlayer;
class RequestMessage;   // ← 전방 선언
class ISocketManager;

class IPlayerManager {
private:
	int playerId;
	std::string playerName;

	ISocketManager* socketManager;
public:

	virtual IGamePlayer* getGamePlayer() = 0;
	virtual ILobbyPlayer* getLobbyPlayer() = 0;
	virtual IRoomPlayer* getRoomPlayer() = 0; 

	virtual int getPlayerId() = 0;

	virtual void sendMessageToUser(Message* message) = 0;
	virtual void executeCommand(RequestMessage* message) = 0;
	virtual void resetPlayerInfo(Role role) = 0;
	virtual void gameStart(std::pair<int, int> roomInfo) = 0;


};