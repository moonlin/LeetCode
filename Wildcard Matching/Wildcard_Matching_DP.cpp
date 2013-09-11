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

class Solution {
public:
	bool isMatch(const char* s, const char* p)
	{
		if (*s == 0) {
			if (*p == 0) return true;

			std::string tmp(p);
			return tmp.find_first_not_of("*") == std::string::npos;
		}

		if (*p == 0) return *s == 0;
		if (validCheck(s, p) == false) return false;

		std::vector<std::vector<bool>> dp(2, std::vector<bool>(strlen(p), false));
		if (*p != '*' && isEqual(s, p) == false) return false;
		int s_len = strlen(s);
		int p_len = strlen(p);

		dp[0][0] = true;
		for (int i = 1; i <= 1; ++i) {
			if (*(p) == '*') dp[i][0] = true;
			else break;
		}

		std::string tmp(p);
		std::string::size_type pos = tmp.find_first_not_of("*", 1);
		if (*p == '*' && pos != std::string::npos) {
			if (isEqual(s, p+pos)) pos = tmp.find_first_not_of("*", pos+1);
		} 
		
		if (pos == std::string::npos) pos = tmp.size();

		for (int j = 1; j < pos; ++j) {
			dp[0][j] = true;
		}

		int flag = 0;
		for (int i = 1; i < s_len; ++i) {
			flag = !flag;
			for (int j = 1; j < p_len; ++j) {
				if (*(p+j) != '*' && !isEqual(s+i, p+j)) {
					dp[flag][j] = false;
					continue;
				} else if (*(p+j) != '*' && isEqual(s+i, p+j)) {
					dp[flag][j] = dp[!flag][j-1];
				} else if (*(p+j) == '*') {
					if (dp[!flag][j-1] || dp[!flag][j] || dp[flag][j-1]) 
						dp[flag][j] = true;

					bool cancelFlag = false;
					while (j+1 < p_len && *(p+j+1) == '*') {
						++j;
						dp[flag][j] = dp[flag][j-1];
						cancelFlag = true;
					}

					if (cancelFlag) --j;
				}
			}

			if (*p == '*') dp[!flag][0] = true;
			else dp[!flag][0] = false;
		}

		return dp[flag][p_len-1];
	}          

	bool validCheck(const char* c1, const char* c2)
	{
		const char* ptr = c1;
		int max1 = 0;
		for (; *ptr; ++max1, ++ptr);

		ptr = c2;
		int max2 = 0;
		for (; *ptr; ++ptr) {
			if (*ptr != '*') ++max2;
		}

		if (max1 < max2) return false;
		return true;
	}

	bool isEqual(const char* c1, const char* c2)
	{
		return (*c1 == *c2) || (*c1 != '\0' && *c2 == '?');
	}
};

int main()
{

	Solution solve;
	bool ret = solve.isMatch("abbba", "?a?**");

	getchar();
	return 0;
}

