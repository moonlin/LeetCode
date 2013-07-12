/**************************************************************

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

**************************************************************/

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& num, int target)
	{
		std::vector<std::vector<int>> ret;
		std::sort(num.begin(), num.end());
		for (uint i = 0; i < num.size(); ++i) {
			int plus1 = num[i];
			for (uint j = i+1; j < num.size(); ++j) {
				int plus2 = num[j];
				int l = j+1;
				int r = num.size()-1;
				while (l < r) {
					if (plus1 + plus2 + num[r-1] + num[r] < target) break;
					if (plus1 + plus2 + num[l] + num[l+1] > target) break;

					int sum = plus1 + plus2 + num[l] + num[r];
					if (sum > target) --r;
					else if (sum < target) ++l;
					else {
						std::vector<int> oneItem;
						oneItem.push_back(num[i]);
						oneItem.push_back(num[j]);
						oneItem.push_back(num[l]);
						oneItem.push_back(num[r]);
						ret.push_back(oneItem);

						for (++l; l<r && num[l]==num[l-1]; ++l);
						for (--r; l<r && num[r]==num[r+1]; --r);
					}
				}

				for (; j < num.size()-1 && num[j]==num[j+1]; ++j);
			}
			
			for (; i < num.size()-1 && num[i]==num[i+1]; ++i);
		}

		return ret;
	}
};
