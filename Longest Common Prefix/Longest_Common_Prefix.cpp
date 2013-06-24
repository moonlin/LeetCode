/******************************************

Write a function to find the longest common prefix string amongst an array of strings.

******************************************/

#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.empty()) return "";

		uint maxLen = strs[0].size();
		for (uint i = 1; i < strs.size(); ++i) {
			maxLen = std::min(maxLen, strs[i].size());
		}

		for (uint i = 1; i < strs.size(); ++i) {
			maxLen = std::min(maxLen, compare(strs[i-1], strs[i], maxLen));
		}

		return strs[0].substr(0, maxLen);
	}

	uint compare(const string& s1, const string& s2, int maxLen)
	{
		for (int i = 0; i < maxLen; ++i) {
			if (s1[i] != s2[i]) return i;
		}

		return maxLen;
	}

};

int main()
{
	vector<string> vec;
	vec.push_back("abcdxwde");
	vec.push_back("abcdxwdf");
	vec.push_back("abcdxwda");
	vec.push_back("abcdewda");
	vec.push_back("abcdvmooo");

	Solution solve;
	string ret = solve.longestCommonPrefix(vec);

	getchar();
	return 0;
}
