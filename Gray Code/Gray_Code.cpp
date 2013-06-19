/****************************************

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

****************************************/

// not effective method

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
	vector<int> grayCode(int n)
	{
		vector<int> codes;
		int num = 0;
		codes.push_back(num);
		bool flag = false;
		while (1) {
			if (!flag) {
				toggle(num, 0);
			} else {
				int bit = 0;
				for (; bit < n && !(num & 1<<bit); ++bit);
				++bit;
				if (bit == n) break;

				toggle(num, bit);
			}

			flag = !flag;
			codes.push_back(num);
		}

		return codes;
	}

	void toggle(int& num, int bit)
	{
		if (num & 1<<bit) {
			num &= ~(1<<bit);
		} else {
			num |= 1<<bit; 
		}
	}

};

int main()
{
	Solution solve;
	vector<int> ret = solve.grayCode(2);

	getchar();
	return 0;
}
