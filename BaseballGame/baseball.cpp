#include <iostream>
#include <string>

using namespace std;


class Baseball {
public:
	void guess(string str) {
		if (str.length() <= 2)
			throw length_error("invalid string size");

		for( char ch : str)
			if(!(ch >= '0' && ch <= '9'))
				throw invalid_argument("invalid arguments");
	}
};
