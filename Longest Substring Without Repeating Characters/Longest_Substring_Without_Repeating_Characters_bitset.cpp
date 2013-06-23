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

		int charSet[26] = {0};
		charSet[str[0] - 'a'] = 1;
		uint max = 0;
		for (uint i = 1; i < str.size(); ++i) {
			if (charSet[str[i] - 'a'] == 1) {
				max = std::max(max, count(charSet, 26));
				memset(charSet, 0, sizeof(charSet));
				std::string::size_type pos = str.rfind(str[i], i-1);
				for (++pos; pos < i; ++pos) {
					charSet[str[pos] - 'a'] = 1;
				}
				
			}

			charSet[str[i] - 'a'] = 1;
		}

		return std::max(max, count(charSet, 26));
	}

	uint count(int charSet[], int size) 
	{
		uint num = 0;
		for (int i = 0; i < size; ++i)
		{
			if (charSet[i] == 1) ++num;
		}

		return num;
	}
};
