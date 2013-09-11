/***********************************************
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.

***********************************************/

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
	{
		if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;

		m_ = obstacleGrid.size();
		n_ = obstacleGrid[0].size();

		return uniquePathsWithObstacles_impl(obstacleGrid, 0, 0);
	}

	int uniquePathsWithObstacles_impl(std::vector<std::vector<int>>& obstacleGrid,
		int x, int y)
	{
		if (x == m_-1 && y == n_-1 && obstacleGrid[x][y] == 0) return 1;
		if (obstacleGrid[x][y] == 1) return 0;

		int sum = 0;
		if (validPlace(obstacleGrid, x+1, y)) {
			sum += uniquePathsWithObstacles_impl(obstacleGrid, x+1, y);
		}

		if (validPlace(obstacleGrid, x, y+1)) {
			sum += uniquePathsWithObstacles_impl(obstacleGrid, x, y+1);
		}

		return sum;
	}

	bool validPlace(std::vector<std::vector<int>>& obstacleGrid, 
		int x, int y)
	{
		if (x < 0 || x >= m_) return false;
		if (y < 0 || y >= n_) return false;
		
		return obstacleGrid[x][y] != 1;
	}
	
	private:
		int m_;
		int n_;
};
