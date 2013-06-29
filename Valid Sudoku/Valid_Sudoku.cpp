/*****************************************

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

*****************************************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
	{
		if (board.empty()) return false;

		for (int index = 0; index < 81; ++index) {
			while (index < 81 && board[index/9][index%9] == '.') ++index;
			if (index >= 81) return true;
			char cc = board[index/9][index%9];
			board[index/9][index%9] = '.';
			if (!validSudoku(board, index/9, index%9, cc)) {
				board[index/9][index%9] = cc;
				return false;
			}
			board[index/9][index%9] = cc;
		}

		return true;
	}          

	bool validSudoku(vector<vector<char>>& board, int row, int col, char cc)
	{
		for (int i = 0; i < 9; ++i) {
			if (board[row][i] == cc) return false;
		}

		for (int j = 0; j < 9; ++j) {
			if (board[j][col] == cc) return false;
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (board[(row/3)*3 + i][(col/3)*3 + j] == cc) return false;
			}
		}

		return true;
	}
};
