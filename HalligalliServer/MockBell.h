#pragma once
#include "IBell.h"
#include "ITable.h"
#include <vector>
#include <algorithm>
#include <mutex>

struct PlayerBellInfo;

class MockBell : IBell {
private:
	bool isActivate;
	bool onThread;

	std::mutex mtx;
	std::vector<PlayerBellInfo> playerInfos;
	

public:
	MockBell();
	~MockBell();
	int getWinner();

	virtual void ringBell(int playerId, int timeDiff)override;
	virtual void notifyWInner(int playerId)override;
	virtual void bellActivate()override;
	virtual void bellDeactivate()override;
};