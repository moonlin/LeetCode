/************************************

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. Please note that your returned answers 
(both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

bool cmp(std::pair<int, int> lop, std::pair<int, int> rop)
{
	return lop <= rop? true: false;
}

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) 
	{
		vector<std::pair<int, int>> nums;
		nums.reserve(numbers.size());
		for (int i = 0; i < numbers.size(); ++i) {
			nums.push_back(std::pair<int, int> (numbers[i], i+1));
		}

		vector<int> result;
		std::sort(nums.begin(), nums.end(), cmp);
		uint i = 0;
		uint j = nums.size()-1;
		while (i < j) {
			if (nums[i].first + nums[j].first < target) ++i;
			else if (nums[i].first + nums[j].first > target) --j;
			else {
				int min = std::min(nums[i].second, nums[j].second);
				int max = std::max(nums[i].second, nums[j].second);
				result.push_back(min);
				result.push_back(max);

				return result;
			}
		}
	}      

};

int main()
{
	std::vector<int> num;
	num.push_back(2);
	num.push_back(9);
	num.push_back(1);
	num.push_back(8);
	num.push_back(7);
	num.push_back(10);

	Solution solve;
	vector<int> ret = solve.twoSum(num, 16);

	getchar();
	return 0;
}
