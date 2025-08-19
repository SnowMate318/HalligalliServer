#pragma once

#include "IPlayerManager.h"
#include <unordered_map>

class ISocket;

class ISocketManager {
private:
	std::unordered_map<int, ISocket*> sockets;
	std::unordered_map<int, IPlayerManager*> playerManagers;
public:

	virtual void sendMessage(int playerId, Message* message) = 0;
	virtual void receiveMessage(int playerId, RequestMessage* message) = 0;

	virtual void addSocket(int socketId, std::string name, ISocket* socket) = 0;
	virtual void removeSocket(int removeId) = 0;

};