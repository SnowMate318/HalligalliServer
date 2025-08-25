#pragma once
#include <json.hpp>
#include "Action.h"
#include "Player.h"
#include "IPlayerManager.h"
#include "SocketPlayerManager.h"

using nlohmann::json;

class Request {

private:


public:
	virtual void execute() = 0;

};