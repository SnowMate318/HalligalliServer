#pragma once
#include "Request.h"

class Unready : public Request {
private:
    int socketId;
    int roomId;
    int playerId;

public:
    Unready(int socketId, int roomId, int playerId)
        : socketId(socketId), roomId(roomId), playerId(playerId) {
    }

    ~Unready() {}

    virtual void execute() override;
};
