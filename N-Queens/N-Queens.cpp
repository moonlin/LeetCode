/****************************************************

The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.

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
    std::vector<std::vector<std::string>> solveNQueens(int n)
	{
		queues.clear();

		std::vector<int> oneQue(n, -1);
		this->solveNQueens_impl(oneQue, n, 0);
		return queues;
	}

	void solveNQueens_impl(std::vector<int>& oneQue, int n, int level) 
	{
		if (level >= n) {
			std::vector<std::string> oneSolution;
			for (uint i = 0; i < n; ++i) {
				std::string level(n, '.');
				level[oneQue[i]] = 'Q';

				oneSolution.push_back(level);
			}

			queues.push_back(oneSolution);
			return;
		}

		for (int pos = 0; pos < n; ++pos) {
			if (!judgePlaced(oneQue, level, pos)) continue;

			oneQue[level] = pos;
			solveNQueens_impl(oneQue, n, level+1);
			oneQue[level] = -1;	
		}
	}

	bool judgePlaced(std::vector<int>& oneQue, int level, int pos)
	{
		for (int i = 0; i < level; ++i) {
			if (oneQue[i] == pos || abs(i-level) == abs(oneQue[i]-pos)) return false;
		}

		return true;
	}
       
private:
	std::vector<std::vector<std::string>> queues;
};
