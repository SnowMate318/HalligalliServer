#include "UnreadyMessage.h"

void UnreadyMessage::messageExecute(IPlayerManager* playerManager)
{
	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	roomPlayer->unready();
}
