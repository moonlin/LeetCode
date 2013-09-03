/*************************************************

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

*************************************************/

class Solution {
public:
    int lengthOfLastWord(const char* s)
	{
		std::string str(s);
		std::string::size_type pos = str.find_last_not_of(" ");
		if (pos == std::string::npos) return 0;

		std::string::size_type pos_e = pos;
		pos = str.find_last_of(" ", pos_e);
		if (pos == std::string::npos) pos = -1;

		return pos_e - pos;
	}          
};
