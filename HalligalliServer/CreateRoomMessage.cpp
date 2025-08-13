#include "CreateRoomMessage.h"

void CreateRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	ILobbyPlayer* lobbyPlayer = playerManager->getLobbyPlayer();
	lobbyPlayer->createRoom(room_title);
	lobbyPlayer->createRoom(room_title);


}
