#pragma once
#include "Request.h"

class Ready : public Request {
private:
    int socketId;
    int roomId;
    int playerId;

public:
    Ready(int socketId, int roomId, int playerId)
        : socketId(socketId), roomId(roomId), playerId(playerId) {
    }

    ~Ready() {}

    virtual void execute() override;
};
