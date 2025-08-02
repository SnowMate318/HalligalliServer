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

TEST_F(PlayerDeckTest, ī��_�ֱ�_�׽�Ʈ) {


    EXPECT_EQ(playerDeck.giveCard()->getCardNum(),1);
}
TEST_F(PlayerDeckTest, ī��_����_�׽�Ʈ) {

    playerDeck.mergeCard(tmpDeck);
    EXPECT_EQ(playerDeck.getCardCount(), 4);
    playerDeck.giveCard();
    EXPECT_EQ(playerDeck.giveCard()->getCardNum(),2);
    EXPECT_EQ(playerDeck.giveCard()->getCardNum(),3);
}
TEST_F(PlayerDeckTest, ī��_����_��_null_������_��ȯ) {

    playerDeck.giveCard();
    playerDeck.giveCard();
    EXPECT_EQ(playerDeck.giveCard(),nullptr);
}


