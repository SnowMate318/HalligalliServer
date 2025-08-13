#include "PenaltyGivenMessage.h"

void PenaltyGivenMessage::messageExecute(IPlayerManager* playerManager)
{
	IGamePlayer* gamePlayer = playerManager->getGamePlayer();
	gamePlayer->penalty();
}
