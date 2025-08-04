#include "GamePlayerImpl.h"
#include "PlayerDeckImpl.h"

GamePlayerImpl::GamePlayerImpl(
	int playerId, int roomId, int roomPlayerId, 
	ISocketPlayerManager* socketPlayerManager
)
{
	this->playerId = playerId;
	this->roomId = roomId;
	this->roomPlayerId = roomPlayerId;
	this->socketPlayerManager = socketPlayerManager;
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

bool GamePlayerImpl::isPlayerAlive()
{
	return this->isAlive;
}

int GamePlayerImpl::getRemainingCardCount()
{
	return this->playerDeck->getCardCount();
}

void GamePlayerImpl::sendMessageToSocket(GameMessage message)
{
	this->socketPlayerManager->sendMessage(message);
}
