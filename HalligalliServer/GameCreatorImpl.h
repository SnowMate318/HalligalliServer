#pragma once
#include "IgameCreator.h"
#include <vector>

class IRoom;
class IBell;
class IGameStatusManager;
class IGameManager;


class GameCreatorImpl : public IGameCreator {

private : 

	IRoom* room;

	IBell* bell;
	IGameStatusManager* gameStatusManager;
	IFrontCards* frontCards;
	ITableDeck* tableDeck;
	std::vector<IGamePlayer*> players;

	IGameManager* gameManager;


public:

	GameCreatorImpl(IRoom* room);
	~GameCreatorImpl();

	virtual IGameManager* createGame()override;


};