/**************************************************************************

A message containing letters from A-Z is being encoded to numbers 
using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, 
determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

**************************************************************************/
 
class Solution {
public:
	int numDecodings(const string& str)
	{
		if (str.empty()) return 0;

		vector<int> dp(str.size(), 0);
		if (str[0] != '0') dp[0] = 1;
		if (valid(str, 0)) dp[1] += 1;
		if (str[1] != '0') dp[1] += dp[0];

		for (uint i = 2; i < str.size(); ++i) {
			if (valid(str, i-1)) dp[i] += dp[i-2];
			if (str[i] != '0') dp[i] += dp[i-1];
		}

		return dp[str.size()-1];
	}

	bool valid(const std::string& str, int pos)
	{
		if (pos >= str.size()) return false;
		if (pos == str.size()-1) return false;
		if (str[pos] == '0') return false;

		int num = 0;
		int loop = 0;
		while (loop < 2 && pos < str.size()) {
			num = num * 10 + str[pos] - '0';
			++pos;
			++loop;
		}

		if (num > 26 || num < 1) return false;
		return true;
	}

};

int main()
{	
	// std::string str("10");
	std::string str("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948");
	Solution solve;
	int ret = solve.numDecodings(str);

	getchar();
	return 0;
}

