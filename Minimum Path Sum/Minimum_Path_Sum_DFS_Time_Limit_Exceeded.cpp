/*************************************************
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*************************************************/
// Run Status: Time Limit Exceeded...

class Solution {
public:
    int minPathSum(const std::vector<std::vector<int>>& grid)
	{
		if (grid.empty()) return 0;

		minNum = INT_MAX;
		int num = 0;
		dfs(grid, 0, 0, num);

		return minNum;
	}        

	void dfs(const std::vector<std::vector<int>>& grid, int row, int col, int num) 
	{
		if (row == grid.size()-1 && col == grid[row].size()-1) {
			num += grid[row][col];

			minNum = std::min(minNum, num);
			return;
		}

		num += grid[row][col];
		if (num > this->minNum) return;

		if (validPlaced(grid, row+1, col)) {
			dfs(grid, row+1, col, num);
		}

		if (validPlaced(grid, row, col+1)) {
			dfs(grid, row, col+1, num);
		}
	}

	bool validPlaced(const std::vector<std::vector<int>>& grid, int row, int col)
	{
		if (row < 0 || row >= grid.size()) return false;
		if (col < 0 || col >= grid[row].size()) return false;

		return true;
	}

private:
	int minNum;
};
