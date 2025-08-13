#pragma once
#include "RequestMessage.h"

class PressBellMessage : public RequestMessage {
private:

    int press_time_diff;

public:
    PressBellMessage(int press_time_diff)
        : press_time_diff(press_time_diff) {
    }

    ~PressBellMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};
