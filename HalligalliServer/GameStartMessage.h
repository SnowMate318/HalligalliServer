#pragma once
#include "RequestMessage.h"

class GameStartMessage : public RequestMessage {
private:
    int room_id;

public:
    GameStartMessage(int room_id)
        : room_id(room_id) {}

    ~GameStartMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager)override;
};
