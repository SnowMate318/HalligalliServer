#pragma once
#include "ITable.h"
#include "IGamePlayer.h"
#include "IRoom.h"


class TableImpl : public ITable{

private:
	IBell* bell;
	ITableCards* tableCards;
	IRoom* room;
	IRoomNotifier* roomNotifier;

	std::vector<IGamePlayer*> getPlayers();
	std::vector<int> getAlivePlayersIndexes();

public:

	TableImpl(IBell* bell, ITableCards* tableCards, IRoom* room, IRoomNotifier* roomNotifier);
	~TableImpl();

	virtual void playCard(int playerId)override;
	virtual void ringBell(int playerId, int timeDiff)override;
	virtual void getPenalty(int playerId)override;
	virtual void playerExitInGame(int playerId)override;
	virtual void playCard(int playerId)override;

	virtual void notifyGameStatus(Message* message)override;
};