/*****************************************************************

Given a 2D binary matrix filled with 0's and 1's, 
find the largest rectangle containing all ones and return its area.

for example:
[
"0110111111111111110",
"1011111111111111111",
"1101111111110111111",
"1111111111111011111",
"1111111111111101111",
"1110111011111111101",
"1011111111111101111",
"1111111111111110110",
"0011111111111110111",
"1101111111011111111",
"1111111110111111111",
"0110111011111111111",
"1111011111111101111",
"1111111111111111111",
"1111111111111111111",
"1111111111111111101",
"1111111101101101111",
"1111110111111110111"
]
the answer is :51

*****************************************************************/

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix)
	{
		if (matrix.empty()) return 0;

		uint XSize = matrix.size();
		uint ySize = matrix[0].size();
		std::vector<std::vector<std::list<std::pair<int, int>>>> dp(XSize, 
				std::vector<std::list<std::pair<int, int>>>
				(ySize, std::list<std::pair<int, int>>(1, std::pair<int, int>(0, 0))));

		dp[0][0] = matrix[0][0]=='1'? 
			std::list<std::pair<int, int>>(1, std::pair<int, int>(1, 1)): 
			std::list<std::pair<int, int>>(1, std::pair<int, int>(0, 0));

		int max = dp[0][0].front().first==1? 1: 0;
		for (uint i = 1; i < XSize; ++i) {
			if (matrix[i][0] == '1') {
				dp[i][0] = std::list<std::pair<int, int>>(1, std::pair<int, int>(1, 1 + dp[i-1][0].front().second));
				max = std::max(max, dp[i][0].front().second);
			}
		}

		for (uint j = 1; j < ySize; ++j) {
			if (matrix[0][j] == '1') {
				dp[0][j] = std::list<std::pair<int, int>>(1, std::pair<int, int>(1 + dp[0][j-1].front().first, 1));
				max = std::max(max, dp[0][j].front().first);
			}
		}
		
		for (uint i = 1; i < XSize; ++i) {
			for (uint j = 1; j < ySize; ++j) {
				if (matrix[i][j] == '0') continue;

				for (std::list<std::pair<int, int>>::iterator iterLeft = dp[i][j-1].begin();
					iterLeft != dp[i][j-1].end(); ++iterLeft)
				{
					for (std::list<std::pair<int, int>>::iterator iterTop = dp[i-1][j].begin();
						iterTop != dp[i-1][j].end(); ++iterTop)
					{
						int xSide = std::min(1 + iterLeft->first, iterTop->first);
						if (xSide == 0) {
							int k = j;
							for (dp[i][k].front().first=1, dp[i][k].front().second=1; 
								k > 0 && matrix[i][k-1]=='1'; ++dp[i][j].front().first, --k);

							max = std::max(max, dp[i][j].front().first);
							continue;
						}

						while (xSide < iterTop->first && matrix[i][j-xSide] == '1') ++xSide;

						int ySide = std::min(iterLeft->second, 1 + iterTop->second);
						if (ySide == 0) {
							int k = i;
							for (dp[k][j].front().first=1, dp[k][j].front().second=1; 
								k > 0 && matrix[k-1][j]=='1'; ++dp[i][j].front().second, --k);

							max = std::max(max, dp[i][j].front().second);
							continue;
						}

						while (ySide < iterLeft->second && matrix[i-ySide][j] == '1') ++ySide;

						if ((1 + iterLeft->first)*ySide > xSide*(1 + iterTop->second)) {
							dp[i][j] = std::list<std::pair<int, int>>(1, std::pair<int, int>(1 + iterLeft->first, ySide));
							max = std::max(max, (1 + iterLeft->first)*ySide);

						} else if (((1 + iterLeft->first)*ySide < xSide*(1 + iterTop->second))) {
							dp[i][j] = std::list<std::pair<int, int>>(1, std::pair<int, int>(xSide, 1 + iterTop->second));
							max = std::max(max, xSide*(1 + iterTop->second));

						} else {
							dp[i][j].clear();
							dp[i][j].push_back(std::pair<int, int> (1 + iterLeft->first, ySide));
							if (1 + iterLeft->first != xSide && ySide != 1 + iterTop->second) {
								dp[i][j].push_back(std::pair<int, int> (xSide, 1 + iterTop->second));
							}

							max = std::max(max, (1 + iterLeft->first)*ySide);
						}


					}
				}
			}
		}

		return max;
	}
};
