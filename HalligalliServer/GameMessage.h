#pragma once
#include "GameStatus.h"
#include "IGamePlayer.h"
#include "IFrontCards.h"
#include <vector>
class GameMessage {
	
public:

	GameStatus gameStatus;
	int targetPlayer;
	int nextTurnPlayer;
	std::vector<IGamePlayer*> players; 
	IFrontCards* frontCards;

	GameMessage(
		GameStatus gameStatus,
		int targetPlayer,
		int nextTurnPlayer,
		std::vector<IGamePlayer*> players,
		IFrontCards* frontCards
	);

};