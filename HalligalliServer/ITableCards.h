#pragma once
#include <vector>
#include "IDeck.h"
class ITableCards {

private:
	std::vector<IDeck*> playerDecks;
	std::vector<ICard*> frontCards;

public:
	virtual void playCard(int playerId) = 0;
	virtual void processPenalty(int playerId) = 0;
	virtual void giveRewardToWinner(int playerId) = 0;

	virtual void notifyBellActivate(int next_turn_player) = 0;
	virtual void notifyPlayerDie(int playerId, int next_turn_player) = 0;
	virtual void notifyBellWinner(int playerId) = 0;
	virtual void notifyNextTurn(int next_turn_player) = 0;
	//todo: 현재 카드 상태 notify 하는게 있으면 전달이 편할거같음
	//todo: 그리고 플레이어 die 이런거 판별하면 역할이 너무 크지않나
};