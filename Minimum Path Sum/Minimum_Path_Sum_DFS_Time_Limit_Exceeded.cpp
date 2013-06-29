/*************************************************

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*************************************************/

// Run Status: Time Limit Exceeded...

class Solution {
public:
    int minPathSum(const vector<vector<int>>& grid)
	{
		if (grid.empty()) return 0;
		minNum = INT_MAX;
		int num = 0;
		return dfs(grid, 0, 0, num)? minNum: 0;
	}        

	bool dfs(const vector<vector<int>>& grid, int row, int col, int num) 
	{
		if (row == grid.size()-1 && col == grid[row].size()-1) {
			num += grid[row][col];
			if (minNum == 0) minNum = num;

			minNum = std::min(minNum, num);
			return true;
		}

		num += grid[row][col];
		if (num > this->minNum) return false;

		bool found = false;
		if (validPlaced(grid, row+1, col)) {
			if (dfs(grid, row+1, col, num)) found = true;
		}

		if (validPlaced(grid, row, col+1)) {
			if (dfs(grid, row, col+1, num)) found = true;
		}

		return found;
	}

	bool validPlaced(const vector<vector<int>>& grid, int row, int col)
	{
		if (row >= grid.size()) return false;
		if (col >= grid[row].size()) return false;

		return true;
	}

private:
	int minNum;
};

