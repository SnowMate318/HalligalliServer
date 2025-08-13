#include "FindRoomMessage.h"

void FindRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	ILobbyPlayer* lobbyPlayer = playerManager->getLobbyPlayer();
	lobbyPlayer->findRooms(page);
}
