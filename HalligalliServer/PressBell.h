#pragma once
#include "Request.h"
#include "GamePlayerImpl.h"

class PressBell : public Request {
private:
    int socketId;
    int roomId;
    int roomPlayerId;
    int press_time_diff;

public:
    PressBell(int socketId, int roomId, int roomPlayerId, int pressTimeDiff)
        : socketId(socketId), roomId(roomId), roomPlayerId(roomPlayerId), press_time_diff(press_time_diff) {
    }

    ~PressBell() {}

    virtual void execute() override;
};
