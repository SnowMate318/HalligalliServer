#pragma once
#include "GameStatus.h"
#include "IGamePlayer.h"
#include "IFrontCards.h"
class GameMessage {

private:
	GameStatus gameStatus;
	int targetPlayer;
	int nextTurn;
	std::vector<IGamePlayer*> players;
	IFrontCards* frontCatds;

public:
	GameMessage(
		GameStatus gameStatus,
		int targetPlayer,
		int nextTurn,
		std::vector<IGamePlayer*> players,
		IFrontCards* frontCatds
	) : gameStatus(gameStatus), 
		targetPlayer(targetPlayer), 
		nextTurn(nextTurn), 
		players(players), 
		frontCatds(frontCatds) {}

};