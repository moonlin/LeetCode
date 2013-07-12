/************************************************

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

************************************************/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& num)
	{
		std::vector<std::vector<int>> ret;
		std::sort(num.begin(), num.end());
		std::vector<int> oneItem;
		for (uint i = 0; i < num.size(); ++i) {
			int plus1 = num[i];
			int l = i+1;
			int r = num.size()-1;
			while (l < r) {
				if (plus1 + num[r-1] + num[r] < 0) break;
				if (plus1 + num[l] + num[l+1] > 0) break;

				int sum = plus1 + num[l] + num[r];
				if (sum > 0) --r;
				else if (sum < 0) ++l;
				else {
					oneItem.clear();
					oneItem.push_back(num[i]);
					oneItem.push_back(num[l]);
					oneItem.push_back(num[r]);
					ret.push_back(oneItem);

					for (++l; l<r && num[l]==num[l-1]; ++l);
					for (--r; l<r && num[r]==num[r+1]; --r);
				}
			}

			for (; i < num.size()-1 && num[i]==num[i+1]; ++i);
		}

		return ret;
	}
};



