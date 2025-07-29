#pragma once
#include <vector>
#include "IDeck.h"
class ITableCards {

private:
	std::vector<IDeck> playerDecks;

public:
	virtual void playCard(int playerId) = 0;
	virtual void processPenalty(int playerId) = 0;
	virtual void giveRewardToWinner(int playerId) = 0;
	virtual void notifyBellActivate() = 0;
	virtual void notifyPlayerDie(int playerId) = 0;

	//todo: ���� ī�� ���� notify �ϴ°� ������ ������ ���ҰŰ���
	//todo: �׸��� �÷��̾� die �̷��� �Ǻ��ϸ� ������ �ʹ� ũ���ʳ�
};