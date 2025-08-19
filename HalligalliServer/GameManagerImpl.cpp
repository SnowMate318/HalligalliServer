#include "GameManagerImpl.h"
#include "PlayerDeckImpl.h"
#include "GameMessage.h"


void GameManagerImpl::addPlayers(int roomPlayerIndex, IGamePlayer* gamePlayer)
{

	if (players.size() >= playerCount) return;

	players[roomPlayerIndex] = gamePlayer;
	playerDecks[roomPlayerIndex] = new PlayerDeckImpl();
}

void
GameManagerImpl::playCard(int playerId)
{
	ICard* card = playerDecks[playerId]->giveCard();
	IGamePlayer* gamePlayer = players[playerId];

	if (card == nullptr) {
		gamePlayer->die();

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
	IGamePlayer* player = players[playerId];

	for (int i = 1; i <= playerCount; i++) {
		targetId = (playerId + i) % playerCount;

		if (player->isAlive()) continue;

		card = playerDecks[playerId]->giveCard();
		if (card == nullptr) {
			player->die();
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
	IGamePlayer* player = players[playerId];
	player->die();
	
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
	//players[playerId]->sendMessageToSocket(message);
}

void 
GameManagerImpl::sendMessageToAll()
{
	GameMessage message = createInfoMessage();
	

	for (int i = 0; i < playerCount; i++) {
        for (auto& pair : players) {  
            IGamePlayer* player = pair.second;  
            if (player->isAlive()) {
                // player->sendMessageToSocket(message);  
            }  
        }

	}
}


GameMessage
GameManagerImpl::createInfoMessage()
{ 
	std::vector<IGamePlayer*> playerVector;
	for (auto& pair : players) {
		playerVector.push_back(pair.second);
	}

	return GameMessage(
		gameStatusManager->getGameStatus(),
		gameStatusManager->getTargetPlayer(),
		gameStatusManager->getNextTurnPlayer(),
		playerVector,
		this->frontCards
	);
}