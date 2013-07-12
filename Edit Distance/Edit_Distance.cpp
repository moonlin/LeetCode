/*********************************************************

Given two words word1 and word2, find the minimum number of steps 
required to convert word1 to word2. 
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*********************************************************/

class Solution {
public:
    int minDistance(std::string& word1, std::string& word2)
	{
		if (word1.empty() && word2.empty()) return 0;
		if (word1.empty() || word2.empty()) return 1;

		std::vector<std::vector<int>> dp(word1.size(), std::vector<int>(word2.size(), 0));
		if (word1[0] != word2[0]) dp[0][0] = 1;

		int flag = dp[0][0]==1? false: true;
		for (uint i = 1; i < word1.size(); ++i) {
			if (word1[i] == word2[0] && !flag) {
				dp[i][0] = dp[i-1][0];
				flag = true;
			} else {
				dp[i][0] = dp[i-1][0] + 1;
			}
		}

		flag = dp[0][0]==1? false: true;
		for (uint j = 1; j < word2.size(); ++j) {
			if (word1[0] == word2[j] && !flag) {
				dp[0][j] = dp[0][j-1];
				flag = true;
			} else {
				dp[0][j] = dp[0][j-1] + 1;
			}
		}

		for (uint i = 1; i < word1.size(); ++i) {
			for (uint j = 1; j < word2.size(); ++j) {
				dp[i][j] = std::min(dp[i-1][j]+1, dp[i][j-1]+1);
				int plus = word1[i]==word2[j]? 0: 1;
				dp[i][j] = std::min(dp[i][j], dp[i-1][j-1]+plus);
			}
		}

		return dp.back().back();
		// return dp[word1.size()-1][word2.size()-1];
	}
};
