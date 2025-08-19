#include "RoomImpl.h"
#include "GameCreatorImpl.h"
#include "IRoomPlayer.h"

#define MAX_PLAYER 4

RoomImpl::RoomImpl(int roomId, std::string roomName)
{
	this->roomId = roomId;
	this->roomName = roomName;
	this->playerCount = 0;
	this->gameStarted = false;
	this->gameCreator = nullptr;
}

RoomImpl::~RoomImpl()
{
}

bool 
RoomImpl::addPlayer(IRoomPlayer* player)
{
	if (playerCount >= MAX_PLAYER) return false;

	players.push_back(player);
	player->setRoomInfo(roomId, playerCount++);
	

	return true;
}

void 
RoomImpl::removePlayer(int playerId)
{
	IRoomPlayer* player = players[playerId];
	players.erase(players.begin() + playerId);
	playerCount--;
}

bool 
RoomImpl::checkAllPlayersReady()
{
	for (IRoomPlayer* player : players) {
		if (!player->getReady()) return false;
	}
	return true;
}

void
RoomImpl::gameStart()
{
	this->gameStarted = true;
	// gamePlayer �����
	for (int i = 0; i < players.size(); i++) {
		players[i]->startGame(roomId, i);
	}
	
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
