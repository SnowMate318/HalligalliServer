#include "CreateRoom.h"

void CreateRoom::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IRoom* room = Lobby::instance().createRoom(roomName);
	if (room == nullptr) {
		//유저 콜백(방 입장 실패)
	}

	int roomId = room->getRoomId();
	int roomPlayerId = room->addPlayer(playerManager->getRoomPlayer());

	if (roomPlayerId == -1) {
		// 방 입장 실패 콜백
	}
}
