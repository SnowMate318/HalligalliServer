#pragma once
#include "IMessageParser.h"

class MessageParserImpl : IMessageParser {

public:
	virtual Message parseMessage()override;

};