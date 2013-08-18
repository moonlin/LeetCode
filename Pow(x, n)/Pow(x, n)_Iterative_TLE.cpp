/*******************************************

Implement pow(x, n).

*******************************************/

class Solution {
public:
    double pow(double x, int n)
    {
    	if (n == INT_MAX && abs(x) == 1.0) return x;
		if (n == INT_MIN && abs(x) == 1.0) return abs(x);

		return this->pow_impl(x, n);
	}

	double pow_impl(double x, int n)
	{
		if (n == 0) return 1.0;
		if (n < 0) {
			x = 1/x;
			n = -n;
		}

		double ret = 1;
		uint loop = (uint)n;
		for (uint i = 0; i < loop; ++i) ret *= x;

		return ret;
	}          
};
