/*******************************************************************************

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, a3, ak) must be in non-descending order. 
    (ie, a1 <= a2 <= a3 <= ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 

********************************************************************************/

// remove the duplicate element using "std::set<int> unique(candidates.begin(), candidates.end())"
// so we can got the unique solution with "combinationSum_impl(unique, target, iter, oneSolution, sum + *iter)"
// the iterator does not plus, so this matches the "unlimited number of times"
// And we can do like combinationSum_impl(unique, target, ++iter, oneSolution, sum + *iter)"
// this means any element of the sequence can only use once

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
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
			combinationSum_impl(unique, target, iter, oneSolution, sum + *iter);
			oneSolution.pop_back();
		}
		
		return;
	}
	
private:
	std::vector<std::vector<int>> ret;
};
