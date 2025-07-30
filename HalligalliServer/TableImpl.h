#pragma once
#include "ITable.h"

class TableImpl : ITable{
	virtual void playCard(int playerId)override;
	virtual void ringBell(int playerId, int timeDiff)override;
	virtual void getPenalty(int playerId)override;
	virtual void playerEnter(IPlayer player)override;
	virtual void playerExit(int playerId)override;
	virtual void playCard(int playerId)override;

	virtual void notifyGameStatus(Message* message)override;
};