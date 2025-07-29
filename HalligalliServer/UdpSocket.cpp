#include "UdpSocket.h"


UdpSocket::UdpSocket() {};
UdpSocket::~UdpSocket() {};

void
UdpSocket::sendJson(std::string str) {
	std::cout << "sendJson 호출" << std::endl;
}

std::string
UdpSocket::receiveJson() {
	std::cout << "receiveJson 호출" << std::endl;
	return "1";
}