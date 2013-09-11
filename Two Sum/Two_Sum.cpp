/************************************
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. Please note that your returned answers 
(both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

************************************/

struct comp {
	bool operator()(const std::pair<int, int>& lop, const std::pair<int, int>& rop)
	{
		return lop.first <= rop.first;
	}
};

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& numbers, int target) 
	{
		std::vector<std::pair<int, int>> nums;
		nums.reserve(numbers.size());
		for (int i = 0; i < numbers.size(); ++i) {
			nums.push_back(std::pair<int, int> (numbers[i], i));
		}

		std::vector<int> result;
		std::sort(nums.begin(), nums.end(), comp());
		uint i = 0;
		uint j = nums.size()-1;
		while (i < j) {
			if (nums[i].first + nums[j].first < target) ++i;
			else if (nums[i].first + nums[j].first > target) --j;
			else {
				int min = std::min(nums[i].second, nums[j].second);
				int max = std::max(nums[i].second, nums[j].second);
				result.push_back(min+1);
				result.push_back(max+1);

				return result;
			}
		}
	}      

};
