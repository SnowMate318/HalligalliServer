#pragma once
#include "Request.h"
#include "GamePlayerImpl.h"

class PressBell : public Request {
private:
    int socketId;
    int roomId;
    int roomPlayerId;
    int pressTimeDiff;

public:
    PressBell(int socketId, int roomId, int roomPlayerId, int pressTimeDiff)
        : socketId(socketId), roomId(roomId), roomPlayerId(roomPlayerId), pressTimeDiff(pressTimeDiff) {
    }

    ~PressBell() {}

    virtual void execute() override;
};
