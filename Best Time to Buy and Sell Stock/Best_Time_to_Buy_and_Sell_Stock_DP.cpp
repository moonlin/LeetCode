/*****************************************************************************************

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

*****************************************************************************************/

class Solution {
public:
	int maxProfit(vector<int>& prices) 
	{
		if (prices.empty()) {
			return 0;
		}

		return dp(prices);
	}

	int dp(vector<int>& prices)
	{
		int gmax = 0;
		int max = prices.back();
		for (uint i = prices.size()-2; i >= 0; --i) {
			gmax = std::max(gmax, max - prices[i]);
			max = std::max(prices[i], max);
		}

		return gmax;
	}


	int dp2(vector<int>& prices)
	{
		int gmax = 0;
		int min = prices.front();
		for (uint i = 1; i < prices.size(); ++i) {
			gmax = std::max(gmax, prices[i] - min);
			min = std::min(min, prices[i]);
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
