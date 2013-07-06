/***************************************************************

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

***************************************************************/

class Solution {
public:
    bool search(int A[], int n, int target)
	{
		int l = 0;
		int r = n-1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (A[mid] == target) return true;

			if (A[l] < A[mid]) {
				if (A[l] <= target && A[mid] > target) r = mid-1;
				else l = mid+1;
			} else if (A[mid] < A[r]) {
				if (A[mid] < target && A[r] >= target) l = mid+1;
				else r = mid-1;
			} else if (A[l] == A[mid]) {
				++l;
				while (A[l] == A[mid]) ++l;
			} else if (A[mid] == A[r]) {
				--r;
				while (A[r] == A[mid]) --r;
			}
		}

		return false;
	}
};
