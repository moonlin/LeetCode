#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int uint;
#define N 10
#define  M 10

class Solution {
public:
	int minCut(string s) 
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (i == j)
					memo[i][j] = 0;
				else
					memo[i][j] = -1;
			}
		}

		return dp(s, 0, s.size()-1);
	}

	// RunTime Error
	int dp(const string& str, uint i, uint j)
	{
		uint minNum = str.size();
		for (uint k = i; k <= j; ++k)
		{
			if (isPalindrome(str, i, k))
			{
				if (k == j) return 0;

				if (memo[k+1][j] == -1)
					memo[k+1][j] = dp(str, k+1, j);

				if (minNum > 1 + memo[k+1][j])
					minNum = 1 + memo[k+1][j];

				//
			}
		}

		return minNum;
	}


	bool isPalindrome(const string& str, uint i, uint j)
	{
		while (i < j)
		{
			if (str[i] != str[j])
				return false;

			++i;
			--j;
		}

		return true;
	}

	int memo[N][M];
};


int main()
{
	Solution solve;
	uint minCut = solve.minCut("seeslaveidemonstrateyetartsnomedievalsees");

	
	std::cout <<"\nmin cut :" <<minCut <<'\n';

	getchar();
	return 0;
}

