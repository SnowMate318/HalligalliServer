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
	//todo: ���� ī�� ���� notify �ϴ°� ������ ������ ���ҰŰ���
	//todo: �׸��� �÷��̾� die �̷��� �Ǻ��ϸ� ������ �ʹ� ũ���ʳ�
};