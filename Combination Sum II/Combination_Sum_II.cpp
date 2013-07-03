/************************************************

Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 

************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		ret.clear();
		std::multiset<int> unique(candidates.begin(), candidates.end());
		std::vector<int> oneSolution;
		int sum = 0;
		this->combinationSum_impl(unique, target, unique.begin(), oneSolution, sum);

		return ret;
	}

	void combinationSum_impl(std::multiset<int>& unique, int target, 
								std::multiset<int>::iterator iter,
								std::vector<int>& oneSolution, int sum)
	{
		if (sum >= target) {
			if (sum == target) ret.push_back(oneSolution);

			return;
		}

		for (; iter != unique.end(); ++iter) {
			oneSolution.push_back(*iter);
			std::multiset<int>::iterator tmpIter = iter;
			combinationSum_impl(unique, target, ++tmpIter, oneSolution, sum+*iter);
			oneSolution.pop_back();

			while (tmpIter != unique.end() && *iter == *tmpIter) ++iter, ++tmpIter;
		}
		
		return;
	}
	
private:
	vector<vector<int>> ret;
};
