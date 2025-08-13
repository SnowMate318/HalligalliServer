#pragma once
#include "ISocket.h"
#include "IPlayerManager.h"
#include <unordered_map>

class ISocketManager {
	
private:
	std::unordered_map<int, ISocket*> sockets;
	std::unordered_map<int, IPlayerManager*> playerManagers;

	virtual void createPlayerManager() = 0;
	virtual void deletePlayerManager() = 0;

public:

	virtual void sendMessage(int playerId, Message* message) = 0;
	virtual void receiveMessage(int playerId, Message* message) = 0;

	virtual void addSocket(int socketId, std::string name, ISocket* socket) = 0;
	virtual void removeSocket(int removeId) = 0;

};