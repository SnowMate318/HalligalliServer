#include "GameStatusManagerImpl.h"
#include "Exception.h"

GameStatusManagerImpl::GameStatusManagerImpl(int playerCount)
{
	this->playerCount = playerCount;
	nextTurnPlayer = 0;
	targetPlayer = -1;
	gameStatus = GameStatus::NEXT_TURN;
}

GameStatusManagerImpl::~GameStatusManagerImpl()
{
}

void 
GameStatusManagerImpl::updatePlayerDie(int playerId)
{
	gameStatus = GameStatus::PLAYER_DIE;
	targetPlayer = playerId;
	nextTurnPlayer = (nextTurnPlayer + 1) % playerCount;
}

void 
GameStatusManagerImpl::updateBellActivate()
{
	gameStatus = GameStatus::PLAYER_DIE;
	targetPlayer = -1;
	nextTurnPlayer = (nextTurnPlayer + 1) % playerCount;
}

void 
GameStatusManagerImpl::updateBellWin(int playerId)
{
	if (playerId >= playerCount || playerId < 0) {
		throw Exception("잘못된 인덱스 오류");
	}

	gameStatus = GameStatus::PLAYER_DIE;
	targetPlayer = playerId;
	nextTurnPlayer = (nextTurnPlayer + 1) % playerCount;
}

void 
GameStatusManagerImpl::updatePenalty(int playerId)
{
	if (playerId >= playerCount || playerId < 0) {
		throw Exception("잘못된 인덱스 오류");
	}

	gameStatus = GameStatus::PLAYER_DIE;
	targetPlayer = playerId;
	nextTurnPlayer = (nextTurnPlayer + 1) % playerCount;
}

void 
GameStatusManagerImpl::updateNextTurn()
{
	gameStatus = GameStatus::PLAYER_DIE;
	targetPlayer = -1;
	nextTurnPlayer = (nextTurnPlayer + 1) % playerCount;
}

GameStatus 
GameStatusManagerImpl::getGameStatus()
{
	return this->gameStatus;
}

int 
GameStatusManagerImpl::getTargetPlayer()
{
	return this->targetPlayer;
}

int 
GameStatusManagerImpl::getNextTurnPlayer()
{
	return this->nextTurnPlayer;
}
