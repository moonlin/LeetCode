/**********************************************************
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

**********************************************************/

class Solution {
public:
    std::string multiply(std::string& num1, std::string& num2)
	{
		std::string ret(num1.size()+num2.size(), '0');
	
		for (int idx2 = num2.size()-1; idx2 >= 0; --idx2) {
			int carry = 0;
			int idx1 = -1;
			for (idx1 = num1.size()-1; idx1 >= 0; --idx1) {
				int num = carry + (num1[idx1]-'0') * (num2[idx2]-'0');

				int sum = num + ret[idx1+idx2+1]-'0';
				carry = sum/10;
				ret[idx1+idx2+1] = sum%10 + '0';
			}

			if (carry) ret[idx1+idx2+1] = carry + '0';
		}
		
		while (ret.size() > 1 && ret[0] == '0') ret.erase(0, 1);

		return ret;
	}
};
