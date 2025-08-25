#include "GamePlayerImpl.h"

//void GamePlayerImpl::setGame(IGame* game)
//{
//    this->game = game;
//}

void GamePlayerImpl::playTurn()
{
    game->playCard(roomPlayerIndex);

}

void GamePlayerImpl::ringBell(int pressTimeDiff)
{
    game->pressBell(roomPlayerIndex, pressTimeDiff);
}

void GamePlayerImpl::penalty()
{
    game->penalty(roomPlayerIndex);
}

void GamePlayerImpl::die()
{
    alive = false;
}

bool GamePlayerImpl::isAlive()
{
    return alive;
}

int GamePlayerImpl::getPlayerId()
{
    return roomPlayerIndex;
}

std::string GamePlayerImpl::getPlayerName()
{
    return playerManager->getPlayerName();
}

IPlayerDeck* GamePlayerImpl::getDeck()
{
    return playerDeck;
}
