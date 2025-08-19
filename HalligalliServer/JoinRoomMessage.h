#pragma once
#include "RequestMessage.h"

class JoinRoomMessage : public RequestMessage {
private:
    int roomId;

public:
    JoinRoomMessage(int room_id) : roomId(roomId) {}
    ~JoinRoomMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};