/******************************************

Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

******************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
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
	int lengthOfLongestSubstring(string& str)
	{
		if (str.empty()) return 0;

		std::set<char> charSet;
		uint max = 0;
		for (int i = 0; i < str.size(); ++i) {
			charSet.clear();
			charSet.insert(str[i]);
			for (int j = i+1; j < str.size(); ++j) {
				if (charSet.find(str[j]) != charSet.end()) {
					max = std::max(max, charSet.size());
					break;
				}

				charSet.insert(str[j]);
			}

			max = std::max(max, charSet.size());
		}

		return std::max(max, charSet.size());
	}
};

int main()
{
	std::string str("xnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxz");

	Solution solve;
	int ret = solve.lengthOfLongestSubstring(str);

	getchar();
	return 0;
}
