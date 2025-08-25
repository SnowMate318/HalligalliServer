#include "RoomPlayerImpl.h"

void RoomPlayerImpl::ready()
{
	isReady = true;
}

void RoomPlayerImpl::unready()
{
	isReady = false;
}

bool RoomPlayerImpl::getReady()
{
	return isReady;
}

void RoomPlayerImpl::startGame(int roomId, int roomPlayerIndex, IGame* game)
{

	playerManager->createGamePlayer(roomId, roomPlayerIndex , game);
}

void RoomPlayerImpl::exitRoom()
{
}

void RoomPlayerImpl::setRoomInfo(int roomId, int roomPlyaerIndex)
{
	this->roomId = roomId;
	this->roomPlayerIndex = roomPlyaerIndex;
}


