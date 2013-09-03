/****************************************************************************************

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.

****************************************************************************************/

class Solution {
public:
	int maxProfit(vector<int>& prices) 
	{
		if (prices.empty()) {
			return 0;
		}

		int max, min;
		return dc(prices, 0, prices.size()-1, max, min);
		return dc(prices, 0, prices.size()-1);
	}

	int dc(vector<int>& prices, int s, int e, int& max, int& min)
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

	int dc2(vector<int>& prices, int s, int e)
	{
		if (s >= e) return 0;

		int mid = (s + e) / 2;
		int max = std::max(dc2(prices, s, mid), dc2(prices, mid+1, e));

		int minLeft = prices[s];
		for (uint i = s+1; i <= mid; ++i) {
			minLeft = std::min(minLeft, prices[i]);
		}

		int maxRight = prices[mid+1];
		for (uint j = mid+2; j <= e; ++j) {
			maxRight = std::max(maxRight, prices[j]);
		}

		max = std::max(max, maxRight - minLeft);
		return max;
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

