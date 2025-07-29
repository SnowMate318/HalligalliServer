#pragma once
#include "IPublisher.h"

class PublisherImpl : IPublisher {
public:
	virtual void notify()override;
	virtual void attach()override;
	virtual void detach()override;
};