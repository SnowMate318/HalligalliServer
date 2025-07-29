#include "TcpSocket.h"


TcpSocket::TcpSocket() {};
TcpSocket::~TcpSocket() {};

void
TcpSocket::sendJson(std::string str) {
	std::cout << "sendJson 호출" << std::endl;
}

std::string
TcpSocket::receiveJson() {
	std::cout << "receiveJson 호출" << std::endl;
	return "1";
}