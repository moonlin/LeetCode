/********************************************

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, 
"()" and "()[]{}" are all valid but "(]" and "([)]" are not.

********************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
	 bool isValid(const std::string& str) 
	 {
		std::stack<char> token;
		for (uint i = 0; i < str.size(); ++i) {
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
				token.push(str[i]);
				continue;
			}

			if (token.empty()) return false;
			if (validPair(str[i], token.top())) token.pop();
		}

		return token.empty();
	 } 

	bool validPair(char cc1, char cc2) {
		if (cc1 == ')') return cc2 == '(';
		if (cc1 == ']') return cc2 == '[';
		if (cc1 == '}') return cc2 == '{';
	}
};

int main()
{
	std::string str("[][{[{{}}[][]{{}}]}]");
	Solution solve;
	bool ret = solve.isValid(str);

	getchar();
	return 0;
}
