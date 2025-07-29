#pragma once
class IRoomNotifier {
private:
public:
	virtual void notifyEnterPlayer(int playerId) = 0;
	virtual void notifyExitPlayer(int playerId) = 0;
	virtual void notifyPlayerReady(int playerId) = 0;
	virtual void notifyPlayerUnready(int playerId) = 0;
	virtual void notifyNextTurn(int playerId) = 0;
	virtual void notifyBellWinner(int playerId) = 0;
	virtual void notifyPenalty(int playerId) = 0;
	virtual void notifyPlayerDie(int playerId) = 0;
	virtual void notifyGameWInner(int playerId) = 0;
	virtual void notifyBellActivate() = 0;

};