#include "SocketPlayerManager.h"


void SocketPlayerManager::createPlayerManager(int socketId, std::string name)
{
	playerManagers[socketId] = new PlayerManagerImpl(socketId, name);
}

void SocketPlayerManager::deletePlayerManager(int removeId)
{
	IPlayerManager* playerManager = playerManagers[removeId];
	playerManagers.erase(removeId);
	delete playerManager;
}

void SocketPlayerManager::sendMessage(int playerId, Message* message)
{
	//Todo: Socket에게 네트워크메세지로 보냄
	ResponseMessage* response = new ResponseMessage(ResponseStatus::RESPONSE_OK, message);

	sockets[playerId]->send(response);

	delete response;
}

IPlayerManager* SocketPlayerManager::getPlayerManager(int socketId)
{
	return playerManagers[socketId];
}

void SocketPlayerManager::addSocket(int socketId, std::string name, ISocket* socket)
{
	sockets[socketId] = socket;
	createPlayerManager(socketId, name);
}

void SocketPlayerManager::removeSocket(int removeId)
{

	deletePlayerManager(removeId);
	ISocket* socket = sockets[removeId];
	sockets.erase(removeId);
	delete socket;

}
