#pragma once
#include "Message.h"
#include "ResponseStatus.h"
#include "GameMessage.h"

class ResponseMessage : Message {

private:
	ResponseStatus responseStatus;
	Message* message;

public:
	ResponseMessage(ResponseStatus status) : responseStatus(status) {}
	ResponseMessage(ResponseStatus status, Message* message) : responseStatus(status), message(message) {}
	~ResponseMessage() {}

	virtual json toJson()override;

};