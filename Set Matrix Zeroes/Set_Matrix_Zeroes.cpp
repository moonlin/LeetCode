/*************************************************************
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*************************************************************/

class Solution {
public:
	void setZeroes(std::vector<std::vector<int>>& matrix)
	{
		if (matrix.empty()) return;
		if (matrix[0].empty()) return;

		bool rowZeroFlag = false;
		for (uint i = 0; i < matrix.size(); ++i) {
			if (matrix[i][0] == 0) {
				rowZeroFlag = true;
				break;
			}
		}

		bool colZeroFlag = false;
		for (uint j = 0; j < matrix[0].size(); ++j) {
			if (matrix[0][j] == 0) {
				colZeroFlag = true;
				break;
			}
		}

		for (uint i = 1; i < matrix.size(); ++i) {
			for (uint j = 1; j < matrix[0].size(); ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (uint i = 1; i < matrix.size(); ++i) {
			for (uint j = 1; j < matrix[0].size(); ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
			}
		}

		if (rowZeroFlag) {
			for (uint i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
		}

		if (colZeroFlag) {
			for (uint j = 0; j < matrix[0].size(); ++j) matrix[0][j] = 0;
		}

	}

};
