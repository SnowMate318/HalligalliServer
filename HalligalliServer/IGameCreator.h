#pragma once
#include "IGame.h"
class IGameCreator {



public:
	virtual IGame* createGame() = 0;

};