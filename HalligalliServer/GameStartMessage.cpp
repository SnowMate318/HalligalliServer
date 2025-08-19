#include "GameStartMessage.h"
#include "LobbyImpl.h"

void GameStartMessage::messageExecute(IPlayerManager* playerManager)
{
	// room�� �����ؼ� ��� �����Ŵ������� gamestart�� ȣ���ؾ���
	ILobby* lobby = LobbyImpl::instance();

	IRoom* room = lobby->getRoomById(roomId);
	bool checkReady = room->checkAllPlayersReady();

	if (!checkReady) {
		// ���� ���� ����(��� ���� ����) �ݹ�
	}

	room->gameStart();

}
