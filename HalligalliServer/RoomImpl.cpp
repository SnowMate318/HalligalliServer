#include "RoomImpl.h"
#include "GameCreatorImpl.h"
#define MAX_PLAYER 4

RoomImpl::RoomImpl(int roomId, std::string roomName)
{
	this->roomId = roomId;
	this->roomName = roomName;
	this->playerCount = 0;
	this->gameStarted = false;
	this->gameCreator = new GameCreatorImpl(roomId, this->players);
}

RoomImpl::~RoomImpl()
{
}

int 
RoomImpl::addPlayer(IRoomPlayer* player)
{
	if (playerCount >= MAX_PLAYER) return -1;

	players.push_back(player);
	playerCount++;

	// Rome Role 생성 후 사용자에게 이식?

	return players.size()-1;
}

void 
RoomImpl::removePlayer(int playerId)
{
	IRoomPlayer* player = players[playerId];
	players.erase(players.begin() + playerId);
	playerCount--;
}

void 
RoomImpl::gameStart()
{
	this->gameStarted = true;
	this->gameCreator->createGame();
}

int 
RoomImpl::getRoomId()
{
	return this->roomId;
}

std::string 
RoomImpl::getRoomName()
{
	return this->roomName;
}

int 
RoomImpl::getPlayerCount()
{
	return this->playerCount;
}

bool 
RoomImpl::getGameStarted()
{
	return this->gameStarted;
}
