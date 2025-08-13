#include "GameManagerImpl.h"
#include "GameRoleImpl.h"

GameManagerImpl::GameManagerImpl(
	std::vector<Player*> players, 
	std::vector<IPlayerDeck*> playerDecks, 
	int playerCount,
	IBell* bell, 
	ITableDeck* tableDeck, 
	IFrontCards* frontCards, 
	IGameStatusManager* gameStatusManager)
{
	this->players = players;
	this->playerDecks = playerDecks;
	this->playerCount = playerCount;
	this->bell = bell;
	this->tableDeck = tableDeck;
	this->frontCards = frontCards;
	this->gameStatusManager = gameStatusManager;
}

GameManagerImpl::~GameManagerImpl()
{
}

void 
GameManagerImpl::playCard(int playerId)
{
	ICard* card = playerDecks[playerId]->giveCard();
    GameRoleImpl* playerRole = dynamic_cast<GameRoleImpl*>(players[playerId]->getRole());  

    if (playerRole == nullptr) {  
        return;  
    }

	if (card == nullptr) {
		playerRole->die();
		gameStatusManager->updatePlayerDie(playerId);
		return;
	}
	tableDeck->addCard(card);
	gameStatusManager->setNextTurnPlayer((playerId + 1) % playerCount);
	gameStatusManager->updateNextTurn();
}

void 
GameManagerImpl::penalty(int playerId)
{
	ICard* card;
	int targetId;
	GameRoleImpl* playerRole;
	for (int i = 1; i <= playerCount; i++) {
		targetId = (playerId + i) % playerCount;

		playerRole = dynamic_cast<GameRoleImpl*>(players[targetId]->getRole());

		if (playerRole->isPlayerAlive()) continue;

		card = playerDecks[playerId]->giveCard();
		if (card == nullptr) {
			playerRole->die();
			gameStatusManager->updatePlayerDie(playerId);
			return;
		}

		playerDecks[targetId]->takeCard(card);
	}
	gameStatusManager->updatePenalty(playerId);
}

void 
GameManagerImpl::playerDie(int playerId) // 플레이어가 나갔을 때 호출 (보통은 다른 메소드에서 호출)
{
	GameRoleImpl* playerRole = dynamic_cast<GameRoleImpl*>(players[playerId]->getRole());
	playerRole->die();
	
	if (gameStatusManager->getNextTurnPlayer() == playerId) {
		gameStatusManager->setNextTurnPlayer((playerId + 1) % playerCount);
	}
	gameStatusManager->updatePlayerDie(playerId);
}

void 
GameManagerImpl::pressBell(int playerId, int timeDiff)
{
	bell->ringBell(playerId, timeDiff);
}

void 
GameManagerImpl::giveRewardToBellWinner(int playerId)
{
	std::queue<ICard*> deck = tableDeck->giveAllCard();

	while (!deck.empty()) {
		playerDecks[playerId]->takeCard(deck.front());
		deck.pop();
	}
	gameStatusManager->updateBellWin(playerId);
}

void 
GameManagerImpl::sendMessageToPlayer(int playerId)
{
	GameMessage message = createInfoMessage();
	players[playerId]->sendMessageToSocket(message);
}

void 
GameManagerImpl::sendMessageToAll()
{
	GameMessage message = createInfoMessage();
	GameRoleImpl* playerRole;

	for (int i = 0; i < playerCount; i++) {
		playerRole = dynamic_cast<GameRoleImpl*>(players[i]->getRole());
		if (playerRole->isPlayerAlive()) {
			players[i]->sendMessageToSocket(message);
		}
	}
}


GameMessage
GameManagerImpl::createInfoMessage()
{ 
	return GameMessage(
		gameStatusManager->getGameStatus(),
		gameStatusManager->getTargetPlayer(),
		gameStatusManager->getNextTurnPlayer(),
		this->players,
		this->frontCards
	);
}