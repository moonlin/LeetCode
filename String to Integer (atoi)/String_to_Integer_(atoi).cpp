/***************************************************

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by 
as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

***************************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;
 
class Solution {
public:
	int atoi(const char* str)
	{
		std::string strNum(str);
		if (strNum.empty()) return 0;

		std::string::size_type pos = strNum.find_first_not_of(" ");
		if (strNum[pos] != '+' && strNum[pos] != '-' && 
					(strNum[pos] > '9' || strNum[pos] < '0'))
		{
			return 0;
		}

		int flag = 1;
		if (strNum[pos] == '-') {
			flag = -1;
			++pos;
		} else if (strNum[pos] == '+') {
			++pos;
		}

		int num = 0;
		int i = pos;
		while (i < strNum.size() && strNum[i] >= '0' && strNum[i] <= '9') {
			if (num > (INT_MAX - strNum[i] + '0') / 10) {
				return flag == 1? INT_MAX: INT_MIN;
			}

			num = num * 10 + strNum[i++] - '0';
		}

		return flag*num;
	}

};

int main()
{	
	std::string num("-2147483647");
	Solution solve;
	int digit = solve.atoi(num.c_str());

	getchar();
	return 0;
}
