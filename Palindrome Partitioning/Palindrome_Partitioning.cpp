/***
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

***/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
	vector<vector<string> > partition(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		
		result.clear();
		vector<string> tmpResult;
		dfs(s, 0, tmpResult);

		return result;
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

	void dfs(const string& str, uint start, vector<string>& tmpResult)
	{
		if (start  >= str.size())
		{
			this->result.push_back(tmpResult);

			return;
		}

		for (uint i = start; i < str.size(); ++i)
		{
			if (isPalindrome(str, start, i))
			{
				tmpResult.push_back(str.substr(start, i-start+1));
				dfs(str, i+1, tmpResult);
				tmpResult.pop_back();
			}
		}
	}

private:
	vector<vector<string> > result;
};


int main()
{
	string str = "coder";
	Solution solve;
	vector<vector<string> > result = solve.partition(str);

	uint minCut = str.size();
	vector<uint> minCutIndex;

	for (uint i = 0; i < result.size(); ++i)
	{
		for (uint j = 0; j < result[i].size(); ++j)
		{
			std::cout <<result[i][j] <<"  ";
		}

		if (minCut > result[i].size())
		{
			minCut = result[i].size();	
		}
		
		std::cout <<'\n';
	}

	for (uint i = 0; i < result.size(); ++i)
	{
		if (minCut == result[i].size())
			minCutIndex.push_back(i);
	}

	std::cout <<"\n\nSolution Num :" <<result.size() <<'\n';

	for (uint i = 0; i < minCutIndex.size(); ++i)
	{
		for (uint j = 0; j < result[minCutIndex[i]].size(); ++j)
		{
			std::cout <<result[minCutIndex[i]][j] <<"  ";
		}

		std::cout <<'\n';
	}
	
	std::cout <<"\nmin cut :" <<minCut-1 <<'\n';

	getchar();
	return 0;
}

