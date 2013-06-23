/**********************************

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there 
exists one unique longest palindromic substring.

**********************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

class Solution {
public:
	std::string longestPalindrome(const string& str)
	{
		if (str.size() == 0 || str.size() == 1) return str;

		int max = 0;
		int max_s = 0;
		for (int i = 1; i < str.size(); ++i) {
			int len = 0;
			int pos = countPalindrome(str, i-1, i, len);
			if (max < len) {
				max = len;
				max_s = pos+1;
			}

			pos = countPalindrome(str, i-1, i+1, len);
			if (max < len) {
				max = len;
				max_s = pos+1;
			}

		}

		return str.substr(max_s, max);
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
			return s;
		}

		len = e-s-1;
		return s;
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
