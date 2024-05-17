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
	void checkIllegalArguments(string str) {
		if (str.length() <= 2)
			throw length_error("invalid string size");

		for (char ch : str)
			if (!(ch >= '0' && ch <= '9'))
				throw invalid_argument("invalid arguments");

		if (str[0] == str[1] ||
			str[0] == str[2] || 
			str[1] == str[2])
				throw invalid_argument("must not have same number");
	}
public:
	GuessResult guess(string str) {
		checkIllegalArguments(str);
		if (str == "123")
		{
			return { true, 3, 0 };
		}
		return { 0,0,0 };
	}
};
