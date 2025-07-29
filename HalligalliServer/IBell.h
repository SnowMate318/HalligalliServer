#pragma once
class IBell {
public:
	virtual void ringBell(int playerId, int timeDiff) = 0;
	virtual void notifyWInner(int playerId) = 0;
};