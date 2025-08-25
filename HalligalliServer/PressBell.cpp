#include "PressBell.h"

void PressBell::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IGamePlayer* gamePlayer = playerManager->getGamePlayer();

	gamePlayer->ringBell(pressTimeDiff);
}
