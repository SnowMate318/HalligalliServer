#pragma once
class IGamePlayer {

public:
    virtual void playerReady(int playerNum) = 0;
    virtual void playerUnready(int playerNum) = 0;
    virtual void gameStart() = 0;
    virtual void ringBell(int playerNum, int timeDiff) = 0;
    virtual void playCard(int playerNum) = 0;
    virtual void getPenalty(int playerNum) = 0;

};