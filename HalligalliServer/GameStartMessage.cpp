#include "GameStartMessage.h"

void GameStartMessage::messageExecute(IPlayerManager* playerManager)
{
	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	roomPlayer->gameStart();
}
