/***************************************************

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

***************************************************/

class Solution {
public:
    int search(int A[], int n, int target)
	{
		int l = 0;
		int r = n-1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (A[mid] == target) return mid;
			else if (A[mid] < target) {
				if (A[mid] <= A[r] && A[r] < target) r = mid-1;
				else l = mid+1;

			} else if (A[mid] > target) {
				if (A[l] <= A[mid] && target < A[l]) l = mid+1;
				else r = mid-1;
			}
		}

		return -1;
	}
};
