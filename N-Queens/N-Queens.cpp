/****************************************************

The n-queens puzzle is the problem of placing n queens on an n?n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

****************************************************/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
	{
		queues.clear();

		vector<int> oneQue(n, -1);
		this->solveNQueens_impl(oneQue, n, 0);
		return queues;
	}

	void solveNQueens_impl(vector<int>& oneQue, int n, int level) 
	{
		if (level >= n) {
			vector<string> vec;
			for (uint i = 0; i < n; ++i) {
				string level;
				for (uint j = 0; j < n; ++j) {
					if (j == oneQue[i]) level += 'Q';
					else level += '.';
				}

				vec.push_back(level);
			}

			queues.push_back(vec);
			return;
		}

		for (int i = 0; i < n; ++i) {
			if (!judgePlaced(oneQue, level, i)) continue;

			setOneQueue(oneQue, level, i);
			solveNQueens_impl(oneQue, n, level+1);
			setOneQueue(oneQue, level, i, true);
		}
	}

	bool judgePlaced(vector<int>& oneQue, int level, int pos)
	{
		for (int i = 0; i < level; ++i) {
			if (oneQue[i] == pos || abs(i-level) == abs(oneQue[i]-pos)) return false;
		}

		return true;
	}

	void setOneQueue(vector<int>& oneQue, int level, int pos, bool bt = false)
	{
		bt? (oneQue[level] = -1): (oneQue[level] = pos);
	}
       
private:
	vector<vector<string>> queues;
};

