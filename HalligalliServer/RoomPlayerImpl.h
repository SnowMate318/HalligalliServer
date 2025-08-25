#pragma once
#include "IRoomPlayer.h"
#include "IPlayerManager.h"

class RoomPlayerImpl : public IRoomPlayer {
private:
	IRoom* room;
	IPlayerManager* playerManager;

	bool isReady;
	int roomId;
	int roomPlayerIndex;
	
public:

	RoomPlayerImpl(IPlayerManager* playerManager, IRoom* room) : playerManager(playerManager), room(room) {
		
		isReady = false;
		roomId = -1;
		roomPlayerIndex = -1;
	}
	~RoomPlayerImpl() {}

	virtual void ready()override;
	virtual void unready()override;
	virtual bool getReady()override;
	virtual void startGame(int roomId, int roomPlayerIndex, IGame* game)override;
	virtual void exitRoom()override;
	virtual void setRoomInfo(int roomId, int roomPlayerIndex)override;

	//sendMessageToPlayerManager();
};