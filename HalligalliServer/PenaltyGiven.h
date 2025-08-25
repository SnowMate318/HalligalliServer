#pragma once
#include "Request.h"

class PenaltyGiven : public Request {
private:
    int socketId;
    int roomId;
    int roomPlayerId;

public:
    PenaltyGiven(int socketId, int roomId, int roomPlayerId) : socketId(socketId), roomId(roomId), roomPlayerId(roomPlayerId) {}
    ~PenaltyGiven() {}

    virtual void execute()override;
};
