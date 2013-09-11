/*********************************************************

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*********************************************************/

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string& word)
	{
		if (board.empty()) return false;
		if (word.empty()) return true;

		board_.swap(board);
		memo_ = std::vector<std::vector<bool>> 
				(board_.size(), std::vector<bool>(board_[0].size(), false));

		for (uint i = 0; i < board_.size(); ++i) {
			for (uint j = 0; j < board_[0].size(); ++j) {
				if (dfs(i, j, word, 0)) return true;
			}
		}
		
		return false;
	}

	bool dfs(int x, int y, std::string& word, int pos)
	{
		if (board_[x][y] != word[pos]) return false;
		if (pos == word.size()-1) return board_[x][y]==word[pos];

		++pos;
		memo_[x][y] = true;
		if (ValidPlace(x+1, y)) {
			if (dfs(x+1, y, word, pos)) return true;
		}
		
		if (ValidPlace(x-1, y)) {
			if (dfs(x-1, y, word, pos)) return true;
		}

		if (ValidPlace(x, y+1))  {
			if (dfs(x, y+1, word, pos)) return true;
		}

		if (ValidPlace(x, y-1)) {
			if (dfs(x, y-1, word, pos)) return true;
		}

		memo_[x][y] = false;

		return false;
	}

	bool ValidPlace(int x, int y) 
	{
		if (x >= memo_.size() || x < 0) return false;
		if (y >= memo_[0].size() || y < 0) return false;

		return memo_[x][y]==false;
	}

private:
	std::vector<std::vector<bool>> memo_;
	std::vector<std::vector<char>> board_;
};
