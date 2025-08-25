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
        executeCommand(buf);
    }
}
void TcpSocket::jsonSend(ResponseMessage* message)
{
    json response = message->toJson();
    auto s = response.dump() + "\n";
    send(clientSock, s.c_str(), (int)s.size(), 0);
#if _DEBUG

#endif
}

json TcpSocket::messageToJson(Message* message)
{
    return json();
}

Request* TcpSocket::getRequest(char bytes[])
{
    json j = json::parse(bytes);
    Action action = j["action"];
    Request* request = nullptr;

    switch (action) {

    case CREATE_ROOM:
        request = new CreateRoom(socketId, j["room_title"]);
        break;
    case FIND_ROOM:
        request = new FindRoom(socketId, j["page"]);
        break;
    case JOIN_ROOM:
        request = new JoinRoom(socketId, j["room_id"]);
        break;
    case EXIT_ROOM:
        request = new ExitRoom(socketId, j["room_id"], j["room_player_id"]);
        break;
    case READY:
        request = new Ready(socketId, j["room_id"], j["room_player_id"]);
        break;
    case UNREADY:
        request = new Unready(socketId, j["room_id"], j["room_player_id"]);
        break;
    case GAME_STARTED:
        request = new GameStart(socketId, j["room_id"]);
        break;
    case CARD_REVEALED:
        request = new CardRevealed(socketId, j["room_id"], j["room_player_id"]);
        break;
    case PRESS_BELL:
        request = new PressBell(socketId, j["room_id"], j["room_player_id"], j["press_time_diff"]);
        break;
    case PENALTY_GIVEN:
        request = new PenaltyGiven(socketId, j["room_id"], j["room_player_id"]);
        break;

        // 제외:PLAYER_EXIT_IN_GAME, NULL_ACTION, GAME_WIN, BELL_WIN
    }

    return request;
}

void TcpSocket::executeCommand(char bytes[])
{
    Request* request = getRequest(bytes);
    if (request == nullptr) {

        //Todo: 오류메세지 반환


    }
    request->execute();

    delete request;
   
}