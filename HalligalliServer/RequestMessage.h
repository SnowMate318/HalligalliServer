#pragma once
#include <json.hpp>
#include "Action.h"
#include "Player.h"
#include "IPlayerManager.h"
using nlohmann::json;

class RequestMessage {

public:
	virtual void messageExecute(IPlayerManager* playerManager) = 0;

};