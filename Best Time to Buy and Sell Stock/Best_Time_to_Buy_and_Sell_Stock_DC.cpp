/**************************

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

**************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <map>

using namespace std;
typedef unsigned int uint;

class Solution {
public:
	int maxProfit(vector<int> &prices) 
	{
		if (prices.empty()) {
			return 0;
		}

		int max, min;
		return dc(prices, 0, prices.size()-1, max, min);
	}

	int dc(vector<int> &prices, int s, int e, int& max, int& min)
	{
		if (s >= e) {
			max = min = prices[s];

			return 0;
		}

		int mid = (s + e) / 2;
		int maxLeft;
		int minLeft;
		int maxLeftPrices = dc(prices, s, mid, maxLeft, minLeft);

		int maxRight;
		int minRight;
		int maxRightPrices = dc(prices, mid+1, e, maxRight, minRight);

		max = std::max(maxLeft, maxRight);
		min = std::min(minLeft, minRight);
		return (std::max(std::max(maxLeftPrices, maxRightPrices), maxRight-minLeft));
	}
};


int main()
{
	int a[] = {2,1,4,5,2,9,7};
	vector<int> prices(a, a+sizeof(a)/sizeof(a[0]));
	Solution solve;
	int ret = solve.maxProfit(prices);

	std::cout <<"ret == " <<ret <<'\n';

	getchar();
	return 0;
}

