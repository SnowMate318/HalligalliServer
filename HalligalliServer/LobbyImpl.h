#pragma once  
#include "ILobby.h"  
#include "ILobbyPlayer.h"  
#include "IRoom.h"  
#include <map>  

class LobbyImpl : public ILobby { 

    int cnt = 1;  
    std::map<int, IRoom*> rooms;  
    std::map<int, ILobbyPlayer*> players;  

    // ½Ì±ÛÅæ ±¸Çö  
    LobbyImpl() = default;  
    ~LobbyImpl() override = default;  

    LobbyImpl(const LobbyImpl&) = delete;  
    LobbyImpl& operator=(const LobbyImpl&) = delete;  
    LobbyImpl(LobbyImpl&&) = delete;  
    LobbyImpl& operator=(LobbyImpl&&) = delete;  

public:  

    static ILobby* instance() {  
        static LobbyImpl inst;  
        return &inst;   // LobbyImpl °´Ã¼ ÁÖ¼ÒÁö¸¸ ILobby*·Î ¹ÝÈ¯  
    }  

    virtual void enterLobbyPlayer(int playerId, ILobbyPlayer* lobbyPlayer) override;  
    virtual void exitLobbyPlayer(int playerId) override;  

    virtual IRoom* createRoom(std::string roomName) override;  
    virtual void deleteRoom(int id) override;  
    virtual std::vector<IRoom*> getRooms(int page) override;  
    virtual IRoom* getRoomById(int roomId) override;  
};