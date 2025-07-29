#pragma once
#include "IMessage.h"
class IMessageParser {

public:
	virtual IMessage parseMessage() = 0;

};