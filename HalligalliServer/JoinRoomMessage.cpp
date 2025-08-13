#include "JoinRoomMessage.h"

void JoinRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	ILobbyPlayer* lobbyPlayer = playerManager->getLobbyPlayer();
	lobbyPlayer->enterRoom(room_id, roomPlayer);

}
