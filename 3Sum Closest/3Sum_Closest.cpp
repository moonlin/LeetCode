/***************************************************

Given an array S of n integers, find three integers in S 
such that the sum is closest to a given number, target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

***************************************************/

class Solution {
public:
    int threeSumClosest(std::vector<int>& num, int target)
	{
		int ret = INT_MAX;
		std::sort(num.begin(), num.end());
		for (uint i = 0; i < num.size(); ++i) {
			int plus1 = num[i];
			int l = i+1;
			int r = num.size()-1;
			while (l < r) {
				int sum = plus1 + num[l] + num[r];
				if (ret == INT_MAX) ret = sum;
				else if (std::abs(sum-target) < std::abs(ret-target)) ret = sum;

				if (sum < target) ++l;
				else if (sum > target) --r;
				else return ret;
			}
			
			for (; i < num.size()-1 && num[i]==num[i+1]; ++i);
		}

		return ret;
	}
};
