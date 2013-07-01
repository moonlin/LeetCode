/********************************************

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

********************************************/

class Solution {
public:
    std::vector<int> searchRange(int A[], int n, int target)
	{
		int lower = lowerBound(A, n, target);
		int upper = upperBound(A, n, target);
		
		std::vector<int> ret;
		ret.push_back(lower);
		ret.push_back(upper);

		return ret;
	}

	int lowerBound(int A[], int n, int target)
	{
		int l = 0;
		int r= n-1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (A[mid] == target) {
				if (mid <= l || A[mid-1] != target) return mid;
				else r = mid - 1;

			} else if (A[mid] < target) {
				l = mid + 1;

			} else {
				r = mid - 1;
			}
		}

		return -1;
	}

	int upperBound(int A[], int n, int target)
	{
		int l = 0;
		int r= n-1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (A[mid] == target) {
				if (mid >= r || A[mid+1] != target) return mid;
				else l = mid + 1;

			} else if (A[mid] < target) {
				l = mid + 1;

			} else {
				r = mid - 1;
			}
		}

		return -1;
	}
};
