/**********************************************************

Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

**********************************************************/

class Solution {
public:
    int trap(int A[], int n)
	{
		if (n <= 0) return 0;

		std::vector<int> left;
		std::vector<int> right;

		left.push_back(0);
		int max = A[0];
		for (uint i = 1; i < n; ++i) {
			left.push_back(max);
			max = std::max(max, A[i]);
		}
		
		right.resize(n);
		right[n-1] = 0;
		max = A[n-1];
		for (int j = n-2; j >= 0; --j) {
			right[j] = max;
			max = std::max(max, A[j]);
		}

		int sum = 0;
		for (uint i = 1; i < n-1; ++i) {
			int num = std::min(left[i], right[i]) - A[i];
			num = num<0? 0: num;
			sum += num;
		}

		return sum;
	}
};
