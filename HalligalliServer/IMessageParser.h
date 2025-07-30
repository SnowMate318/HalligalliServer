#pragma once
#include "Message.h"
class IMessageParser {

public:
	virtual Message parseMessage() = 0;

};