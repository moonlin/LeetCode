/**********************************************

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

**********************************************/
// Run Status: Accepted!
// Program Runtime: 1620 milli secs

class Solution {
public:
    int totalNQueens(int n)
	{
		this->total = 0;
		std::vector<int> oneQue(n, -1);
		this->solveNQueens_impl(oneQue, n, 0);

		return this->total;
	}

	void solveNQueens_impl(std::vector<int>& oneQue, int n, int level) 
	{
		if (level >= n) {
			++this->total;
			return;
		}

		for (int i = 0; i < n; ++i) {
			if (!judgePlaced(oneQue, level, i)) continue;

			oneQue[level] = i;
			solveNQueens_impl(oneQue, n, level+1);
			oneQue[level] = -1; //needless
		}
	}

	bool judgePlaced(vector<int>& oneQue, int level, int pos)
	{
		for (int i = 0; i < level; ++i) {
			if (oneQue[i] == pos || abs(i-level) == abs(oneQue[i]-pos)) return false;
		}

		return true;
	}

private:
	int total;
};
