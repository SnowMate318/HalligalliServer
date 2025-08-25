#pragma once
#include "Request.h"
#include "Lobby.h"
class GameStart : public Request {
private:
    int socketId;
    int roomId;

public:
    GameStart(int socketId, int roomId)
        : socketId(socketId), roomId(roomId) {}
    ~GameStart() {}

    virtual void execute()override;
};
