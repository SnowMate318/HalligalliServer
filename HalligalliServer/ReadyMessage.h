#pragma once
#include "RequestMessage.h"

class ReadyMessage : public RequestMessage {
private:
    int room_id;
    int player_id;

public:
    ReadyMessage(int room_id, int player_id)
        : room_id(room_id), player_id(player_id) {
    }

    ~ReadyMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};
