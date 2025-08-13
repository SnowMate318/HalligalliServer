#include "PlayerManagerImpl.h"
#include "GamePlayerImpl.h"
#include "LobbyPlayerImpl.h"
#include "RoomPlayerImpl.h"
#include "JoinRoomMessage.h"
#include "CreateRoomMessage.h"


PlayerManagerImpl::PlayerManagerImpl(int playerId, std::string playerName, ISocketManager* socketManager)
	: playerId(playerId), playerName(playerName), socketManager(socketManager)
{
	gamePlayer = new GamePlayerImpl(this);
}


PlayerManagerImpl::~PlayerManagerImpl()
{
	delete gamePlayer;
	delete lobbyPlayer;
	delete roomPlayer;
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
		gamePlayer = new GamePlayerImpl();
		break;
	case Role::LOBBY:
		delete lobbyPlayer;
		lobbyPlayer = new LobbyPlayerImpl();
		break;
	case Role::ROOM:
		delete roomPlayer;
		roomPlayer = new RoomPlayerImpl();
		break;
	}
}
