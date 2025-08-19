#include "LobbyImpl.h"
#include "RoomImpl.h"

void LobbyImpl::enterLobbyPlayer(int playerId, ILobbyPlayer* lobbyPlayer)
{
	players[playerId] = lobbyPlayer;
}

void LobbyImpl::exitLobbyPlayer(int playerId)
{
	players.erase(playerId);
}

IRoom* LobbyImpl::createRoom(std::string roomName)
{
	int roomId = cnt++;
	IRoom* room = new RoomImpl(roomId, roomName);
	rooms[roomId] = room;
	return room;
}

void LobbyImpl::deleteRoom(int id)
{
	IRoom* room = rooms[id];
	rooms.erase(id);
	delete room;
}

std::vector<IRoom*> LobbyImpl::getRooms(int page)
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

IRoom* LobbyImpl::getRoomById(int roomId)
{
	return rooms[roomId];
}

