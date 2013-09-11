/*******************************************************************************
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*******************************************************************************/

class Solution {
public:
	std::vector<std::vector<std::string>> partition(const string& s) 
	{
		result.clear();
		vector<string> tmpResult;
		dfs(s, 0, tmpResult);

		return result;
	}

	void dfs(const string& str, uint start, std::vector<std::string>& tmpResult)
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

private:
	std::vector<std::vector<std::string>> result;
};
