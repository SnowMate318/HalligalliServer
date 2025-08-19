#include "CreateRoomMessage.h"
#include "ILobbyPlayer.h"
#include "LobbyImpl.h"
void CreateRoomMessage::messageExecute(IPlayerManager* playerManager)
{
	
	ILobby* lobby = LobbyImpl::instance();
	IRoom* room = lobby->createRoom(roomName);
	if (room == nullptr) {
		//���� �ݹ�(�� ���� ����)
	}

	// �� ����
	lobby->exitLobbyPlayer(playerId);

	int roomId = room->getRoomId();
	int roomPlayerId = room->addPlayer(playerManager->getRoomPlayer());

	if (roomPlayerId == -1) {
		// �� ���� ���� �ݹ�
	}
}
