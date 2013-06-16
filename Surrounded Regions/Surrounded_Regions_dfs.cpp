/***
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region .
For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

***/


#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef unsigned int uint;


class Solution {
public:
    void solve(vector<vector<char>>& board)
	{
		board_ = board;
		for (int i = 0; i < board_.size(); ++i)
		{
			dfs(i, 0);
			dfs(i, board_.size()-1);
		}

		for (int j = 0; j < board_.size(); ++j)
		{
			dfs(0, j);
			dfs(board_.size()-1, j);
		}

		for (uint i = 0; i < board_.size(); ++i) {
			for (uint j = 0; j < board_.size(); ++j) {
				if (board_[i][j] == 'O') {
					board_[i][j] = 'X';
				} else if (board_[i][j] == '#') {
					board_[i][j] = 'O';
				}
			}
		}
	
		board.swap(board_);
	}

	void dfs(int i, int j)
	{
		if (i >= board_.size() || j >= board_.size()
			|| i < 0 || j < 0) 
		{
			return;
		}

		if (board_[i][j] != 'O') return;

		board_[i][j] = '#';

		dfs(i-1, j);
		dfs(i, j-1);
		dfs(i+1, j);
		dfs(i, j+1);
	}

private:

	vector<vector<char>> board_;
};


int main()
{
	Solution solve;

	vector<vector<char>> board;

	solve.solve(board);

	getchar();
	return 0;
}