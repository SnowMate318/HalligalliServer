#include "FindRoom.h"

void FindRoom::execute()
{
	IPlayerManager* playerManager = SocketPlayerManager::instance().getPlayerManager(socketId);
	std::vector<IRoom*> rooms = Lobby::instance().getRooms(page);
	RoomInfoMessage* roomInfoMessage = new RoomInfoMessage(page, rooms);

	SocketPlayerManager::instance().sendMessage(socketId, roomInfoMessage);
}
