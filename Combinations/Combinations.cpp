/*****************************************

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*****************************************/

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
	{
		ret.clear();
		vector<int> seqK;
		this->combine_impl(n, 1, k, seqK);

		return ret;
	}

	void combine_impl(int n, int pos, int k, vector<int>& seqK)
	{
		if (pos > n && k > 0) return;
		if (k == 0) {
			ret.push_back(seqK);
			return;
		}

		for (int i = pos; i <= n; ++i) {
			seqK.push_back(i);
			combine_impl(n, i+1, k-1, seqK);
			seqK.pop_back();
		}
	}

private:
	vector<vector<int>> ret;
};
