#include "GamePlayerImpl.h"
#include "PlayerDeckImpl.h"

GamePlayerImpl::GamePlayerImpl(int playerId, int roomId, int roomPlayerId)
{
	this->playerId = playerId;
	this->roomId = roomId;
	this->roomPlayerId = roomPlayerId;
	this->playerDeck = new PlayerDeckImpl();
	this->isAlive = true;
}

GamePlayerImpl::~GamePlayerImpl()
{
}

void 
GamePlayerImpl::playCard()
{
}

void 
GamePlayerImpl::penalty()
{
}

void 
GamePlayerImpl::pressBell(int diff)
{
}

void 
GamePlayerImpl::die()
{

}
