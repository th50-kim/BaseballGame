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
