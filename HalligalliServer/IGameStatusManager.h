#pragma once
#include "Action.h"
class IGameStatusManager {

private:
	int playerCount;
	int targetPlayer;
	int nextTurnPlayer;
	Action status;

public:

	virtual void updatePlayerDie(int playerId) = 0;
	virtual void updateBellActivate() = 0;
	virtual void updatePenalty(int playerId) = 0;
	virtual void updateBellWin(int playerId) = 0;
	virtual void updateNextTurn() = 0;

	virtual Action getGameStatus() = 0;
	virtual int getTargetPlayer() = 0;
	virtual int getNextTurnPlayer() = 0;
	virtual void setNextTurnPlayer(int playerId) = 0;

};