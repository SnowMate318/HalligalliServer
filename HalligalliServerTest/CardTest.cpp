#include "gtest/gtest.h"
#include "../HalligalliServer/CardImpl.h"

class CardTest : public ::testing::Test {
protected:
    int testCardNumData[8] = { 1,5,6,10,11,15,16,20 };
    int testCntData[8] = { 1,5,1,5,1,5,1,5 };
    Fruit testFruitsData[8] = {
        Fruit::APPLE,
        Fruit::APPLE,
        Fruit::BANANA,
        Fruit::BANANA,
        Fruit::GRAPE,
        Fruit::GRAPE,
        Fruit::WATERMELON,
        Fruit::WATERMELON
    };
};

// 매크로로 중복 줄이기
#define CARD_TEST(index, name)                              \
TEST_F(CardTest, Card##index##_##name) {                    \
    CardImpl card(testCardNumData[index]);                  \
    EXPECT_EQ(card.getCardNum(), testCardNumData[index]);   \
    EXPECT_EQ(card.getFruitCnt(), testCntData[index]);      \
    EXPECT_EQ(card.getFruit(), testFruitsData[index]);      \
}

CARD_TEST(0, Apple1)
CARD_TEST(1, Apple5)
CARD_TEST(2, Banana1)
CARD_TEST(3, Banana5)
CARD_TEST(4, Grape1)
CARD_TEST(5, Grape5)
CARD_TEST(6, Watermelon1)
CARD_TEST(7, Watermelon5)
