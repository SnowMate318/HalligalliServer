#pragma once
class IRoomPublisher {
public:
	virtual void notify() = 0;
	virtual void attach() = 0;
	virtual void detach() = 0;
};