#pragma once
#include "ISender.h"

class SenderImpl : ISender {

public:
	virtual void sendMessage()override;

};