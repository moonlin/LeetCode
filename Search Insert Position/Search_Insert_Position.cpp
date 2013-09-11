/*******************************************
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 --> 2
[1,3,5,6], 2 --> 1
[1,3,5,6], 7 --> 4
[1,3,5,6], 0 --> 0

*******************************************/

class Solution {
public:
    int searchInsert(const int A[], int n, int target)
	{
		if (A[0] > target) return 0;
		if (A[n-1] < target) return n;
		int l = 0;
		int r = n-1;
		while (l <= r) {
			int mid = (l + r)/2;
			if (A[mid] == target) return mid;
			else if (A[mid] < target) {
				if (A[mid+1] > target) return mid+1;
				l = mid+1;
			} else {
				if (mid-1 >= 0 && A[mid-1] < target) return mid;
				r = mid-1;
			}
		}
	}          

};
