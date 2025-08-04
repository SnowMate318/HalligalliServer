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
}

void
GameStatusManagerImpl::updateBellActivate()
{
	gameStatus = GameStatus::BELL_ACTIVATE;
	targetPlayer = -1;
}

void
GameStatusManagerImpl::updateBellWin(int playerId)
{
	if (playerId >= playerCount || playerId < 0) {
		throw Exception("잘못된 인덱스 오류");
	}

	gameStatus = GameStatus::BELL_WIN;
	targetPlayer = playerId;
}

void
GameStatusManagerImpl::updatePenalty(int playerId)
{
	if (playerId >= playerCount || playerId < 0) {
		throw Exception("잘못된 인덱스 오류");
	}

	gameStatus = GameStatus::PENALTY;
	targetPlayer = playerId;
}

void
GameStatusManagerImpl::updateNextTurn()
{
	gameStatus = GameStatus::NEXT_TURN;
	targetPlayer = -1;
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

void 
GameStatusManagerImpl::setNextTurnPlayer(int playerId)
{
	this->nextTurnPlayer = playerId;
}
