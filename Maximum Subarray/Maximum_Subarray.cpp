/*************************************

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.
More practice:

If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, which is more subtle.

*************************************/

class Solution {
public:
    int maxSubArray(int A[], int n)
	{
		std::vector<int> dp(n, 0);
		dp[0] = A[0];
		int gmax = dp[0];
		for (int i = 1; i < n; ++i) {
			dp[i] = A[i] + (dp[i-1]>0? dp[i-1]: 0);
			gmax = std::max(gmax, dp[i]);
		}

		return gmax;
	}          
};
