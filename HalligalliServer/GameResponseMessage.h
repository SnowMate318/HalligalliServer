#pragma once
#include "GameStatus.h"
#include "Player.h"
#include "IFrontCards.h"
#include "Message.h"
#include <vector>
class GameMessage : public Message{
	
public:

	GameStatus gameStatus;
	int targetPlayer;
	int nextTurnPlayer;
	std::vector<Player*> players;
	IFrontCards* frontCards;

	GameMessage(
		GameStatus gameStatus,
		int targetPlayer,
		int nextTurnPlayer,
		std::vector<Player*> players,
		IFrontCards* frontCards
	);

};