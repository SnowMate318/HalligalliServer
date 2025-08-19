#include "JoinRoomMessage.h"
#include "LobbyImpl.h"
#include "IRoom.h"

void JoinRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	int playerId = playerManager->getPlayerId();

	ILobby* lobby = LobbyImpl::instance();
	IRoom* room = lobby->getRoomById(roomId);

	lobby->exitLobbyPlayer(playerId);

	int roomId = room->getRoomId();
	int roomPlayerId = room->addPlayer(playerManager->getRoomPlayer());

	if (roomPlayerId == -1) {
		// 방 입장 실패 콜백
	}


}
