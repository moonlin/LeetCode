/***************************************************************

Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].

***************************************************************/

class Solution {
public:
    enum Direction {LEFT, DOWN, RIGHT, UP};

	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
	{
		std::vector<int> ret;
		if (matrix.empty()) return ret;

		matrix_.clear();
		matrix_.swap(matrix);

		isUsed_ = std::vector<std::vector<bool>> (matrix_.size(), 
						std::vector<bool>(matrix_[0].size(), false));

		int sum = matrix_.size() * matrix_[0].size();
		dfs(ret, 0, 0, Direction::RIGHT, sum);

		return ret;
	}

	void dfs(std::vector<int>& ret, int row, int col, Direction direction, int sum)
	{
		if (!ValidPlace(row, col)) return;

		ret.push_back(matrix_[row][col]);
		isUsed_[row][col] = true;
		if (--sum == 0) return;

		if (direction == Direction::RIGHT) {
			if (ValidPlace(row, col+1) && !isUsed_[row][col+1]) {
				dfs(ret, row, col+1, direction, sum);
			} else if (ValidPlace(row+1, col) && !isUsed_[row+1][col]) {
				dfs(ret, row+1, col, Direction::DOWN, sum);
			}

		} else if (direction == Direction::DOWN) {
			if (ValidPlace(row+1, col) && !isUsed_[row+1][col]) {
				dfs(ret, row+1, col, direction, sum);
			} else if (ValidPlace(row, col-1) && !isUsed_[row][col-1]) {
				dfs(ret, row, col-1, Direction::LEFT, sum);
			}

		} else if (direction == Direction::LEFT) {
			if (ValidPlace(row, col-1) && !isUsed_[row][col-1]) {
				dfs(ret, row, col-1, direction, sum);
			} else if (ValidPlace(row-1, col) && !isUsed_[row-1][col]) {
				dfs(ret, row-1, col, Direction::UP, sum);
			}

		} else if (direction == Direction::UP) {
			if (ValidPlace(row-1, col) && !isUsed_[row-1][col]) {
				dfs(ret, row-1, col, direction, sum);
			} else if (ValidPlace(row, col+1) && !isUsed_[row][col+1]) {
				dfs(ret, row, col+1, Direction::RIGHT, sum);
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
