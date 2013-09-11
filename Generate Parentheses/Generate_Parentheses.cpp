/******************************************************

Given n pairs of parentheses, write a function to 
generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

******************************************************/

class Solution {
public:
	std::vector<std::string> generateParenthesis(int n)
	{
		this->collection.clear();
		std::string str;
		this->generateParenthesis_impl(str, n, 0);

		return this->collection;
	}

	void generateParenthesis_impl(std::string& pattern, int n, int left)
	{
		if (n == left && pattern.size() == n*2) 
		{
			collection.push_back(pattern);
			return;
		}
		
		if (left < n) {
			pattern.push_back('(');
			generateParenthesis_impl(pattern, n, left+1);
			pattern.pop_back();
		}
		
		if (pattern.size()-left < left) {
			pattern.push_back(')');
			generateParenthesis_impl(pattern, n, left);
			pattern.pop_back();
		} 

	}

private:
	std::vector<std::string> collection;
};
