#include "UdpSocket.h"


UdpSocket::UdpSocket() {};
UdpSocket::~UdpSocket() {};

void
UdpSocket::sendJson(std::string str) {
	std::cout << "sendJson ȣ��" << std::endl;
}

std::string
UdpSocket::receiveJson() {
	std::cout << "receiveJson ȣ��" << std::endl;
	return "1";
}