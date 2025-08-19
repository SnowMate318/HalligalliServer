#pragma once
#include "ISocketManager.h"
#include <unordered_map>

class SocketManagerImpl : ISocketManager {
private:
	std::unordered_map<int, ISocket*> sockets;
	std::unordered_map<int, IPlayerManager*> playerManagers;

	void createPlayerManager();
	void deletePlayerManager();

public:

	SocketManagerImpl() {}
	~SocketManagerImpl() {}

	virtual void sendMessage(int playerId, Message* message)override;
	virtual void receiveMessage(int playerId, RequestMessage* message)override;

	virtual void addSocket(int socketId, std::string name, ISocket* socket)override;
	virtual void removeSocket(int removeId)override;
};