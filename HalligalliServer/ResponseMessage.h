#pragma once
#include "Message.h"
#include "ResponseStatus.h"
#include "GameMessage.h"
#include "Action.h"

class ResponseMessage : Message {

private:
	ResponseStatus responseStatus;
	Action action;

	Message* message;

public:
	ResponseMessage(ResponseStatus status) : responseStatus(status) {
		action = Action::NULL_ACTION;
		message = nullptr;
	}
	ResponseMessage(ResponseStatus status, Message* message) : responseStatus(status), message(message) {
		action = Action::NULL_ACTION;
	}

	void setAction(Action action);
	void setResponseStatus(ResponseStatus status);

	~ResponseMessage() {}



	virtual json toJson()override;

};