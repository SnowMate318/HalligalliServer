#pragma once
#include "IgameCreator.h"
#include "BellImpl.h"
#include "FrontCardsImpl.h"
#include "TableDeckImpl.h"
#include "GameStatusManagerImpl.h"
#include "GameImpl.h"
#include "GamePlayerImpl.h"
#include "PlayerDeckImpl.h"
#include "RoomImpl.h"


#include <vector>


class GameCreatorImpl : public IGameCreator {

private : 

	IRoom* room;

	IBell* bell;
	IGameStatusManager* gameStatusManager;
	IFrontCards* frontCards;
	ITableDeck* tableDeck;
	std::vector<IGamePlayer*> players;

	IGame* game;


public:

	GameCreatorImpl(IRoom* room);
	~GameCreatorImpl();

	virtual IGame* createGame()override;

};