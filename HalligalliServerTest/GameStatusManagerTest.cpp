#include "gtest/gtest.h"
#include "../HalligalliServer/GameStatusManagerImpl.h"
#define MAX_PLAYER 4

class GameStatusManagerTest : public ::testing::Test {
protected:
    GameStatusManagerImpl gameStatusManager = GameStatusManagerImpl(MAX_PLAYER);

};

TEST_F(GameStatusManagerTest, 초기화_테스트) {

    EXPECT_EQ(gameStatusManager.getGameStatus(),Action::NEXT_TURN);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),-1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),0);
}

TEST_F(GameStatusManagerTest, 메소드_실행_테스트) {
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

TEST_F(GameStatusManagerTest, 벨_활성화_함수_테스트) {
    gameStatusManager.updateBellActivate();
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::BELL_ACTIVATE);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),-1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, 벨_승리자_함수_테스트) {
    gameStatusManager.updateBellWin(1);
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::BELL_WIN);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, 플레이어_사망_함수_테스트) {
    gameStatusManager.updatePlayerDie(1);
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::PLAYER_DIE);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, 패널티_적용_함수_테스트) {
    gameStatusManager.updatePenalty(1);
    EXPECT_EQ(gameStatusManager.getGameStatus(), Action::PENALTY);
    EXPECT_EQ(gameStatusManager.getTargetPlayer(),1);
    EXPECT_EQ(gameStatusManager.getNextTurnPlayer(),1);
}
TEST_F(GameStatusManagerTest, 상태_매니저_인덱스_오류_테스트) {

    EXPECT_ANY_THROW(gameStatusManager.updatePenalty(MAX_PLAYER));
    EXPECT_NO_THROW(gameStatusManager.updatePenalty(MAX_PLAYER-1));
    EXPECT_ANY_THROW(gameStatusManager.updatePenalty(-1));
    EXPECT_NO_THROW(gameStatusManager.updatePenalty(0));

    EXPECT_ANY_THROW(gameStatusManager.updateBellWin(MAX_PLAYER));
    EXPECT_NO_THROW(gameStatusManager.updateBellWin(MAX_PLAYER-1));
    EXPECT_ANY_THROW(gameStatusManager.updatePenalty(-1));
    EXPECT_NO_THROW(gameStatusManager.updatePenalty(0));

    
}



