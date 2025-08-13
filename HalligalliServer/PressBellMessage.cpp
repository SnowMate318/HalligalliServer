#include "PressBellMessage.h"

void PressBellMessage::messageExecute(IPlayerManager* playerManager)
{
	IGamePlayer* gamePlayer = playerManager->getGamePlayer();
	gamePlayer->ringBell(press_time_diff);
}
