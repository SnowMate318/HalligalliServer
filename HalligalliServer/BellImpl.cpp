#include "BellImpl.h"


struct PlayerBellInfo {
	int playerId;
	int timeDiff;

	PlayerBellInfo(int playerId, int timeDiff) {
		this->playerId = playerId;
		this->timeDiff = timeDiff;
	}

	bool operator<(const PlayerBellInfo& other) const {
		return timeDiff < other.timeDiff; // 오름차순 정렬용
	}
};


BellImpl::BellImpl()
{
	this->isActivate = false;
	this->onThread = false;
}

BellImpl::~BellImpl()
{
}

void BellImpl::ringBell(int playerId, int timeDiff)  
{  
	if (!isActivate) return;  

	std::lock_guard<std::mutex> lock(mtx);  
	playerInfos.emplace_back(PlayerBellInfo{ playerId, timeDiff });  

	if (onThread) return;  

	onThread = true;  

	std::thread([this, playerId, timeDiff]() { // 캡처 목록에 playerId와 timeDiff 추가  
		std::this_thread::sleep_for(std::chrono::seconds(4));  

		PlayerBellInfo winner = PlayerBellInfo(playerId, timeDiff);  
		{  
			std::lock_guard<std::mutex> lock(mtx);  
			if (!playerInfos.empty()) {  
				std::sort(playerInfos.begin(), playerInfos.end());  
				winner = playerInfos.front();     // 가장 작은 timeDiff  
				playerInfos.clear();              // 초기화  
			}  
			onThread = false;  
		}  

		if (winner.playerId != -1)  
			this->notifyWInner(winner.playerId);  
		}).detach();  
}

void BellImpl::notifyWInner(int playerId)
{
	//Todo: 기능 구현
}

void BellImpl::bellActivate()
{
	this->isActivate = true;
}

void BellImpl::bellDeactivate()
{
	this->isActivate = false;
}
