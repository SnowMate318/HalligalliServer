#include "ExitRoom.h"

void ExitRoom::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	IRoom* room = Lobby::instance().getRoomById(roomId);

	room->removePlayer(roomPlayerIndex);
	playerManager->resetPlayerInfo(Role::ROOM);
}
