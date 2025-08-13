#pragma once
#include "RequestMessage.h"

class FindRoomMessage : public RequestMessage {
private:
    int page;

public:
    FindRoomMessage(int page) : page(page) {}
    ~FindRoomMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};