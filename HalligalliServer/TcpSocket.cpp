#include "TcpSocket.h"


TcpSocket::TcpSocket() {};
TcpSocket::~TcpSocket() {};

void
TcpSocket::sendJson(std::string str) {
	std::cout << "sendJson ȣ��" << std::endl;
}

std::string
TcpSocket::receiveJson() {
	std::cout << "receiveJson ȣ��" << std::endl;
	return "1";
}