/****************************************************

Given n non-negative integers representing the histogram's bar height 
where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

****************************************************/

class Solution {
public:
    int largestRectangleArea(vector<int>& height)
	{
		if (height.empty()) return 0;

		int max = INT_MIN;
		std::stack<int> recStack;
		for (uint i = 0; i < height.size(); ++i) {
			while (!recStack.empty() && height[recStack.top()] > height[i]) {
				int idx = recStack.top();
				int curr = i;
				recStack.pop();
				max = std::max(max, height[idx]*(recStack.empty()?curr :curr-recStack.top()-1));
			}

			recStack.push(i);
		}

		int curr = height.size();
		while (!recStack.empty()) {
			int idx = recStack.top();
			recStack.pop();
			max = std::max(max, height[idx]*(recStack.empty()?curr :curr-recStack.top()-1));
		}

		return max;
	}
};
