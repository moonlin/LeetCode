/*************************************

Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;
 
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& sub)
	{
		if (sub.empty()) {
			return vector<vector<int>> ();
		}

		subs.clear();
		std::sort(sub.begin(), sub.end());
		vector<int> result;
		subsetsWithDup_impl(sub, 0, result);
		return subs;
	}

	void subsetsWithDup_impl(vector<int>& sub, int pos, 
		vector<int>& result, bool backtrace = false)
	{
		if (pos >= sub.size()) return;
		if (backtrace != true) {
			subs.push_back(result);
		}

		result.push_back(sub[pos]);
		subsetsWithDup_impl(sub, pos+1, result);
		if (pos+1 == sub.size()) {
			subs.push_back(result);
		}

		result.pop_back();
		++pos;

		subsetsWithDup_impl(sub, pos, result, true);
	}

	vector<vector<int>> subs;
};

int main()
{	
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	Solution solve;
	solve.subsets(num);

	getchar();
	return 0;
}

