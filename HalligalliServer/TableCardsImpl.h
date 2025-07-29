#pragma once
#include "ITableCards.h"
#include "IGamePublisher.h"
class TableCardsImpl : ITableCards, IGamePublisher {
private:
	std::vector<IDeck> playerDecks;
public:
	virtual void playCard(int playerId)override;
	virtual void processPenalty(int playerId)override;
	virtual void giveRewardToWinner(int playerId)override;
	virtual void notifyBellActivate()override;
	virtual void notifyPlayerDie(int playerId)override;

	virtual void notify()override;
	virtual void attach()override;
	virtual void detach()override;
};