#include "GamePlayerImpl.h"
#include "PlayerDeckImpl.h"

GamePlayerImpl::GamePlayerImpl(
	int playerId, 
	int roomId, 
	int roomPlayerId, 
	ISocketPlayerManager* socketPlayerManager, 
	IGameManager* gameManager
)
{
	this->playerId = playerId;
	this->roomId = roomId;
	this->roomPlayerId = roomPlayerId;
	this->socketPlayerManager = socketPlayerManager;
	this->gameManager = gameManager;
	this->playerDeck = new PlayerDeckImpl();
	this->isAlive = true;
}

GamePlayerImpl::~GamePlayerImpl()
{
}

void 
GamePlayerImpl::playCard()
{
	gameManager->playCard(playerId);
}

void 
GamePlayerImpl::penalty()
{
	gameManager->penalty(playerId);
}

void 
GamePlayerImpl::pressBell(int diff)
{
	gameManager->pressBell(playerId, diff);
}

void 
GamePlayerImpl::die()
{
	this->isAlive = false;
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
