#include "gtest/gtest.h"
#include "../HalligalliServer/PlayerDeckImpl.h"
#include "../HalligalliServer/CardImpl.h"

class PlayerDeckTest : public ::testing::Test {
protected:
    PlayerDeckImpl playerDeck;

    std::queue<ICard*> tmpDeck;

    void SetUp() override {
        playerDeck.takeCard(new CardImpl(1));
        playerDeck.takeCard(new CardImpl(2));

        tmpDeck.push(new CardImpl(3));
        tmpDeck.push(new CardImpl(4));
    }
};

TEST_F(PlayerDeckTest, 카드_주기_테스트) {


    EXPECT_EQ(playerDeck.giveCard()->getCardNum(),1);
}
TEST_F(PlayerDeckTest, 카드_병합_테스트) {

    playerDeck.mergeCard(tmpDeck);
    EXPECT_EQ(playerDeck.getCardCount(), 4);
    playerDeck.giveCard();
    EXPECT_EQ(playerDeck.giveCard()->getCardNum(),2);
    EXPECT_EQ(playerDeck.giveCard()->getCardNum(),3);
}
TEST_F(PlayerDeckTest, 카드_없을_시_null_포인터_반환) {

    playerDeck.giveCard();
    playerDeck.giveCard();
    EXPECT_EQ(playerDeck.giveCard(),nullptr);
}


