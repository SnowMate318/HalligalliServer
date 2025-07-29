#include "gtest/gtest.h"
#include "ICard.h"
#include "CardImpl.h"

TEST(MyClassTest, AddTest) {

    int testCardNumData[8] = { 1,5,6,10,11,15,16,20 };
    int testCntData[8] = { 1,5,1,5,1,5,1,5 };
    Fruit testFruitsData[8] = {
        Fruit::APPLE ,
        Fruit::APPLE,
        Fruit::BANANA,
        Fruit::BANANA,
        Fruit::GRAPE,
        Fruit::GRAPE,
        Fruit::WATERMELON,
        Fruit::WATERMELON
    };



    CardImpl* testCards[8];
    for (int i = 0; i < 8; i++) {
        testCards[i] = new CardImpl(i);
    }



    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(testCards[i]->getCardNum(), testCardNumData[i]);
        EXPECT_EQ(testCards[i]->getFruitCnt(), testCntData[i]);
        EXPECT_EQ(testCards[i]->getFruit(), testFruitsData[i]);
    }

}