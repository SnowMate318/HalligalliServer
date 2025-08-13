#pragma once
#include "RequestMessage.h"

class JoinRoomMessage : public RequestMessage {
private:
    int room_id;

public:
    JoinRoomMessage(int room_id) : room_id(room_id) {}
    ~JoinRoomMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};