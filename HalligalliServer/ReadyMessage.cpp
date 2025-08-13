#include "ReadyMessage.h"

void ReadyMessage::messageExecute(IPlayerManager* playerManager)
{

	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	roomPlayer->ready();

}
