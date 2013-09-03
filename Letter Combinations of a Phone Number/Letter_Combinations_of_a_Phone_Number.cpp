/*********************************************

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*********************************************/

class Solution {
public:
	std::vector<std::string> letterCombinations(std::string& digits)
	{
		letterVec.clear();
		string tmpStr;
		this->letterCombinations_impl(digits, 0, tmpStr);

		return letterVec;
	}

	void letterCombinations_impl(std::string& digits, int pos, std::string& letter)
	{
		if (pos >= digits.size()) {
			letterVec.push_back(letter);

			return ;
		}

		char cc = digits[pos];
		if (cc == '0') {
			letterVec.push_back(letter);
		} else if (cc == '2') {
			letterCombinations_impl(digits, pos+1, letter+'a');
			letterCombinations_impl(digits, pos+1, letter+'b');
			letterCombinations_impl(digits, pos+1, letter+'c');
		} else if (cc == '3') {
			letterCombinations_impl(digits, pos+1, letter+'d');
			letterCombinations_impl(digits, pos+1, letter+'e');
			letterCombinations_impl(digits, pos+1, letter+'f');
		} else if (cc == '4') {
			letterCombinations_impl(digits, pos+1, letter+'g');
			letterCombinations_impl(digits, pos+1, letter+'h');
			letterCombinations_impl(digits, pos+1, letter+'i');
		} else if (cc == '5') {
			letterCombinations_impl(digits, pos+1, letter+'j');
			letterCombinations_impl(digits, pos+1, letter+'k');
			letterCombinations_impl(digits, pos+1, letter+'l');
		} else if (cc == '6') {
			letterCombinations_impl(digits, pos+1, letter+'m');
			letterCombinations_impl(digits, pos+1, letter+'n');
			letterCombinations_impl(digits, pos+1, letter+'o');
		} else if (cc == '7') {
			letterCombinations_impl(digits, pos+1, letter+'p');
			letterCombinations_impl(digits, pos+1, letter+'q');
			letterCombinations_impl(digits, pos+1, letter+'r');
			letterCombinations_impl(digits, pos+1, letter+'s');
		} else if (cc == '8') {
			letterCombinations_impl(digits, pos+1, letter+'t');
			letterCombinations_impl(digits, pos+1, letter+'u');
			letterCombinations_impl(digits, pos+1, letter+'v');
		} else if (cc == '9') {
			letterCombinations_impl(digits, pos+1, letter+'w');
			letterCombinations_impl(digits, pos+1, letter+'x');
			letterCombinations_impl(digits, pos+1, letter+'y');
			letterCombinations_impl(digits, pos+1, letter+'z');
		} else {
			return;
		}
	}

private:
	std::vector<std::string> letterVec;
};

int main()
{
	string str("23");

	Solution solve;
	vector<string> ret = solve.letterCombinations(str);

	getchar();
	return 0;
}
