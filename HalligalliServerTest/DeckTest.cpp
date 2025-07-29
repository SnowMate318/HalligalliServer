#include "gtest/gtest.h"  
#include "../HalligalliServer/DeckImpl.h"  
#include "../HalligalliServer/CardImpl.h"  

class DeckTest : public ::testing::Test {  
protected:  
    int testCardNumData[8] = { 1, 5, 6, 10, 11, 15, 16, 20 };  
    DeckImpl deck1;  
    DeckImpl deck2;  

    void SetUp() override {  
        for (int i = 0; i < 2; i++) {  
            ICard* card = new CardImpl(testCardNumData[i]);  
            deck1.takeCard(card);  
        }  
        for (int i = 0; i < 8; i++) {
            ICard* card = new CardImpl(testCardNumData[i]);
            deck2.takeCard(card);
        }
    }  
};

TEST_F(DeckTest, 카드_주기_테스트) {

    EXPECT_EQ(deck1.giveCard()->getCardNum(), 1);
    EXPECT_EQ(deck1.giveCard()->getCardNum(), 5);
    EXPECT_EQ(deck1.giveCard(), nullptr);
}
TEST_F(DeckTest, 카드_합치기_테스트) {

    deck1.mergeDeck(&deck2);

    EXPECT_EQ(deck1.getCardCount(), 10);
    EXPECT_EQ(deck2.getCardCount(), 0);

    deck1.giveCard();
    deck1.giveCard();
    EXPECT_EQ(deck1.giveCard()->getCardNum(), 1); // 기존 deck2의 첫번째 카드를 반환하는지 확인
}

TEST_F(DeckTest, 카드_받기_테스트) {

    ICard* card = new CardImpl(1);
    deck1.takeCard(card);

    EXPECT_EQ(deck1.giveCard()->getCardNum(), 1);
    EXPECT_EQ(deck1.giveCard()->getCardNum(), 5);
    EXPECT_EQ(deck1.giveCard()->getCardNum(), 1);
    EXPECT_EQ(deck1.giveCard(), nullptr);
}
