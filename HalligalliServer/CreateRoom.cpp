#include "CreateRoom.h"

void CreateRoom::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);

	IRoom* room = Lobby::instance().createRoom(roomName);
	if (room == nullptr) {
		//���� �ݹ�(�� ���� ����)
	}

	int roomId = room->getRoomId();
	int roomPlayerId = room->addPlayer(playerManager->getRoomPlayer());

	if (roomPlayerId == -1) {
		// �� ���� ���� �ݹ�
	}
}
