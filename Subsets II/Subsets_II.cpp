/**************************************

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

**************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;
 
class Solution {
public:
	vector<vector<int>> subsetsWithDup(std::vector<int>& sub)
	{
		if (sub.empty()) {
			return vector<vector<int>> ();
		}

		subsets.clear();
		std::sort(sub.begin(), sub.end());
		vector<int> result;
		subsetsWithDup_impl(sub, 0, result);
		return subsets;
	}

	void subsetsWithDup_impl(vector<int>& sub, int pos, 
							vector<int>& result, bool backtrace = false)
	{
		if (pos >= sub.size()) return;
		if (backtrace != true) {
			subsets.push_back(result);
		}

		result.push_back(sub[pos]);
		subsetsWithDup_impl(sub, pos+1, result);
		if (pos+1 == sub.size()) {
			subsets.push_back(result);
		}

		result.pop_back();
		for (++pos; pos < sub.size() && sub[pos] == sub[pos-1]; ++pos);

		subsetsWithDup_impl(sub, pos, result, true);
	}

	vector<vector<int>> subsets;
};

int main()
{	
	vector<int> num;
	num.push_back(4);
	num.push_back(1);
	num.push_back(0);

	Solution solve;
	solve.subsetsWithDup(num);

	getchar();
	return 0;
}
