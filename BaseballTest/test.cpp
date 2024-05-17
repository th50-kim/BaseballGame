#include "pch.h"
#include "../BaseballGame/baseball.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched	) {
	Baseball game;

	EXPECT_THROW(game.guess(string("12")), length_error);
}