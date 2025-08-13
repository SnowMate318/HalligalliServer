#include "SocketManagerImpl.h"
#include "ResponseMessage.h"
#include "PlayerManagerImpl.h"

void SocketManagerImpl::createPlayerManager()
{
}

void SocketManagerImpl::deletePlayerManager()
{
}

void SocketManagerImpl::sendMessage(int playerId, Message* message)
{
	//Todo: Socket에게 네트워크메세지로 보냄
	ResponseMessage* response = new ResponseMessage(ResponseStatus::OK, message);

	sockets[playerId]->send(response);

	delete response;
}

void SocketManagerImpl::receiveMessage(int playerId, Message* message)
{
	playerManagers[playerId]->executeCommand(message);
}

void SocketManagerImpl::addSocket(int socketId, std::string name, ISocket* socket)
{
	sockets[socketId] = socket;

	playerManagers[socketId] = new PlayerManagerImpl(socketId, name);

}

void SocketManagerImpl::removeSocket(int removeId)
{
	ISocket* socket = sockets[removeId];
	IPlayerManager* playerManager = playerManagers[removeId];

	sockets.erase(removeId);
	playerManagers.erase(removeId);

	delete socket;
	delete playerManager;

}
