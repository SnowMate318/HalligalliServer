#pragma once
#include "Request.h"
#include "Lobby.h"
#include "IRoom.h"
class JoinRoom : public Request {
private:
    int socketId;
    int roomId;

public:
    JoinRoom(int socketId, int roomId) : socketId(socketId), roomId(roomId) {}
    ~JoinRoom() {}

    virtual void execute() override;
};