/******************************************

Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

******************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string& str)
	{
		if (str.empty()) return 0;

		std::set<char> charSet;
		charSet.insert(str[0]);
		uint max = 0;
		for (int i = 1; i < str.size(); ++i) {
			if (charSet.find(str[i]) != charSet.end()) {
				max = std::max(max, charSet.size());
				charSet.clear();
				std::string::size_type pos = str.rfind(str[i], i-1);
				for (++pos; pos < i; ++pos) {
					charSet.insert(str[pos]);
				}

			}

			charSet.insert(str[i]);
		}

		return std::max(max, charSet.size());
	}
};
