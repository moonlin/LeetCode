/**********************************

Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", 
which has length = 4.

**********************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
	int longestValidParentheses(const string& str) 
	{
		std::vector<int> dp(str.size(), 0);
		int max = 0;
		for (int i = 1; i < str.size(); ++i) {
			if (str[i] == '(') dp[i] = 0;
			else if (str[i] == ')') {
				if (str[i-1] == '(' && i-1 > 0) dp[i] = dp[i-2] + 1;
				else if (str[i-1] == '(' && i-1 <= 0) dp[i] = 1;
				else if (str[i-1] == ')' && dp[i-1]) {
					if (i-1-dp[i-1]*2 >= 0 && str[i-1-dp[i-1]*2] != str[i]) {
						dp[i] = dp[i-1]+1+(i-dp[i-1]*2-2>=0? dp[i-dp[i-1]*2-2]: 0);
					}
				} 

				max = std::max(max, dp[i]);
			}
		}

		return max*2;
	} 

};

int main()
{
	//std::string str("))(((())))()())()()((()()(");
	std::string str("()(())");
	Solution solve;
	int ret = solve.longestValidParentheses(str);

	getchar();
	return 0;
}
