/***************************************************************************

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

***************************************************************************/

class Solution {
public:
    std::string countAndSay(int n)
	{
		std::string say("1");
		if (n == 1) return say;

		for (int i = 1; i < n; ++i) {
			int count = 1;
			std::string tmp;
			for (int j = 1; j < say.size(); ++j) {
				if (say[j] == say[j-1]) {
					++count;
				} else { 
					tmp.push_back(count+'0');
					tmp.push_back(say[j-1]);
					count = 1;
				}
			}

			tmp.push_back(count+'0');
			tmp.push_back(say.back());

			say.swap(tmp);
		}

		return say;
	}
};
