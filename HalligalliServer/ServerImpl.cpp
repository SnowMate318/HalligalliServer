// ServerImpl.cpp
#include "ServerImpl.h"


static bool recvLine(SOCKET sock, std::string& outLine) {
    constexpr int BUF_SIZE = 4096;
    char buf[BUF_SIZE];
    outLine.clear();
    while (true) {
        int r = recv(sock, buf, BUF_SIZE, 0);
        if (r == 0) return false; // peer closed
        if (r == SOCKET_ERROR) return false;

        outLine.append(buf, buf + r);
        auto pos = outLine.find('\n');
        if (pos != std::string::npos) {
            outLine = outLine.substr(0, pos); // 개행 전까지 한 줄
            return true;
        }
        if (outLine.size() > 16 * 1024) { // 간단한 방어
            return false;
        }
    }
}

ServerImpl::ServerImpl(const std::string& host, const std::string& port)
    : host_(host), port_(port) {
}

ServerImpl::~ServerImpl() {
    serverStop();
    closeListenSocket();
    WSACleanup();
}

bool ServerImpl::initWinsock() {
    WSADATA wsaData{};
    int r = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (r != 0) {
        std::cerr << "WSAStartup failed: " << r << "\n";
        return false;
    }
    return true;
}
bool ServerImpl::createListenSocket() {
    addrinfo hints{};
    hints.ai_family = AF_INET;       // IPv4 (필요시 AF_UNSPEC로 바꾸면 v4/v6 둘다)
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;    // bind용

    addrinfo* result = nullptr;
    int r = getaddrinfo(host_.c_str(), port_.c_str(), &hints, &result);
    if (r != 0) {
        std::cerr << "getaddrinfo failed: " << gai_strerrorA(r) << "\n";
        return false;
    }

    listenSock_ = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (listenSock_ == INVALID_SOCKET) {
        std::cerr << "socket failed: " << WSAGetLastError() << "\n";
        freeaddrinfo(result);
        return false;
    }

    // 재시작 시 TIME_WAIT 충돌 줄이기
    BOOL opt = TRUE;
    setsockopt(listenSock_, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt));

    r = bind(listenSock_, result->ai_addr, (int)result->ai_addrlen);
    if (r == SOCKET_ERROR) {
        std::cerr << "bind failed: " << WSAGetLastError() << "\n";
        freeaddrinfo(result);
        closesocket(listenSock_);
        listenSock_ = INVALID_SOCKET;
        return false;
    }

    freeaddrinfo(result);

    r = listen(listenSock_, SOMAXCONN);
    if (r == SOCKET_ERROR) {
        std::cerr << "listen failed: " << WSAGetLastError() << "\n";
        closesocket(listenSock_);
        listenSock_ = INVALID_SOCKET;
        return false;
    }

    return true;
}

void ServerImpl::closeListenSocket() {
    if (listenSock_ != INVALID_SOCKET) {
        closesocket(listenSock_);
        listenSock_ = INVALID_SOCKET;
    }
}

void ServerImpl::serverStart() {
    if (!initWinsock()) return;
    if (!createListenSocket()) return;

    running_.store(true);
    std::cout << "[Server] 서버 정보 " << host_ << ":" << port_ << "\n";

    while (running_.load()) {
        sockaddr_storage clientAddr{};
        int addrLen = sizeof(clientAddr);

        SOCKET clientSock = accept(listenSock_, (sockaddr*)&clientAddr, &addrLen);
        if (clientSock == INVALID_SOCKET) {
            int err = WSAGetLastError();
            // 종료 과정 중이면 오류 무시
            if (!running_.load() && (err == WSAEINTR || err == WSAENOTSOCK)) break;
            std::cerr << "accept failed: " << err << "\n";
            continue;
        }

        // 클라이언트마다 새 스레드 생성 (필요시 쓰레드풀로 교체 가능)
        std::thread t(&ServerImpl::clientWorker, clientSock, clientAddr); // 여기서 관련함수
        t.detach();
    }

    closeListenSocket();
    std::cout << "[Server] Stopped.\n";
}

void ServerImpl::serverStop() {
    running_.store(false);
    // accept 깨우기 위해 리스닝 소켓 닫기
    closeListenSocket();
}


void ServerImpl::clientWorker(SOCKET clientSock, sockaddr_storage addr) {
    
    // 1) 소켓 생성 시 관련 클래스 객체 생성
    //Todo    
    int id = counter++;
    ISocket* socket = new TcpSocket(counter,clientSock, addr);

    std::string line;
    // 접속자 로그
    logging(addr);
    // 1) 유저 정보 JSON 한 줄 수신
    if (!receive(clientSock, line)) {

        // 소켓 delete 후 함수종료
        delete socket;

    }

    // 2) JSON 파싱 및 검증
    std::string username;
    if (!parsingAndVerify(clientSock, line, username)) {

        // 소켓 delete 후 함수종료
        delete socket;

    }
    socket->setUsername(username); // 이름 넣기
    
    std::cout << "[Client] 새로운 사용자 -> username: " << username << "\n";

    // 3) ACK 응답(JSON)
    responseAck(clientSock, username);

    // 소켓에 아이디 부여해서 저장
    sockets[id] = socket;


    // 5) 로직 실행(while 루프) 
    socket->startListening();
     
    
    // 5) 소켓 종료, 딜리트
    sockets.erase(id);
    delete socket;
    closesocket(clientSock);
}
void ServerImpl::logging(sockaddr_storage addr) {
    char host[NI_MAXHOST]{}, serv[NI_MAXSERV]{};
    if (getnameinfo((sockaddr*)&addr, sizeof(addr), host, sizeof(host), serv, sizeof(serv),
        NI_NUMERICHOST | NI_NUMERICSERV) == 0) {
        std::cout << "[Client]  연결: " << host << ":" << serv << "\n";
    }
    else {
        std::cout << "[Client] 연결: \n";
    }

}

bool ServerImpl::receive(SOCKET clientSock, std::string& line)
{
    if (!recvLine(clientSock, line)) {
        std::cerr << "[Client] 읽기 실패\n";
        closesocket(clientSock);
        return false;
    }
    return true;
}

bool ServerImpl::parsingAndVerify(SOCKET clientSock, std::string& line, std::string& username) {
    try {
        json j = json::parse(line);
        if (!j.contains("username") || !j["username"].is_string()) {
            json err = {
                {"ok", false},
                {"error", "잘못된 형식입니다. 요구 형식: {username:string}"}
            };
            auto s = err.dump() + "\n";
            send(clientSock, s.c_str(), (int)s.size(), 0);
            closesocket(clientSock);
            return false;
        }
        username = j["username"].get<std::string>();
    }
    catch (const std::exception& e) {
        json err = { {"ok", false}, {"error", std::string("json 파싱 에러: ") + e.what()} };
        auto s = err.dump() + "\n";
        send(clientSock, s.c_str(), (int)s.size(), 0);
        closesocket(clientSock);
        return false;
    }
    return true;
}

void ServerImpl::responseAck(SOCKET clientSock, std::string username)
{
    {
        json ack = {
            {"ok", true},
            {"msg", "USERINFO RECEIVED"},
            {"name", username}
        };
        auto s = ack.dump() + "\n";
        send(clientSock, s.c_str(), (int)s.size(), 0);
    }
}
