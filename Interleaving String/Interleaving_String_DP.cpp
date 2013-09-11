/****************************************Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.For example,Given:s1 = "aabcc",s2 = "dbbca",When s3 = "aadbbcbcac", return true.When s3 = "aadbbbaccc", return false.****************************************/class Solution {public:    bool isInterleave(std::string& s1, std::string& s2, std::string& s3)	{		return this->isInterleave_impl(s1, s2, s3);	}	bool isInterleave_impl(std::string& s1, std::string& s2, std::string& s3)	{		if (s1.size() + s2.size() != s3.size()) return false;		std::vector<std::vector<bool>> dp				(s1.size()+1, std::vector<bool> (s2.size()+1, false));		dp[0][0] = true;		for (uint i = 1; i <= s1.size(); ++i) {			if (s1[i-1] == s3[i-1]) {				dp[i][0] = dp[i-1][0];			} else break;		}				for (uint j = 1; j <= s2.size(); ++j) {			if (s2[j-1] == s3[j-1]) {				dp[0][j] = dp[0][j-1];							} else break;		}		for (uint i = 1; i < s1.size()+1; ++i) {			for (uint j = 1; j < s2.size()+1; ++j) {				char cc1 = s1[i-1];				char cc2 = s2[j-1];				char cc3 = s3[i+j-1];				if (cc1 != cc3 && cc2 != cc3) dp[i][j] = false;				else if (cc1 == cc3 && cc2 != cc3) dp[i][j] = dp[i-1][j];				else if (cc1 != cc3 && cc2 == cc3) dp[i][j] = dp[i][j-1];				else if (cc1 == cc3 && cc2 == cc3) {					dp[i][j] = dp[i][j-1] | dp[i-1][j];				}			}		}		return dp[s1.size()][s2.size()];	}	};