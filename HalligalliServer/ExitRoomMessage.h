#pragma once
#include "RequestMessage.h"

class ExitRoomMessage : public RequestMessage {
private:
    int roomId;
    int roomPlayerIndex;

public:
    ExitRoomMessage(int roomId, int roomPlayerIndex)
        : roomId(roomId), roomPlayerIndex(roomPlayerIndex) {
    }

    ~ExitRoomMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};
