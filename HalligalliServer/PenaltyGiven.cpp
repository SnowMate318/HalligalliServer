#include "PenaltyGiven.h"

void PenaltyGiven::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IGamePlayer* gamePlayer = playerManager->getGamePlayer();
	gamePlayer->penalty();
}
