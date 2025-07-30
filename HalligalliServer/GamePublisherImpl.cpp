#include "GamePublisherImpl.h"

GamePublisherImpl::GamePublisherImpl(IGameObserver* gameObserver)
{
	this->gameObserver = gameObserver;
}

GamePublisherImpl::~GamePublisherImpl()
{
}

void GamePublisherImpl::notify()
{
}

void GamePublisherImpl::attach()
{
}

void GamePublisherImpl::detach()
{
}
