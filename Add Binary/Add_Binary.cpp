/**********************************************

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

**********************************************/

class Solution {
public:
    std::string addBinary(std::string& a, std::string& b)
	{
		std::string addStr;
		int carry = 0;
		int i, j;
		for (i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; --i, --j) {
			int add = a[i]-'0' + b[j]-'0' + carry;
			carry = add/2;
			char cc = add%2 + '0';
			addStr.push_back(cc);
			//addStr.insert(0, 1, cc);
		}

		while (i >= 0) {
			int add = a[i]-'0' + carry;
			carry = add/2;
			char cc = add%2 + '0';
			addStr.push_back(cc);
			//addStr.insert(0, 1, cc);
			--i;
		}

		while (j >= 0) {
			char add = b[j]-'0' + carry;
			carry = add/2;
			char cc = add%2 + '0';
			addStr.push_back(cc);
			//addStr.insert(0, 1, cc);
			--j;
		}

		if (carry) addStr.push_back(carry+'0');
		//if (carry) addStr.insert(0, 1, carry+'0');

		std::reverse(addStr.begin(), addStr.end());

		return addStr;
	}        
};
