#pragma once
#include "RequestMessage.h"

class PenaltyGivenMessage : public RequestMessage {
private:

public:
    PenaltyGivenMessage() {}
    ~PenaltyGivenMessage() {}

    virtual void messageExecute(IPlayerManager* playerManager) override;
};
