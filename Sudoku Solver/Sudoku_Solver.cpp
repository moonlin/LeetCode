/****************************************************
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

A sudoku puzzle...

...and its solution numbers marked in red.

****************************************************/

class Solution {
public:
	void solveSudoku(std::vector<std::vector<char>>& board)
	{
		if (board.empty()) return;

		this->solveSudoku_impl(board, 0);
	}          

	bool solveSudoku_impl(std::vector<std::vector<char>>& board, int index)
	{
		while (index < 81 && board[index/9][index%9] != '.') ++index;
		if (index >= 81) return true;

		for (int i = 1; i < 10; ++i) {
			if (validSudoku(board, index/9, index%9, '0'+i)) {
				board[index/9][index%9] = '0' + i;
				if (solveSudoku_impl(board, index+1)) return true;
				board[index/9][index%9] = '.';
			}
		}

		return false;
	}

	bool validSudoku(std::vector<std::vector<char>>& board, int row, int col, char cc)
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
