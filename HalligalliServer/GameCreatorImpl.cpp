#include "GameCreatorImpl.h"



GameCreatorImpl::GameCreatorImpl(IRoom* room)
{
	this->game = nullptr;
	this->room = room;
	this->bell = nullptr;
	this->frontCards = nullptr;
	this->gameStatusManager = nullptr;
	this->tableDeck = nullptr;

}

GameCreatorImpl::~GameCreatorImpl()
{
	delete bell;
	delete frontCards;
	delete gameStatusManager;
	delete tableDeck;
	delete game;
}

IGame* 
GameCreatorImpl::createGame()
{
	bell = new BellImpl();
	frontCards = new FrontCardsImpl();
	gameStatusManager = new GameStatusManagerImpl(this->players.size());
	tableDeck = new TableDeckImpl();


	this->game = new GameImpl(
		
		this->players.size(),
		this->bell,
		this->tableDeck,
		this->frontCards,
		this->gameStatusManager
	);



	return this->game;
}
