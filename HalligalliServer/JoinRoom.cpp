#include "JoinRoom.h"


void JoinRoom::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IRoom* room = Lobby::instance().getRoomById(roomId);

	playerManager->createRoomPlayer(room);

	int roomId = room->getRoomId();
	int roomPlayerId = room->addPlayer(playerManager->getRoomPlayer());


	if (roomPlayerId == -1) {
		// �� ���� ���� �ݹ�

		return;
	}

	playerManager->getRoomPlayer()->setRoomInfo(roomId, roomPlayerId);

}
