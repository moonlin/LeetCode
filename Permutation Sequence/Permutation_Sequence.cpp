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

class Solution {
public:
    std::string getPermutation(int n, int k)
	{
		memset(status, false, 10);
		result.resize(n);

		this->getPermutation_impl(0, k, n);

		return result;
	}

	bool getPermutation_impl(uint pos, int& k, int n)
	{
		if (k <= 0) return false; 
		if (pos >= n) {
			if (--k == 0) {
				for (int i = 0; i < n; ++i) {
					result[i] = num[i]+'0';
				}

				return true;
			}

			return false;
		}

		for (uint i = 0; i < n; ++i) {
			if (status[i] == false) {
				status[i] = true;
				num[pos] = i+1;
				if (getPermutation_impl(pos+1, k, n)) return true;

				status[i] = false;
			}
		}

		return false;
	}

private:
	int num[9];
	bool status[9];
	std::string result;
};

