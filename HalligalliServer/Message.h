#pragma once

#include <json.hpp>
using nlohmann::json;

class Message {

public:
	virtual json toJson() = 0;

};