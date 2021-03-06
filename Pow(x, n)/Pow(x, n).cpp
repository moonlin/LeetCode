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
		if (n < 0) return pow_impl(1/x, -n);

		// return x * pow(x, n-1);
		if (n % 2) return x * pow_impl(x, n-1);
		else return pow_impl(x*x, n/2);
	}          
};
