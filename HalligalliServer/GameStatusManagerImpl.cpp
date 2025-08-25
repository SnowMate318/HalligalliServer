#include "GameStatusManagerImpl.h"
#include "Exception.h"

GameStatusManagerImpl::GameStatusManagerImpl(int playerCount)
{
	this->playerCount = playerCount;
	nextTurnPlayer = 0;
	targetPlayer = -1;
	gameStatus = Action::NEXT_TURN;
}

GameStatusManagerImpl::~GameStatusManagerImpl()
{
}

void
GameStatusManagerImpl::updatePlayerDie(int playerId)
{
	gameStatus = Action::PLAYER_DIE;
	targetPlayer = playerId;
}

void
GameStatusManagerImpl::updateBellActivate()
{
	gameStatus = Action::BELL_ACTIVATE;
	targetPlayer = -1;
}

void
GameStatusManagerImpl::updateBellWin(int playerId)
{
	if (playerId >= playerCount || playerId < 0) {
		throw Exception("잘못된 인덱스 오류");
	}

	gameStatus = Action::BELL_WIN;
	targetPlayer = playerId;
}

void
GameStatusManagerImpl::updatePenalty(int playerId)
{
	if (playerId >= playerCount || playerId < 0) {
		throw Exception("잘못된 인덱스 오류");
	}

	gameStatus = Action::PENALTY;
	targetPlayer = playerId;
}

void
GameStatusManagerImpl::updateNextTurn()
{
	gameStatus = Action::NEXT_TURN;
	targetPlayer = -1;
}

Action
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
