#include "TableImpl.h"



TableImpl::TableImpl(IBell* bell, ITableCards* tableCards,IRoom* room, IRoomNotifier* roomNotifier)
{
	this->bell = bell;
	this->tableCards = tableCards;
	this->room = room;
	this->roomNotifier = roomNotifier;
}

TableImpl::~TableImpl()
{
}

void TableImpl::playCard(int playerId)
{
	tableCards->playCard(playerId);
}

void TableImpl::notifyGameStatus(Message* message)
{
	roomNotifier->notifyGameMessage(message);
}

void TableImpl::ringBell(int playerId, int timeDiff)
{
}

void TableImpl::getPenalty(int playerId)
{
	tableCards->processPenalty(playerId, getAlivePlayersIndexes());
}

void TableImpl::playerExitInGame(int playerId) // 
{
	tableCards->playerExit(playerId);
}

std::vector<IGamePlayer*>
TableImpl::getPlayers()
{
	return room->getRoomPlayers();
}

std::vector<int> 
TableImpl::getAlivePlayersIndexes()
{
	//Todo: ±¸Çö
	return room->getAlivePlayerIndexes();
}
