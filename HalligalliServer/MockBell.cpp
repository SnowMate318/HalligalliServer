#include "MockBell.h"


struct PlayerBellInfo {
	int playerId;
	int timeDiff;

	PlayerBellInfo(int playerId, int timeDiff) {
		this->playerId = playerId;
		this->timeDiff = timeDiff;
	}

	bool operator<(const PlayerBellInfo& other) const {
		return timeDiff < other.timeDiff; // �������� ���Ŀ�
	}
};


MockBell::MockBell()
{
	this->isActivate = false;
	this->onThread = false;
}

MockBell::~MockBell()
{
}

void MockBell::ringBell(int playerId, int timeDiff)
{
	if (!isActivate) return;

	std::lock_guard<std::mutex> lock(mtx);
	playerInfos.emplace_back(PlayerBellInfo{ playerId, timeDiff });

	if (onThread) return;

	onThread = true;

	std::thread([this, playerId, timeDiff]() { // ĸó ��Ͽ� playerId�� timeDiff �߰�  
		std::this_thread::sleep_for(std::chrono::seconds(4));

		{
			std::lock_guard<std::mutex> lock(mtx);
			onThread = false;
		}
		}).detach();
}


void MockBell::bellActivate()
{
	this->isActivate = true;
}

void MockBell::bellDeactivate()
{
	this->isActivate = false;
}

int
MockBell::getWinner() {
	PlayerBellInfo winner = PlayerBellInfo(-1, 100000000);
	if (!playerInfos.empty()) {
		std::sort(playerInfos.begin(), playerInfos.end());
		winner = playerInfos.front();     // ���� ���� timeDiff  
		playerInfos.clear();              // �ʱ�ȭ  
	}
	return winner.playerId;
}

void MockBell::notifyWInner(int playerId) {
    
}