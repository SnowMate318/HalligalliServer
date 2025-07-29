#pragma once  
#include "IPlayer.h"  
#include "IRoom.h"  
#include <unordered_map>  
#include <vector>  
#include <iostream>
class IPlayerRoomManager {  

private:
    std::unordered_map<int,IPlayer*> players;  
    std::unordered_map<int, IRoom*> rooms;
    std::vector<IRoom*> roomsvector; // 전체 방 조회 연산을 쉽게하기 위해
public:
    virtual void createPlayer(std::string playerName) = 0;
    virtual void deletePlayer(int playerId) = 0;
    virtual void createRoom(std::string roomName) = 0;
    virtual void deleteRoom(int roomId) = 0;
    virtual void playerEnterRoom(int roomId, int playerId) = 0;
    virtual void playerExitRoom(int roomId, int playerId) = 0;
    virtual std::vector<IRoom*> getRooms(int page) = 0;

    virtual void playerReady(int roomId, int playerNum) = 0;
    virtual void playerUnready(int roomId, int playerNum) = 0;
    virtual void gameStart(int roomId) = 0;
    virtual void ringBell(int roomId, int playerNum, int timeDiff) = 0;
    virtual void playCard(int roomId, int playerNum) = 0;
    virtual void getPenalty(int roomId, int playerNum) = 0;
    
};