#pragma once
#include "ResponseMessage.h"
#include "ISocket.h"
#include "PlayerManagerImpl.h"
#include <unordered_map>

class SocketPlayerManager {
private:
	std::unordered_map<int, ISocket*> sockets;
	std::unordered_map<int, IPlayerManager*> playerManagers;

	void createPlayerManager(int playerId, std::string name);
	void deletePlayerManager(int removeId);
	// ½Ì±ÛÅæ ±¸Çö  

	SocketPlayerManager() = default;
	~SocketPlayerManager() = default;

	SocketPlayerManager(const SocketPlayerManager&) = delete;
	SocketPlayerManager& operator=(const SocketPlayerManager&) = delete;
	SocketPlayerManager(SocketPlayerManager&&) = delete;
	SocketPlayerManager& operator=(SocketPlayerManager&&) = delete;

public:

	static SocketPlayerManager& instance() {
		static SocketPlayerManager inst;
		return inst;   // LobbyImpl °´Ã¼ ÁÖ¼ÒÁö¸¸ ILobby*·Î ¹İÈ¯  
	}

	void sendMessage(int socketId, Message* message);
	IPlayerManager* getPlayerManager(int socketId);

	void addSocket(int socketId, std::string name, ISocket* socket);
	void removeSocket(int removeId);
};