#pragma once
#include <string>
#include <iostream>
class ISocket {

public:
	virtual void sendJson(std::string json) = 0;
	virtual std::string receiveJson() = 0;

};