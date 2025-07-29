#pragma once
#include "IMessageParser.h"

class MessageParserImpl : IMessageParser {

public:
	virtual IMessage parseMessage()override;

};