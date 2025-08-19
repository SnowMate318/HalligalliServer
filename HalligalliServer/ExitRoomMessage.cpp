#include "ExitRoomMessage.h"
#include "LobbyIMpl.h"

void ExitRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	IRoomPlayer* roomPlayer = playerManager->getRoomPlayer();
	ILobby* lobby = LobbyImpl::instance();
	IRoom* room = lobby->getRoomById(roomId);

	lobby->enterLobbyPlayer(playerManager->getPlayerId(), playerManager->getLobbyPlayer());
	room->removePlayer(roomPlayerIndex);
	playerManager->resetPlayerInfo(Role::ROOM);
}
