#pragma once
#include "Message.h"
#include "ICard.h"
#include "IGamePlayer.h"
#include "GameStatus.h"
#include <vector>

class GameMessage : public Message {

private:
	std::vector<IGamePlayer*> gamePlayers;
	std::vector<ICard*> frontcard;
	GameStatus message;
	int next_turn;
	int target_player;

public:
	
	GameMessage(GameStatus message, std::vector<ICard*> frontcard);
	GameMessage(GameStatus message, std::vector<ICard*> frontcard, int target_player);

	~GameMessage();

	void setPlayers(std::vector<IGamePlayer*> gamePlayers);
	void setNextTurn(int next_turn);
	

};