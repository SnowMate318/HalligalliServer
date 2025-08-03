#pragma once
class IGamePlayer {
private:
	int playerId;
	int roomId;
	int roomPlayerId;
	bool isAlive;
	IPlayerDeck* playerDeck;
public:
	virtual void playCard() = 0;
	virtual void penalty() = 0;
	virtual void pressBell(int diff) = 0;
	virtual void die() = 0;

};