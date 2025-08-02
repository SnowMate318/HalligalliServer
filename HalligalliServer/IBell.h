#pragma once
class IBell {
private:
	bool isActivate;
	
public:
	virtual void ringBell(int playerId, int timeDiff) = 0;
	virtual void notifyWInner(int playerId) = 0;
	virtual void bellActivate() = 0;
	virtual void bellDeactivate() = 0;
};