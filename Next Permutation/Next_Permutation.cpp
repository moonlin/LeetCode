/********************************************

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1

********************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

typedef unsigned int uint;

class Solution {
public:
	void nextPermutation(std::vector<int>& num)
	{
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

int main()
{
	int array[] = {5,4,7,5,3,2};
	std::vector<int> num(array, array+(sizeof(array)/sizeof(array[0])));

	Solution solve;
	solve.nextPermutation(num);

	getchar();
	return 0;
}
