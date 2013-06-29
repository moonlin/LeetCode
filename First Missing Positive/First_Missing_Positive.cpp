/***************************************************

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

***************************************************/

class Solution {
public:
    int firstMissingPositive(int A[], int n)
	{
		if (n == 0) return 1;

		for (int i = 0; i < n; ++i) {
			if (A[i] <= 0) A[i] = INT_MIN;
		}

		for (int i = 0; i < n; ++i) {
			if (A[i] == INT_MIN) continue;
			else if (A[i] > 0 && A[i] <= n) {
				if (A[A[i]-1] <= 0 && A[A[i]-1] != INT_MIN) continue;
				A[A[i]-1] = A[A[i]-1]==INT_MIN? 0: -A[A[i]-1];
			} else if (A[i] < 0 && -A[i] <= n) {
				if (A[-A[i]-1] <= 0 && A[-A[i]-1] != INT_MIN) continue;
				A[-A[i]-1] = A[-A[i]-1]==INT_MIN? 0: -A[-A[i]-1];
			}
		}

		int index;
		for (index = 0; index < n; ++index) {
			if (A[index] > 0 || A[index] == INT_MIN) return index+1;
		}

		if (index == n) return n+1;
	}          

};
