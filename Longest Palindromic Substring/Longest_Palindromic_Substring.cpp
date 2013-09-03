/**********************************

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there 
exists one unique longest palindromic substring.

**********************************/

class Solution {
public:
	std::string longestPalindrome(const string& str)
	{
		if (str.size() == 0 || str.size() == 1) return str;

		int gmax = 0;
		int max_s = 0;
		for (uint i = 1; i < str.size(); ++i) {
			int len = 0;
			int pos = countPalindrome(str, i-1, i, len);
			if (gmax < len) {
				gmax = len;
				max_s = pos;
			}

			pos = countPalindrome(str, i-1, i+1, len);
			if (gmax < len) {
				gmax = len;
				max_s = pos;
			}

		}

		return str.substr(max_s, gmax);
	}

	int countPalindrome(const string& str, int s, int e, int& len)
	{
		while (s >= 0 && e < str.size()) {
			if (str[s] == str[e]) {
				--s;
				++e;
				continue;
			}

			len = e-s-1;
			return s+1;
		}

		len = e-s-1;
		return s+1;
	}

	// Time Limit Exceeded...
	std::string longestPalindrome(const string& str)
	{
		if (str.size() == 0 || str.size() == 1) return str;

		int gmax = 0;
		int max_s = 0;
		std::vector<std::vector<bool>> dp(str.size(), std::vector<bool> (str.size(), false));
		for (uint k = 0; k < 2; ++k) {
			for (uint i = 0; i < str.size(); ++i) {
				if (str[i] == str[i+k]) {
					dp[i][i+k] = true;
					if (gmax < (i+k - i + 1)) {
						gmax = (i+k - i + 1);
						max_s = i;
					}
				}
			}
		}

		for (uint k = 2; k < str.size(); ++k) {
			for (uint i = 0; i < str.size()-k; ++i) {
				if (str[i] == str[i+k]) {
					dp[i][i+k] = dp[i+1][i+k-1];
					if (dp[i][i+k] && gmax < (k+1)) {
						gmax = k+1;
						max_s = i;
					}

				} else {
					dp[i][i+k] = false;
				}
			}
		}

		return str.substr(max_s, gmax); 
	}

};

int main()
{
	std::string str("abcfcba123414321111111123414321abcfcba");

	Solution solve;
	string ret = solve.longestPalindrome(str);

	getchar();
	return 0;
}
