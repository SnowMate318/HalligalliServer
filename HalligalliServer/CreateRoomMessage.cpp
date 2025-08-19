#include "CreateRoomMessage.h"
#include "ILobbyPlayer.h"
#include "LobbyImpl.h"
void CreateRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	
	ILobby* lobby = LobbyImpl::instance();
	IRoom* room = lobby->createRoom(roomName);
	if (room == nullptr) {
		//유저 콜백(방 입장 실패)
	}

	// 방 입장
	lobby->exitLobbyPlayer(playerId);

	int roomId = room->getRoomId();
	int roomPlayerId = room->addPlayer(playerManager->getRoomPlayer());

	if (roomPlayerId == -1) {
		// 방 입장 실패 콜백
	}
}
