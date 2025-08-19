#include "GamePlayerImpl.h"

bool GamePlayerImpl::playTurn()
{
    return false;
}

void GamePlayerImpl::ringBell(int press_time_diff)
{
}

void GamePlayerImpl::penalty()
{
}

void GamePlayerImpl::die()
{
    alive = false;
}

bool GamePlayerImpl::isAlive()
{
    return alive;
}
