#include <iostream>
#include <string>

using namespace std;


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
	void guess(string str) {
		checkIllegalArguments(str);
	}
};
