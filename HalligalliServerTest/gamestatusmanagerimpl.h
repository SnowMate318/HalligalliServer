#pragma once
#include "IGameStatusManager.h"


class GameStatusManagerImpl : IGameStatusManager {

private:
	int playerCount;
	int targetPlayer;
	int nextTurnPlayer;
	GameStatus gameStatus;

public:

	GameStatusManagerImpl(int playerCount);
	~GameStatusManagerImpl();

	virtual void updatePlayerDie(int playerId)override;
	virtual void updateBellActivate()override;
	virtual void updateBellWin(int playerId)override;
	virtual void updatePenalty(int playerId)override;
	virtual void updateNextTurn()override;

	virtual GameStatus getGameStatus()override;
	virtual int getTargetPlayer()override;
	virtual int getNextTurnPlayer()override;

};