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
//TEST_F(FrontCardsTest, ����_üũ_��_ī��_�߰�_�׽�Ʈ) {
//
//    EXPECT_EQ(frontCards.checkFiveFruit(), true);
//    frontCards.updateCard(2, new CardImpl(2));
//    EXPECT_EQ(frontCards.checkFiveFruit(), false);
//
//}
//TEST_F(FrontCardsTest, ����_üũ_��_ī��_����_�׽�Ʈ) {
//
//    EXPECT_EQ(frontCards.checkFiveFruit(), true);
//    frontCards.resetCard(1);
//    EXPECT_EQ(frontCards.checkFiveFruit(), false);
//
//}
//TEST_F(FrontCardsTest, ����Ʈī��_�ε���_����_�׽�Ʈ) {
//
//    EXPECT_ANY_THROW(frontCards.updateCard(MAX_SIZE, new CardImpl(2))); // Todo: ���� ����ȭ
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
