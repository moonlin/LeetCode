/**************************************************************************

A message containing letters from A-Z is being encoded to numbers 
using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, 
determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

**************************************************************************/
//Run Status: Accepted!
//Program Runtime: 372 milli secs

// not effective method...
class Solution {
public:
	int numDecodings(const string& str)
	{
		if (str.empty()) return 0;

		this->memo = std::vector<int> (str.size()+1, 0);


		return this->numDecodings_impl(str, 0);
	}

	int numDecodings_impl(const string& str, int pos)
	{
		if (pos >= str.size()) return 1;

		if (memo[pos]) return memo[pos];

		int total = 0;
		if (valid(str, pos)) {
			total += numDecodings_impl(str, pos+2);
		}

		if (str[pos] != '0') {
			total += numDecodings_impl(str, pos+1);
		}

		return memo[pos] = total;
	}


	bool valid(const std::string str, int pos)
	{
		if (pos >= str.size()) return false;
		if (pos == str.size()-1) return false;
		if (str[pos] == '0') return false;

		int num = 0;
		int loop = 0;
		while (loop < 2 && pos < str.size()) {
			num = num * 10 + str[pos] - '0';
			++pos;
			++loop;
		}

		if (num > 26 || num < 1) return false;
		return true;
	}

private: 
	std::vector<int> memo;
};

int main()
{	
	// std::string str("10");
	std::string str("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948");
	Solution solve;
	int ret = solve.numDecodings(str);

	getchar();
	return 0;
}
