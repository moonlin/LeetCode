/**********************************************
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

**********************************************/

class Solution {
public:
    int uniquePaths(int m, int n)
	{
		if (m == 0 || n == 0) return 0;

		m_ = m;
		n_ = n;

		return uniquePaths_impl(0, 0);
	}

    int uniquePaths_impl(int x, int y)
	{
		if (x == m_-1 && y == n_-1) return 1;

		int sum = 0;
		if (validPlace(x+1, y)) {
			sum += uniquePaths_impl(x+1, y);
		}

		if (validPlace(x, y+1)) {
			sum += uniquePaths_impl(x, y+1);
		}

		return sum;
	}
	
	bool validPlace(int x, int y)
	{
		if (x < 0 || x >= m_) return false;
		if (y < 0 || y >= n_) return false;

		return true;
	}

private:
	int m_;
	int n_;
};
