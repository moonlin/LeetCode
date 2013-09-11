/***************************************************
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.

***************************************************/

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
	{
		if (matrix.empty()) return false;
		if (matrix[0].empty()) return false;

		int rowNum = matrix.size();
		int colNum = matrix[0].size();

		int l = 0;
		int r = rowNum-1;
		int mid = -1;
		while (l <= r) {
			mid = (l+r)/2;
			if (matrix[mid][0] <= target && matrix[mid][colNum-1] >= target)
				break;
			else if (matrix[mid][0] >= target)
				r = mid-1;
			else if (matrix[mid][colNum-1] <= target)
				l = mid+1;
		}

		if (mid < 0 || mid > rowNum-1) return false;
		
		l = 0;
		r = colNum-1;
		while (l <= r) {
			int mid2 = (l+r)/2;
			if (matrix[mid][mid2] == target) return true;
			else if (matrix[mid][mid2] <= target)
				l = mid2+1;
			else 
				r = mid2-1;
		}

		return false;
	}
	
};
