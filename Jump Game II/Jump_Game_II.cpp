/*********************************************************

 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*********************************************************/

// Time Limit Exceeded...

class Solution {
public:
    int jump(int A[], int n)
	{
		if (n <= 1) return 0;

		std::vector<int> jumpVec(A, A+n);
		std::vector<int> dp(n, 0);
		for (int i = jumpVec.size()-1; i >= 0; --i) {
			int min = INT_MAX;
			if (i+jumpVec[i] >= n-1) {
				dp[i] = 1;
				min = 1;
			} else {
				for (int j = i+1; j <= i+jumpVec[i]; ++j) {
					if (dp[j]) {
						min = std::min(min, dp[j]+1);
					} else {
						j += jumpVec[j];
					}
				}
			}

			if (min < INT_MAX) dp[i] = min;
		}

		return dp[0];
	}
};
