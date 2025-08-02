#include "gtest/gtest.h"
#include "../HalligalliServer/MockTableDeck.h"
#include "../HalligalliServer/CardImpl.h"

class TableDeckTest : public ::testing::Test {
protected:
    MockTableDeck tableDeck;

    void SetUp() override {
        tableDeck.addCard(new CardImpl(1));
        tableDeck.addCard(new CardImpl(2));
    }
};

TEST_F(TableDeckTest, 카드_전달_테스트) {


    std::queue<ICard*> given_deck = tableDeck.giveAllCard();

    EXPECT_EQ(tableDeck.isDeckEmpty(), true);

    EXPECT_EQ(given_deck.front()->getCardNum(), 1);

    given_deck.pop();

    EXPECT_EQ(given_deck.front()->getCardNum(), 2);
}
