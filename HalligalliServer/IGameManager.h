#pragma once
#include <vector>
#include "IGamePlayer.h"
#include "IPlayerDeck.h"
#include "IBell.h"
#include "ITableDeck.h"
#include "IFrontCards.h"
#include "IGameStatusManager.h"
#include "GameMessage.h"
#include <memory>
class IGameManager {

private:
	std::vector<IGamePlayer*> players;
	std::vector<IPlayerDeck*> playerDecks;
	IBell* bell;
	ITableDeck* tableDeck;
	IFrontCards* frontCards;
	IGameStatusManager* gameStatusManager;

	virtual GameMessage createInfoMessage() = 0;

public:
	virtual void playCard(int playerId) = 0;
	virtual void penalty(int playerId) = 0;
	virtual void playerDie(int playerId) = 0;
	virtual void pressBell(int playerId, int timeDiff) = 0;
	virtual void giveRewardToBellWinner(int playerId) = 0;
	virtual void sendMessageToPlayer(int playerId) = 0;
	virtual void sendMessageToAll() = 0;

};