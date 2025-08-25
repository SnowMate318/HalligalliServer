#pragma once  
#include "RoomImpl.h"
#include "IRoom.h"  
#include <map>  

class Lobby  { 

    int cnt = 1;  
    std::map<int, IRoom*> rooms;  

    // ½Ì±ÛÅæ ±¸Çö  
    Lobby() = default;
    ~Lobby() = default;

    Lobby(const Lobby&) = delete;
    Lobby& operator=(const Lobby&) = delete;
    Lobby(Lobby&&) = delete;
    Lobby& operator=(Lobby&&) = delete;

public:  

    static Lobby& instance() noexcept {
        static Lobby inst;
        return inst;
    }


    IRoom* createRoom(std::string roomName);  
    void deleteRoom(int id);  
    std::vector<IRoom*> getRooms(int page);  
    IRoom* getRoomById(int roomId);  
};