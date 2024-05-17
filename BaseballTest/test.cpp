#include "pch.h"
#include "../BaseballGame/baseball.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string str) {
		try {
			game.guess(str);
			FAIL();
		}
		catch (exception e) {
			
		}

	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidChar) {
	assertIllegalArgument("12");
	assertIllegalArgument("12c");

}
