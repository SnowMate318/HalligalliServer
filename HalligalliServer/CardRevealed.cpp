#include "CardRevealed.h"

void CardRevealed::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);
	IGamePlayer* gamePlayer = playerManager->getGamePlayer();
	gamePlayer->playTurn();
}
