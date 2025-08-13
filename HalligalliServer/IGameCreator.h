#pragma once
#include "IGameManager.h"

class IGameCreator {



public:
	virtual IGameManager* createGame() = 0;

};