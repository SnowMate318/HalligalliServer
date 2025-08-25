#include "gtest/gtest.h"
#include "../HalligalliServer/GameStatusManagerImpl.h"
#define MAX_PLAYER 4

class GameStatusManagerTest : public ::testing::Test {
protected:
    GameStatusManagerImpl gameStatusManager = GameStatusManagerImpl(MAX_PLAYER);

};

TEST_F(GameStatusManagerTest, �ʱ�ȭ_�׽�Ʈ) {

    EXPECT_EQ(gameStatusManager.getGameStatus(),Action::NEXT_TURN);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),-1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),0);
}

TEST_F(GameStatusManagerTest, �޼ҵ�_����_�׽�Ʈ) {
    gameStatusManager.updateNextTurn();
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::NEXT_TURN);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),-1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);

    gameStatusManager.updateNextTurn();
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(), 2);

    gameStatusManager.updateNextTurn();
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(), 3);

    gameStatusManager.updateNextTurn();
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(), 0);
}

TEST_F(GameStatusManagerTest, ��_Ȱ��ȭ_�Լ�_�׽�Ʈ) {
    gameStatusManager.updateBellActivate();
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::BELL_ACTIVATE);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),-1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, ��_�¸���_�Լ�_�׽�Ʈ) {
    gameStatusManager.updateBellWin(1);
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::BELL_WIN);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, �÷��̾�_���_�Լ�_�׽�Ʈ) {
    gameStatusManager.updatePlayerDie(1);
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::PLAYER_DIE);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, �г�Ƽ_����_�Լ�_�׽�Ʈ) {
    gameStatusManager.updatePenalty(1);
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::PENALTY);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, ����_�Ŵ���_�ε���_����_�׽�Ʈ) {

    EXPECT_ANY_THROW(gameStatusManager.updatePenalty(MAX_PLAYER));
    EXPECT_NO_THROW(gameStatusManager.updatePenalty(MAX_PLAYER-1));
    EXPECT_ANY_THROW(gameStatusManager.updatePenalty(-1));
    EXPECT_NO_THROW(gameStatusManager.updatePenalty(0));

    EXPECT_ANY_THROW(gameStatusManager.updateBellWin(MAX_PLAYER));
    EXPECT_NO_THROW(gameStatusManager.updateBellWin(MAX_PLAYER-1));
    EXPECT_ANY_THROW(gameStatusManager.updatePenalty(-1));
    EXPECT_NO_THROW(gameStatusManager.updatePenalty(0));

    
}



