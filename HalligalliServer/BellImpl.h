#pragma once
#include "IBell.h"
#include <vector>
#include <algorithm>
#include <mutex>

struct PlayerBellInfo;

class BellImpl : public IBell {
private:
	bool isActivate;
	bool onThread;

	std::mutex mtx;
	std::vector<PlayerBellInfo> playerInfos;

public:
	BellImpl();
	~BellImpl();
	virtual void ringBell(int playerId, int timeDiff)override;
	virtual void notifyWInner(int playerId)override;
	virtual void bellActivate()override;
	virtual void bellDeactivate()override;
};