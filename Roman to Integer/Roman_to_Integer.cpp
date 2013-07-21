/*******************************************************

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

*******************************************************/

class Solution {
public:
    int romanToInt(const std::string& s)
	{
		std::unordered_map<char, int> convert;
		convert['I'] = 1;
		convert['V'] = 5;
		convert['X'] = 10;
		convert['L'] = 50;
		convert['C'] = 100;
		convert['D'] = 500;
		convert['M'] = 1000;

		int sum = convert[s.back()];
		for (int i = s.size()-2; i >= 0; --i) {
			if (convert[s[i]] < convert[s[i+1]]) sum -= convert[s[i]];
			else sum += convert[s[i]];
		}

		return sum;
	}
};
