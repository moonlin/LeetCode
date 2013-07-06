/************************************************************

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

************************************************************/

class Solution {
public:
    int numDistinct(std::string& S, std::string& T)
	{
		if (S.empty()) return 0;
		if (T.empty()) return S.size();

		std::vector<std::vector<int>> dp(S.size(), std::vector<int> (T.size(), 0));
		dp[0][0] = S[0]==T[0]? 1: 0;
		for (uint i = 1; i < S.size(); ++i) {
			if (S[i] == T[0]) dp[i][0] = dp[i-1][0] + 1;
			else dp[i][0] = dp[i-1][0];
		}

		for (uint i = 1; i < S.size(); ++i) {
			for (uint j = 1; j < T.size(); ++j) {
				if (S[i] == T[j]) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
				else dp[i][j] = dp[i-1][j];
			}
		}

		return dp[S.size()-1][T.size()-1];
	}
};
