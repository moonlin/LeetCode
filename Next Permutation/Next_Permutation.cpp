/********************************************

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 --> 1,3,2
3,2,1 --> 1,2,3
1,1,5 --> 1,5,1

********************************************/

class Solution {
public:
	void nextPermutation(std::vector<int>& num)
	{
		if (num.empty() || num.size() == 1) return;

		int index = num.size()-2;
		while (index >= 0 && num[index] >= num[index+1]) --index;
		if (index < 0) {
			std::reverse(num.begin(), num.end());
			return;
		}

		int i;
		for (i = num.size()-1; i > index && num[index] >= num[i]; --i);
		std::swap(num[index], num[i]);
		std::reverse(num.begin()+index+1, num.end());
	}
};
