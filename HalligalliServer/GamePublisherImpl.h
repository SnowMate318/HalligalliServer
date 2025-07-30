#pragma once
#include "IGamePublisher.h"
#include "IgameObserver.h"

class GamePublisherImpl : public IGamePublisher{

private:

public:

	GamePublisherImpl();
	~GamePublisherImpl();

	virtual void notify()override;
	virtual void attach()override;
	virtual void detach()override;

};