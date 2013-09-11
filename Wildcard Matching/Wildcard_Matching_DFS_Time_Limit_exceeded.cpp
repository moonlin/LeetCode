/**************************************
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false

**************************************/
//Run Status: Time Limit Exceeded...

class Solution {
public:
    bool isMatch(const char* s, const char* p)
	{
		if (*p == '\0') return *s == '\0';

		if (*p != '*') {
			return isEqual(s, p)? isMatch(s+1, p+1): false;
		}

		for (const char* ptr = s; *ptr; ++ptr) {
			if (isMatch(ptr+1, p+1)) return true;
		}

		return isMatch(s, p+1);
	}          

	bool isEqual(const char* c1, const char* c2)
	{
		return (*c1 == *c2) || (*c1 != '\0' && *c2 == '?');
	}

};
