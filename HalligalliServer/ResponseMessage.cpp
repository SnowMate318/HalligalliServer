#include "ResponseMessage.h"

json ResponseMessage::toJson()
{

    json response = { {"Response", responseStatus} };

    if (message != nullptr) {
        response.update(message->toJson());
    }

    return response;
}
