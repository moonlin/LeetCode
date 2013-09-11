/**********************************************
Implement int sqrt(int x).

Compute and return the square root of x.

**********************************************/

class Solution {
public:
    int sqrt(int x)
	{
		long long l = 0;
		long long r = x;

		while (l <= r) {
			long long mid = (l+r)/2;
			if (mid*mid <= x && (mid+1)*(mid+1) > x) return mid;
			else if (mid*mid < x) l = mid+1;
			else if (mid*mid > x) r = mid-1;
		}

		return -1;
	}
};
