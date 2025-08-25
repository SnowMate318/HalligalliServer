#pragma once
#include "Request.h"
#include "Lobby.h"

class ExitRoom : public Request {
private:
    int socketId;
    int roomId;
    int roomPlayerIndex;

public:
    ExitRoom(int socketId, int roomId, int roomPlayerIndex)
        : socketId(socketId), roomId(roomId), roomPlayerIndex(roomPlayerIndex) {
    }

    ~ExitRoom() {}

    virtual void execute() override;
};
