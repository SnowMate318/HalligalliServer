#include "BellImpl.h"


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

	std::thread([this, playerId, timeDiff]() { // ĸó ��Ͽ� playerId�� timeDiff �߰�  
		std::this_thread::sleep_for(std::chrono::seconds(4));  

		PlayerBellInfo winner = PlayerBellInfo(playerId, timeDiff);  
		{  
			std::lock_guard<std::mutex> lock(mtx);  
			if (!playerInfos.empty()) {  
				std::sort(playerInfos.begin(), playerInfos.end());  
				winner = playerInfos.front();     // ���� ���� timeDiff  
				playerInfos.clear();              // �ʱ�ȭ  
			}  
			onThread = false;  
		}  

		if (winner.playerId != -1)  
			this->notifyWInner(winner.playerId);  
		}).detach();  
}

void BellImpl::notifyWInner(int playerId)
{
	//Todo: ��� ����
}

void BellImpl::bellActivate()
{
	this->isActivate = true;
}

void BellImpl::bellDeactivate()
{
	this->isActivate = false;
}
