#pragma once
#include "Player.h"
#include "IPlayerManager.h"
class ILobbyPlayer : Player {

public:

	virtual int getPlayerId() = 0;;

};