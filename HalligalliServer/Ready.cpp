#include "Ready.h"

void Ready::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	roomPlayer->ready();

}
