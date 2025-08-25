#include "ResponseMessage.h"

void ResponseMessage::setAction(Action action)
{
    this->action = action;
}

void ResponseMessage::setResponseStatus(ResponseStatus status)
{
    this->responseStatus = status;
}

json ResponseMessage::toJson()
{

    json response = { {"Response", responseStatus} };

    if (message != nullptr) {
        response.update(message->toJson());
    }

    return response;
}
