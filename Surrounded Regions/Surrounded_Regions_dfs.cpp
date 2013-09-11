/***********************************************************************
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
***********************************************************************/

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board)
	{
		if (board.empty()) return;
		if (board[0].empty()) return;

		for (uint i = 0; i < board.size(); ++i)
		{
			dfs(board, i, 0);
			dfs(board, i, board.size()-1);
		}

		for (uint j = 0; j < board[0].size(); ++j)
		{
			dfs(board, 0, j);
			dfs(board, board.size()-1, j);
		}

		for (uint i = 0; i < board.size(); ++i) {
			for (uint j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				} else if (board[i][j] == '#') {
					board[i][j] = 'O';
				}
			}
		}
	
	}

	void dfs(std::vector<std::vector<char>>& board, int i, int j)
	{
		if (i < 0 || i >= board.size() 
				|| j < 0 || j >= board[0].size())
		{
			return;
		}

		if (board[i][j] != 'O') return;

		board[i][j] = '#';

		dfs(board, i-1, j);
		dfs(board, i, j-1);
		dfs(board, i+1, j);
		dfs(board, i, j+1);
	}

};
