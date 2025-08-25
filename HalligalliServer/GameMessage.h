#pragma once
#include "Action.h"
#include "IGamePlayer.h"
#include "IFrontCards.h"

class GameMessage : public Message{

private:
	Action status;
	int targetPlayer;
	int nextTurn;
	std::vector<IGamePlayer*> players;
	IFrontCards* frontCards;

public:
	GameMessage(
		Action status,
		int targetPlayer,
		int nextTurn,
		std::vector<IGamePlayer*> players,
		IFrontCards* frontCatds
	) : status(status),
		targetPlayer(targetPlayer), 
		nextTurn(nextTurn), 
		players(players), 
		frontCards(frontCards) {}

	json toJson()override;

};