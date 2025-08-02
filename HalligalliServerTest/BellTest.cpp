#include "gtest/gtest.h"
#include "../HalligalliServer/MockBell.h"

class BellTest : public ::testing::Test {
protected:
    MockBell mockBell;

    void SetUp() override {
        mockBell.bellActivate();
    }
};

TEST_F(BellTest, ��_�︮��_�׽�Ʈ) {
    mockBell.ringBell(1, 100);
    mockBell.ringBell(2, 50);
    mockBell.ringBell(3, 200);

    EXPECT_EQ(mockBell.getWinner(), 2);
}
