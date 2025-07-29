#pragma once
#include "IGamePlayer.h"

class HalligalliGamePlayer : IGamePlayer {



    virtual void playerReady(int playerNum)override;
    virtual void playerUnready(int playerNum)override;
    virtual void gameStart()override;
    virtual void ringBell(int playerNum, int timeDiff)override;
    virtual void playCard(int playerNum)override;
    virtual void getPenalty(int playerNum)override;
};