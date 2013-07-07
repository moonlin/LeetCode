/*******************************************************

Given a number represented as an array of digits, plus one to the number.

*******************************************************/

class Solution {
public:
	std::vector<int> plusOne(std::vector<int>& digits)
	{
		std::vector<int> ret;
		ret.resize(digits.size());
		int carry = 1;
		for (int i = digits.size()-1; i >= 0; --i) {
			int sum = digits[i] + carry;
			carry = sum/10;
			ret[i] = sum%10;
		}

		if (carry) ret.insert(ret.begin(), carry);

		return ret;
	}
};
