/*********************************************************

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*********************************************************/

class Solution {
public:
    int jump(int A[], int n)
	{
		if (n <= 1) return 0;

		std::vector<int> jumpVec(A, A+n);
		std::vector<int> dp(n, 0);
		
		int nextPos = 0;
		for (uint i = 0; i <= nextPos; ++i) {
			int pos = i + jumpVec[i];
			if (pos > n-1) pos = n-1;

			if (nextPos < pos) {
				for (int j = nextPos+1; j <= pos; ++j) {
					dp[j] = dp[i] + 1;
				}

				nextPos = pos;
			}

			if (nextPos == n-1) return dp[n-1];
		}
	}
};
