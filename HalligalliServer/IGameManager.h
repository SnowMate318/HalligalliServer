#pragma once
#include <unordered_map>
#include "IGamePlayer.h"
#include "IPlayerDeck.h"
#include "IBell.h"
#include "ITableDeck.h"
#include "IFrontCards.h"
#include "IGameStatusManager.h"
#include <memory>
class IGameManager {

private:

public:
	virtual void addPlayers(int roomPlayerIndex, IGamePlayer* gamePlayer) = 0;

	virtual void playCard(int playerId) = 0;
	virtual void penalty(int playerId) = 0;
	virtual void playerDie(int playerId) = 0;
	virtual void pressBell(int playerId, int timeDiff) = 0;
	virtual void giveRewardToBellWinner(int playerId) = 0;
	virtual void sendMessageToPlayer(int playerId) = 0;
	virtual void sendMessageToAll() = 0;

};