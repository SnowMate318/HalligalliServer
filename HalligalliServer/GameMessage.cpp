#include "GameMessage.h"

GameMessage::GameMessage(
	GameStatus gameStatus, 
	int targetPlayer, 
	int nextTurnPlayer, 
	std::vector<IGamePlayer*> players, 
	IFrontCards* frontCards
)
{
	this->gameStatus = gameStatus;
	this->targetPlayer = targetPlayer;
	this->nextTurnPlayer = nextTurnPlayer;
	this->players = players;
	this->frontCards = frontCards;
}
