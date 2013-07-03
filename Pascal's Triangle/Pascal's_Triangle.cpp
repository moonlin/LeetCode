/*****************************************************

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*****************************************************/

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows)
	{
		std::vector<std::vector<int>> retTriangle;
		retTriangle.resize(numRows);
		for (int i = 0; i < numRows; ++i) {
			retTriangle[i].assign(i+1, 1);
		}

		for (int i = 2; i < numRows; ++i) {
			for (int j = 1; j < retTriangle[i].size()-1; ++j)
				retTriangle[i][j] = retTriangle[i-1][j-1] + retTriangle[i-1][j];
		}

		return retTriangle;
	}
};
