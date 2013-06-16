/********************

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

********************/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <map>

using namespace std;
typedef unsigned int uint;

class Solution {
public:
	bool isPalindrome(string s) 
	{
		int i = 0;
		int j = s.size()-1;

		while (i < j) {
			while (i < j && !validTag(s[i])) ++i;
			while (i < j && !validTag(s[j])) --j;

			if (i >= j) break;

			if (!(s[i] == s[j] || s[i] == s[j] + 'a' - 'A'
							   || s[i] == s[j] + 'A' - 'a'))
			{
				return false;
			}

			++i;
			--j;
		}

		return true;
	}

	bool validTag(char cc)
	{
		if ((cc >= '0' && cc <= '9') 
			|| (cc >= 'a' && cc <= 'z') 
			|| (cc >= 'A' && cc <= 'Z'))
		{
			return true;
		}

		return false;
	}
};

int main()
{
	string str = "A man, a plan, a canal: Panama";
	Solution solve;
	bool ret = solve.isPalindrome(str);

	std::cout <<"ret == " <<ret <<'\n';

	getchar();
	return 0;
}

