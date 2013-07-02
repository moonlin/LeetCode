/********************************************************

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

********************************************************/

// Run Status: Time Limit Exceeded...

class Solution {
public:
    std::string getPermutation(int n, int k)
	{
		std::vector<int> num(n, 0);
		std::vector<bool> status(n, false);

		this->getPermutation_impl(num, 0, k, status);

		return result;
	}

	void getPermutation_impl(std::vector<int>& num, uint pos, int& k, std::vector<bool>& status)
	{
		if (k <= 0) return;
		if (pos > num.size()-1) {
			result.clear();
			
			if (--k == 0) {
				for (int i = 0; i < num.size(); ++i) {
					result.push_back(num[i]+'0');
				}
			}

			return;
		}

		for (uint i = 0; i < num.size(); ++i) {
			if (status[i]) continue;

			status[i] = true;
			num[pos] = i+1;
			getPermutation_impl(num, pos+1, k, status);
			status[i] = false;
		}
	}

private:
	std::string result;
};
