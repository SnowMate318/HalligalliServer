#include "RequestMessage.h"
#include "ParsingException.h"

RequestMessage::RequestMessage(json j)
{
	if (!j.contains("action")) {
		throw new ParsingException();
	}



}

json RequestMessage::toJson()
{
	return json();
}
