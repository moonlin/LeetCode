/*********************************************

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 

**********************************************/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		ret.clear();
		std::set<int> unique(candidates.begin(), candidates.end());
		std::vector<int> oneSolution;
		int sum = 0;
		this->combinationSum_impl(unique, target, unique.begin(), oneSolution, sum);

		return ret;
	}

	void combinationSum_impl(std::set<int>& unique, int target, 
								std::set<int>::iterator iter,
								std::vector<int>& oneSolution, int sum)
	{
		if (sum >= target) {
			if (sum == target) ret.push_back(oneSolution);

			return;
		}

		for (; iter != unique.end(); ++iter) {
			oneSolution.push_back(*iter);
			combinationSum_impl(unique, target, iter, oneSolution, sum+*iter);
			oneSolution.pop_back();
		}
		
		return;
	}
	
private:
	vector<vector<int>> ret;
};
