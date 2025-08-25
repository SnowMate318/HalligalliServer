#pragma once
#include "Request.h"
#include "Lobby.h"
#include "SocketPlayerManager.h"
#include "RoomInfoMessage.h"

class FindRoom : public Request {
private:
    int socketId;
    int page;

public:
    FindRoom(int socketId, int page) : socketId(socketId), page(page) {}
    ~FindRoom() {}

    virtual void execute() override;
};
