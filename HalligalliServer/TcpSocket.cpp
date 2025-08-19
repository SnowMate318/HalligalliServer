#include "TcpSocket.h"

TcpSocket::~TcpSocket()
{
}

void TcpSocket::setUsername(std::string username)
{
    this->username = username;
}

std::string TcpSocket::getUsername()
{
    return username;
}

void TcpSocket::startListening()
{
    constexpr int BUF_SIZE = 4096;
    char buf[BUF_SIZE];
    while (true) {
        int r = recv(clientSock, buf, BUF_SIZE, 0);
        if (r == 0) {
            std::cout << "[Client] 유저 연결 종료.\n";
            break;
        }
        if (r == SOCKET_ERROR) {
            std::cerr << "[Client] 수신 에러: " << WSAGetLastError() << "\n";
            break;
        }
        commandExecute(buf);
    }
}
void TcpSocket::send(ResponseMessage* message)
{
    json response = message->toJson();

}

json TcpSocket::parsing(char bytes[])
{
    return json();
}

RequestMessage* TcpSocket::jsonToMessage(json message)
{
    return nullptr;
}

json TcpSocket::messageToJson(Message* message)
{
    return json();
}
void TcpSocket::commandExecute(char bytes[])
{
    json j = json::parse(bytes);
}