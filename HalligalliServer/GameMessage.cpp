#include "GameMessage.h"

GameMessage::GameMessage(GameStatus message, std::vector<ICard*> frontcard)
{
	this->message = message;
	this->frontcard = frontcard;
	this->next_turn = -1;
	this->target_player = -1;
}


GameMessage::GameMessage(GameStatus message, std::vector<ICard*> frontcard, int target_player)
{
	this->message = message;
	this->frontcard = frontcard;
	this->next_turn = -1;
	this->target_player = target_player;
}

GameMessage::~GameMessage()
{
}

void GameMessage::setPlayers(std::vector<IGamePlayer*> gamePlayers)
{
	this->gamePlayers = gamePlayers;
}

void GameMessage::setNextTurn(int next_turn)
{
	this->next_turn = next_turn;
}
