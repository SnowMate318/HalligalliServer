#pragma once
#include "RequestMessage.h"

class GameStartMessage : public RequestMessage {
private:
    int roomId;

public:
    GameStartMessage(int roomId)
        : roomId(roomId) {}


    ~GameStartMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager)override;
};
