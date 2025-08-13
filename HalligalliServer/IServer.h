#pragma once

class IServer {

public:
	virtual void serverStart() = 0;
	virtual void serverStop() = 0;
};