#pragma once
#include "IPlayer.h"
#include "IBell.h"
#include "Message.h"
#include "ITableCards.h"

class ITable {
private:
	IBell* bell;
	ITableCards* tablecards;
public:
	virtual void playCard(int playerId) = 0;
	virtual void ringBell(int playerId, int timeDiff) = 0;
	virtual void getPenalty(int playerId) = 0;
	virtual void playerEnter(IPlayer player) = 0;
	virtual void playerExit(int playerId) = 0;
	virtual void playCard(int playerId) = 0;

	virtual void notifyGameStatus(Message* message) = 0;
};