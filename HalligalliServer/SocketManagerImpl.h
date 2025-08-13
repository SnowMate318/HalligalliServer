#pragma once
#include "ISocketManager.h"

class SocketManagerImpl : ISocketManager {
private:
	std::unordered_map<int, ISocket*> sockets;
	std::unordered_map<int, IPlayerManager*> playerManagers;

	virtual void createPlayerManager()override;
	virtual void deletePlayerManager()override;

public:

	SocketManagerImpl() {}
	~SocketManagerImpl() {}

	virtual void sendMessage(int playerId, Message* message)override;
	virtual void receiveMessage(int playerId, Message* message)override;

	virtual void addSocket(int socketId, std::string name, ISocket* socket)override;
	virtual void removeSocket(int removeId)override;
};