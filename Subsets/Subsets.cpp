/*************************************************************************
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

*************************************************************************/
 
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& sub)
	{
		if (sub.empty()) {
			return std::vector<std::vector<int>> ();
		}

		subs.clear();
		std::sort(sub.begin(), sub.end());

		std::vector<int> oneSolution;
		subsetsWithDup_impl(sub, 0, oneSolution);
		return subs;
	}

	void subsetsWithDup_impl(std::vector<int>& sub, int pos,
		std::vector<int>& oneSolution)
	{
		if (pos >= sub.size()) {
			subs.push_back(oneSolution);
			return;
		}

		subsetsWithDup_impl(sub, pos+1, oneSolution);
		oneSolution.push_back(sub[pos]);
		subsetsWithDup_impl(sub, pos+1, oneSolution);
		oneSolution.pop_back();
	}

private:
	std::vector<std::vector<int>> subs;
};
