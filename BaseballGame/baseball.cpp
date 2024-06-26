#include <iostream>
#include <string>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};
class Baseball {
private:
	string correct = "123";
private:
	void checkIllegalArguments(string str) {
		if (str.length() <= 2)
			throw length_error("invalid string size");

		for (char ch : str)
			if (!(ch >= '0' && ch <= '9'))
				throw invalid_argument("invalid arguments");

		if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2])
				throw invalid_argument("must not have same number");
	}
public:
	GuessResult guess(string guess) {
		checkIllegalArguments(guess);
		GuessResult result = { false, 0, 0 };

		for (int index = 0; index < correct.size(); index++) {
			if (guess[index] == correct[index])
				result.strikes++;
			else if (guess.find(correct[index]) != std::string::npos)
				result.balls++;
		}

		result.solved = (result.strikes == 3);
	
		return result;
	}
};
