#pragma once
#include "IGameCreator.h"
#include "IBell.h"
#include "IGameStatusManager.h"
#include "Player.h"
#include "IFrontCards.h"
#include "ITableDeck.h"
#include "IRole.h"
#include <vector>

class GameCreatorImpl : public IGameCreator {

private : 
	int roomId;
	IBell* bell;
	IGameStatusManager* gameStatusManager;
	IFrontCards* frontCards;
	ITableDeck* tableDeck;
	std::vector<Player*> players;
	std::vector<IPlayerDeck*> playerDecks;

	IGameManager* gameManager;
	virtual IRole* createGameRole(Player* player, IPlayerDeck* playerDeck, int playerIndex);


public:

	GameCreatorImpl(int roomId, std::vector<Player*> players);
	~GameCreatorImpl();

	virtual IGameManager* createGame()override;


};