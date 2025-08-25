#include "Lobby.h"


IRoom* Lobby::createRoom(std::string roomName)
{
	int roomId = cnt++;
	IRoom* room = new RoomImpl(roomId, roomName);
	rooms[roomId] = room;
	return room;
}

void Lobby::deleteRoom(int id)
{
	IRoom* room = rooms[id];
	rooms.erase(id);
	delete room;
}

std::vector<IRoom*> Lobby::getRooms(int page)
{
	int start = page * 10;
	int end = start + 9;

	auto it = rooms.lower_bound(start); // start 이상인 첫 key
	std::vector<IRoom*> lobbyRooms;
	while (it != rooms.end() && it->first <= end) {
		lobbyRooms.push_back(it->second);
	}
	return lobbyRooms;
}

IRoom* Lobby::getRoomById(int roomId)
{
	return rooms[roomId];
}

