/*******************************************************************************
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
  
*******************************************************************************/

class Solution {
public:
	int minCut(const std::string& s) 
	{
		memo.clear();

		return this->minCut_impl(s);
	}


	int minCut_impl(const std::string& str)
	{
		uint n = str.size();
		memo.resize(n);
		for (uint i = 0; i < n; ++i)
		{
			memo[i].resize(n);
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
					memo[i][j] = 0;
				else
					memo[i][j] = -1;
			}
		}

		std::vector<int> dp(str.size(), INT_MAX);
		dp[str.size()-1] = 0;

		for (int i = n-2; i >= 0; --i) {
			if (isPalindrome(str, i, n-1)) {
				dp[i] = 0;
				continue;
			}

			for (int j = i; j < str.size()-1; ++j) {
				if (isPalindrome(str, i, j)) {
					dp[i] = std::min(dp[i], dp[j+1]+1);
				}
			}
		}

		return dp[0];
	}

	bool isPalindrome(const std::string& str, uint i, uint j)
	{
		if (memo[i][j] == 0) return true;
		if (memo[i][j] == 1) return false;

		if (i == j) return true;

		if (str[i] != str[j])
		{
			memo[i][j] = 1;
			return false;
		}
		
		if (i+1 == j)
		{
			memo[i][j] = 0;
			return true;
		}

		bool  ret = isPalindrome(str, i+1, j-1);
		memo[i][j] = ret? 0: 1;

		return ret;
	}

private:
	std::vector<std::vector<int>> memo;
};

int main()
{
	Solution solve;
	uint minCut = solve.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	std::cout <<"\nmin cut :" <<minCut <<'\n';
	
	minCut = solve.minCut("cabababcbc");
	std::cout <<"\nmin cut :" <<minCut <<'\n';

	minCut = solve.minCut("coder");
	std::cout <<"\nmin cut :" <<minCut <<'\n';
	return 0;
}
