#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <atomic>
#include <thread>
#include <iostream>
#include <json.hpp> // ���� ��� ���
#include <unordered_map>
#include "IServer.h"
#include "TcpSocket.h"

using nlohmann::json;
#pragma comment(lib, "Ws2_32.lib")

class ServerImpl : IServer{
public:
    // host�� ���� "0.0.0.0", port�� "5000" ���� ���ڿ�
    ServerImpl(const std::string& host = "0.0.0.0", const std::string& port = "5000");
    ~ServerImpl();


    virtual void serverStart()override; // ���ŷ: accept ����
    virtual void serverStop()override;  // ���� ���� ��û

private:
    std::string host_;
    std::string port_;

    int counter = 0;

    std::unordered_map<int, ISocket*> sockets;

    SOCKET listenSock_ = INVALID_SOCKET;
    std::atomic<bool> running_{ false };

    bool initWinsock();
    bool createListenSocket();
    void closeListenSocket();

    void logging(sockaddr_storage addr);
    bool receive(SOCKET clientSock, std::string& line);
    bool parsingAndVerify(SOCKET clientSock, std::string& line, std::string& username);
    void responseAck(SOCKET clientSock, std::string username);
    void responseNack(SOCKET clientSock, std::string username);

    void clientWorker(SOCKET clientSock, sockaddr_storage addr);
};
