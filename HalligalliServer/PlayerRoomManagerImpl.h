#pragma once
#include "IPLayerRoomManager.h"

class PlayerRoomManagerImpl : IPlayerRoomManager {
private:
    std::unordered_map<int, IPlayer*> players;
    std::unordered_map<int, IRoom*> rooms;
    std::vector<IRoom*> roomsvector; // 전체 방 조회 연산을 쉽게하기 위해

    //Todo: createPlayer 실행 시 private로 broadcaster에 방 정보를 구독하는 메소드 생성할 것 (delete시 unsub)
public:
    virtual void createPlayer(std::string playerName)override;
    virtual void deletePlayer(int playerId)override;
    virtual void createRoom(std::string roomName)override;
    virtual void deleteRoom(int roomId)override;
    virtual void playerEnterRoom(int roomId, int playerId)override;
    virtual void playerExitRoom(int roomId, int playerId)override;
    virtual std::vector<IRoom*> getRooms(int page)override;

    virtual void playerReady(int roomId, int playerNum)override;
    virtual void playerUnready(int roomId, int playerNum)override;
    virtual void gameStart(int roomId)override;
    virtual void ringBell(int roomId, int playerNum, int timeDiff)override;
    virtual void playCard(int roomId, int playerNum)override;
    virtual void getPenalty(int roomId, int playerNum)override;
};