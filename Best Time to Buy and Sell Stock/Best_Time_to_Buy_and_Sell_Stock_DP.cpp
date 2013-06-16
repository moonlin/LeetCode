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

		return dp(prices);
	}

	int dp(vector<int> &prices)
	{
		int gmax = 0;
		int max = prices[prices.size()-1];
		for (int i = prices.size()-2; i >= 0; --i) {
			max = std::max(prices[i+1], max);
			gmax = std::max(gmax, max - prices[i]);
		}

		return gmax;
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
