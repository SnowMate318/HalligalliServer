#include "PlayerManagerImpl.h"

class Message;
class IGamePlayer;
class ILobbyPlayer;
class IRoomPlayer;
class Request;   // ← 전방 선언

PlayerManagerImpl::PlayerManagerImpl(int socketId, std::string playerName)
	: socketId(socketId), playerName(playerName)
{
	gamePlayer = nullptr;
	roomPlayer = nullptr;
}


PlayerManagerImpl::~PlayerManagerImpl()
{
	delete gamePlayer;
	delete roomPlayer;
}

IGamePlayer* PlayerManagerImpl::getGamePlayer()
{
	return gamePlayer;
}

IRoomPlayer* PlayerManagerImpl::getRoomPlayer()
{
	return roomPlayer;
}

int PlayerManagerImpl::getSocketId()
{
	return socketId;
}

std::string PlayerManagerImpl::getPlayerName()
{
	return playerName;
}

void PlayerManagerImpl::sendMessageToSocket(Message* message)
{

	SocketPlayerManager::instance().sendMessage(socketId, message);
}


void PlayerManagerImpl::resetPlayerInfo(Role role)
{
	switch (role) {
	case Role::GAME:
		delete gamePlayer;
		gamePlayer = nullptr;
		break;
	case Role::ROOM:
		delete roomPlayer;
		roomPlayer = nullptr;
		break;
	}
}

void PlayerManagerImpl::createGamePlayer(int roomId, int roomPlayerIndex, IGame* game)
{
	if (gamePlayer != nullptr) {
		resetPlayerInfo(Role::GAME);
	}
	this->gamePlayer = new GamePlayerImpl(this, game, roomId, roomPlayerIndex);
}

void PlayerManagerImpl::createRoomPlayer(IRoom* room)
{
	this->roomPlayer = new RoomPlayerImpl(this, room);
}
