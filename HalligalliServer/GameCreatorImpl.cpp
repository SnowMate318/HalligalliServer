#include "GameCreatorImpl.h"
#include "BellImpl.h"
#include "FrontCardsImpl.h"
#include "TableDeckImpl.h"
#include "GameStatusManagerImpl.h"
#include "GameManagerImpl.h"
#include "GamePlayerImpl.h"
#include "PlayerDeckImpl.h"


GameCreatorImpl::GameCreatorImpl(IRoom* room)
{
	this->room = room;

	//IPlayerDeck* playerDeck;

	//int idx = 0;
	//for (Player* player : players) {
	//	playerDeck = new PlayerDeckImpl();
	//	gameRole = createGameRole(player, playerDeck, idx++);
	//	player->setRole(gameRole);
	//	playerDecks.push_back(playerDeck);
	//}
}

GameCreatorImpl::~GameCreatorImpl()
{
	delete bell;
	delete frontCards;
	delete gameStatusManager;
	delete tableDeck;
	delete gameManager;
}

IGameManager* 
GameCreatorImpl::createGame()
{
	bell = new BellImpl();
	frontCards = new FrontCardsImpl(this->players.size());
	gameStatusManager = new GameStatusManagerImpl(this->players.size());
	tableDeck = new TableDeckImpl();


	this->gameManager = new GameManagerImpl(
		
		this->players.size(),
		this->bell,
		this->tableDeck,
		this->frontCards,
		this->gameStatusManager
	);

	return this->gameManager;
}
