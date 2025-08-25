#pragma once
#include "Request.h"

class CardRevealed : public Request {
private:
    int socketId;
    int roomId;
    int playerId;

public:
    CardRevealed(int socketId, int roomId, int playerId)
        : socketId(socketId), roomId(roomId), playerId(playerId) {
    }

    ~CardRevealed() {}

    virtual void execute() override;
};
