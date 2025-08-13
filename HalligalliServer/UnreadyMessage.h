#pragma once
#include "RequestMessage.h"

class UnreadyMessage : public RequestMessage {
private:
    int room_id;
    int player_id;

public:
    UnreadyMessage(int room_id, int player_id)
        : room_id(room_id), player_id(player_id) {
    }

    ~UnreadyMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};
