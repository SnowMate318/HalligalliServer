#include "GameStart.h"


void GameStart::execute()
{
	// room�� �����ؼ� ��� �����Ŵ������� gamestart�� ȣ���ؾ���
	Lobby& lobby = Lobby::instance();

	IRoom* room = lobby.getRoomById(roomId);
	bool checkReady = room->checkAllPlayersReady();

	if (!checkReady) {
		// ���� ���� ����(��� ���� ����) �ݹ�
	}

	room->gameStart();

}
