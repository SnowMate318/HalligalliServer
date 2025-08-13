#include "ExitRoomMessage.h"

void ExitRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	roomPlayer->exitRoom();
	playerManager->resetPlayerInfo(Role::ROOM);
}
