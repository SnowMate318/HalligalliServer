//#include "gtest/gtest.h"
//#include "../HalligalliServer/FrontCardsImpl.h"
//#include "../HalligalliServer/CardImpl.h"
//
//#define MAX_SIZE 4
//
//class FrontCardsTest : public ::testing::Test {
//protected:
//    FrontCardsImpl frontCards = FrontCardsImpl();
//
//    void SetUp() override {
//        frontCards.updateCard(0,new CardImpl(2));
//        frontCards.updateCard(1,new CardImpl(3));
//    }
//};
//
//TEST_F(FrontCardsTest, 과일_체크_및_카드_추가_테스트) {
//
//    EXPECT_EQ(frontCards.checkFiveFruit(), true);
//    frontCards.updateCard(2, new CardImpl(2));
//    EXPECT_EQ(frontCards.checkFiveFruit(), false);
//
//}
//TEST_F(FrontCardsTest, 과일_체크_및_카드_제거_테스트) {
//
//    EXPECT_EQ(frontCards.checkFiveFruit(), true);
//    frontCards.resetCard(1);
//    EXPECT_EQ(frontCards.checkFiveFruit(), false);
//
//}
//TEST_F(FrontCardsTest, 프론트카드_인덱스_오류_테스트) {
//
//    EXPECT_ANY_THROW(frontCards.updateCard(MAX_SIZE, new CardImpl(2))); // Todo: 예외 세분화
//    EXPECT_NO_THROW(frontCards.updateCard(MAX_SIZE - 1, new CardImpl(2)));
//    EXPECT_ANY_THROW(frontCards.updateCard(-1, new CardImpl(2)));
//    EXPECT_NO_THROW(frontCards.updateCard(0, new CardImpl(2)));
//    
//    EXPECT_ANY_THROW(frontCards.resetCard(MAX_SIZE));
//    EXPECT_NO_THROW(frontCards.resetCard(MAX_SIZE-1));
//    EXPECT_ANY_THROW(frontCards.resetCard(-1));
//    EXPECT_NO_THROW(frontCards.resetCard(0));
//    
//}
