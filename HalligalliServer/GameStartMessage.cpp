#include "GameStartMessage.h"
#include "LobbyImpl.h"

void GameStartMessage::messageExecute(IPlayerManager* playerManager)
{
	// room과 접신해서 모든 유저매니저에게 gamestart를 호출해야함
	ILobby* lobby = LobbyImpl::instance();

	IRoom* room = lobby->getRoomById(roomId);
	bool checkReady = room->checkAllPlayersReady();

	if (!checkReady) {
		// 게임 시작 실패(모두 레디 안함) 콜백
	}

	room->gameStart();

}
