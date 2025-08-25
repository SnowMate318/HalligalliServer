#include "Unready.h"

void Unready::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	roomPlayer->unready();
}
