/***************************************************************

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

***************************************************************/

class Solution {
public:
    enum Direction {LEFT, DOWN, RIGHT, UP};

	std::vector<std::vector<int>> generateMatrix(int n)
	{
		if (n < 0) return matrix_;

		matrix_ = std::vector<std::vector<int>> (n, std::vector<int>(n, -1));
		isUsed_ = std::vector<std::vector<bool>> (n, std::vector<bool>(n, false));
		dfs(0, 0, Direction::RIGHT, 1, n*n);
		return matrix_;
	}

	void dfs(int row, int col, Direction direction, int val, int sum)
	{
		if (!ValidPlace(row, col)) return;

		matrix_[row][col] = val;
		isUsed_[row][col] = true;
		if (val == sum) return;

		++val;
		if (direction == Direction::RIGHT) {
			if (ValidPlace(row, col+1) && !isUsed_[row][col+1]) {
				dfs(row, col+1, direction, val, sum);
			} else if (ValidPlace(row+1, col) && !isUsed_[row+1][col]) {
				dfs(row+1, col, Direction::DOWN, val, sum);
			}

		} else if (direction == Direction::DOWN) {
			if (ValidPlace(row+1, col) && !isUsed_[row+1][col]) {
				dfs(row+1, col, direction, val, sum);
			} else if (ValidPlace(row, col-1) && !isUsed_[row][col-1]) {
				dfs(row, col-1, Direction::LEFT, val, sum);
			}

		} else if (direction == Direction::LEFT) {
			if (ValidPlace(row, col-1) && !isUsed_[row][col-1]) {
				dfs(row, col-1, direction, val, sum);
			} else if (ValidPlace(row-1, col) && !isUsed_[row-1][col]) {
				dfs(row-1, col, Direction::UP, val, sum);
			}

		} else if (direction == Direction::UP) {
			if (ValidPlace(row-1, col) && !isUsed_[row-1][col]) {
				dfs(row-1, col, direction, val, sum);
			} else if (ValidPlace(row, col+1) && !isUsed_[row][col+1]) {
				dfs(row, col+1, Direction::RIGHT, val, sum);
			}

		}
	}

	bool ValidPlace(int row, int col)
	{
		if (row < 0 || row >= matrix_.size()) return false;
		if (col < 0 || col >= matrix_[0].size()) return false;

		return true;
	}

private:
	std::vector<std::vector<int>> matrix_;
	std::vector<std::vector<bool>> isUsed_;
};
