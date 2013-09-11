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

		board_.swap(board);
		for (int i = 0; i < board_.size(); ++i)
		{
			bfs(i, 0);
			bfs(i, board_[0].size()-1);
		}

		for (int j = 0; j < board_[0].size(); ++j)
		{
			bfs(0, j);
			bfs(board_.size()-1, j);
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

	bool isValid(int i, int j) 
	{
		if (i >= board_.size() || j >= board_.size()
			|| i < 0 || j < 0) 
		{
			return false;
		}

		return true;
	}

	void bfs(int i, int j)
	{
		if (!isValid(i, j)) return;
		if (board_[i][j] != 'O') return;

		board_[i][j] = '#';
		std::queue<std::pair<int, int>> nodeQue;
		nodeQue.push(std::pair<int, int> (i, j));
		while (!nodeQue.empty())
		{
			std::pair<int, int> node = nodeQue.front();
			nodeQue.pop();

			i = node.first;
			j = node.second;
			if (isValid(i-1, j) && board_[i-1][j] == 'O') {
				board_[i-1][j] = '#';
				nodeQue.push(std::pair<int, int> (i-1, j));
			}

			if (isValid(i, j-1) && board_[i][j-1] == 'O') {
				board_[i][j-1] = '#';
				nodeQue.push(std::pair<int, int> (i, j-1));
			}

			if (isValid(i+1, j) && board_[i+1][j] == 'O') {
				board_[i+1][j] = '#';
				nodeQue.push(std::pair<int, int> (i+1, j));
			}

			if (isValid(i, j+1) && board_[i][j+1] == 'O') {
				board_[i][j+1] = '#';
				nodeQue.push(std::pair<int, int> (i, j+1));
			}
		}

	}

private:
	std::vector<std::vector<char>> board_;
};
