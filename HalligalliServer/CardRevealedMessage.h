#pragma once
#include "RequestMessage.h"

class CardRevealedMessage : public RequestMessage {
private:
    int room_id;
    int player_id;

public:
    CardRevealedMessage(int room_id, int player_id)
        : room_id(room_id), player_id(player_id) {
    }

    ~CardRevealedMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};
