#include "PlayerImpl.h"
#include "LobbyRoleImpl.h"
#include "ILobby.h"



PlayerImpl::PlayerImpl(
	int playerId,
	std::string playerName,
	ISocketPlayerManager* socketPlayerManager,
	ILobby* lobby
)
{
	this->playerId = playerId;
	this->playerName = playerName;
	this->lobbyRole = new LobbyRoleImpl(lobby);
	this->roomRole = nullptr;
	this->gameRole = nullptr;

	this->socketPlayerManager = socketPlayerManager;
}

PlayerImpl::~PlayerImpl()
{
}

void 
PlayerImpl::sendMessageToSocket(Message message)
{
	socketPlayerManager->sendPlayerToSocket(message);
}

Message 
PlayerImpl::receiveMessageFromSocket()
{
	return socketPlayerManager->sendSocketToPlayer();
}


void  
PlayerImpl::setRole(RoleType roleType, IRole* role)  
{  
    switch (roleType) {  
    case LOBBY_ROLE:  
        this->lobbyRole = dynamic_cast<ILobbyRole*>(role);  
        break;  
    case ROOM_ROLE:  
        this->roomRole = dynamic_cast<IRoomRole*>(role);  
        break;  
    case GAME_ROLE:  
        this->gameRole = dynamic_cast<IGameRole*>(role);  
        break;  
    }  

    this->role = role;  
}

IRole* 
PlayerImpl::getRole()
{
	return this->role;
}

int 
PlayerImpl::getId()
{
	return this->playerId;
}

std::string 
PlayerImpl::getPlayerName()
{
	return this->playerName;
}
