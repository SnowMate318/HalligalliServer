#include "PlayerManagerImpl.h"
#include "GamePlayerImpl.h"
#include "LobbyPlayerImpl.h"
#include "RoomPlayerImpl.h"
#include "JoinRoomMessage.h"
#include "CreateRoomMessage.h"
#include "ISocketManager.h"
#include "Role.h"
class Message;
class IGamePlayer;
class ILobbyPlayer;
class IRoomPlayer;
class RequestMessage;   // ← 전방 선언

PlayerManagerImpl::PlayerManagerImpl(int playerId, std::string playerName, ISocketManager* socketManager)
	: playerId(playerId), playerName(playerName), socketManager(socketManager)
{
	lobbyPlayer = new LobbyPlayerImpl(this, playerId);
	gamePlayer = nullptr;
	roomPlayer = nullptr;
}


PlayerManagerImpl::~PlayerManagerImpl()
{
	delete gamePlayer;
	delete lobbyPlayer;
	delete roomPlayer;
}

IGamePlayer* PlayerManagerImpl::getGamePlayer()
{
	return gamePlayer;
}

ILobbyPlayer* PlayerManagerImpl::getLobbyPlayer()
{
	return lobbyPlayer;
}

IRoomPlayer* PlayerManagerImpl::getRoomPlayer()
{
	return roomPlayer;
}

int PlayerManagerImpl::getPlayerId()
{
	return playerId;
}

void PlayerManagerImpl::sendMessageToUser(Message* message)
{
	socketManager->sendMessage(playerId, message);
}

void PlayerManagerImpl::executeCommand(RequestMessage* message)
{

	message->messageExecute(this);
	
}

void PlayerManagerImpl::resetPlayerInfo(Role role)
{
	switch (role) {
	case Role::GAME:
		delete gamePlayer;
		gamePlayer = nullptr;
		break;
	case Role::LOBBY:
		delete lobbyPlayer;
		lobbyPlayer = new LobbyPlayerImpl(this, playerId);
		break;
	case Role::ROOM:
		delete roomPlayer;
		roomPlayer = new RoomPlayerImpl(this);
		break;
	}
}

void PlayerManagerImpl::gameStart(std::pair<int, int> roomInfo)
{
	if (gamePlayer != nullptr) {
		resetPlayerInfo(Role::GAME);
	}
	this->gamePlayer = new GamePlayerImpl(this, roomInfo);
}
