/**********************************************

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

**********************************************/

class Solution {
public:
    int totalNQueens(int n)
	{
		total = 0;
		vector<int> oneQue(n, -1);
		this->solveNQueens_impl(oneQue, n, 0);
		return total;
	}

	void solveNQueens_impl(vector<int>& oneQue, int n, int level) 
	{
		if (level >= n) {
			++total;
			return;
		}

		for (int i = 0; i < n; ++i) {
			if (!judgePlaced(oneQue, level, i)) continue;

			oneQue[level] = i;
			solveNQueens_impl(oneQue, n, level+1);
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
