#pragma once
#include "RequestMessage.h"

class ExitRoomMessage : public RequestMessage {
private:
    int room_id;
    int player_id;

public:
    ExitRoomMessage(int room_id, int player_id)
        : room_id(room_id), player_id(player_id) {
    }

    ~ExitRoomMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};
