#include "pch.h"
#include "../BaseballGame/baseball.cpp"

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
	assertIllegalArgument("121");

}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	Baseball game;
	GuessResult result = game.guess("123");

	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIf2Strikes) {
	Baseball game;
	GuessResult result = game.guess("124");
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIf1Strike) {
	Baseball game;
	GuessResult result = game.guess("154");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIf1Strike1Ball) {
	Baseball game;
	GuessResult result = game.guess("142");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(1, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIf1Ball) {
	Baseball game;
	GuessResult result = game.guess("451");

	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(1, result.balls);
}