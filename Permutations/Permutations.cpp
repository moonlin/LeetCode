/**************************************************

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

**************************************************/

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
	std::vector<std::vector<int>> permute(std::vector<int>& num)
	{
		collection.clear();
		this->permute_impl(num, 0);

		return this->collection;
	}

	void permute_impl(std::vector<int>& num, uint pos)
	{
		if (pos >= num.size()-1) {
			this->collection.push_back(num);

			return;
		}

		for (int i = pos; i < num.size(); ++i) {
			std::swap(num[pos], num[i]);
			permute_impl(num, pos+1);
			std::swap(num[pos], num[i]);
		}
	}

private:
	std::vector<std::vector<int>> collection;
};

int main()
{
	int array[] = {1,2,3,4};
	std::vector<int> num(array, array+(sizeof(array)/sizeof(array[0])));

	Solution solve;
	std::vector<std::vector<int>> ret = solve.permute(num);

	getchar();
	return 0;
}
