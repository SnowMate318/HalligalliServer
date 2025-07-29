#pragma once
class IGamePublisher {
public:
	virtual void notify() = 0;
	virtual void attach() = 0;
	virtual void detach() = 0;
};