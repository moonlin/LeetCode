/*********************************************************

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*********************************************************/

class Solution {
public:
	bool canJump(int A[], int n)
	{
		std::vector<int> jumpVec(A, A+n);
		std::vector<bool> dp(n, false);
		for (int i = jumpVec.size()-1; i >= 0; --i) {
			if (i+jumpVec[i] >= n-1) dp[i] = true;
			else {
				for (int j = i+1; j <= i+jumpVec[i]; ++j) {
					if (dp[j]) {
						dp[i] = true;
						break;
					} else {  	// fix TLE here...
						j += jumpVec[j];
					}
				}
			}
		}

		return dp[0];
	}
};
