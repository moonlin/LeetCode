/****************************************

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

****************************************/

#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		collection.clear();
		string str;
		this->generateParenthesis_impl(str, n, 0);

		return collection;
	}

	void generateParenthesis_impl(string& pattern, int n, int left)
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
	vector<string> collection;
};

int main()
{
	Solution solve;
	vector<string> ret = solve.generateParenthesis(3);

	getchar();
	return 0;
}
