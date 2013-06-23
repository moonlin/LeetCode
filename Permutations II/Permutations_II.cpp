/****************************************

 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

****************************************/

class Solution {
public:
	std::vector<std::vector<int>> permuteUnique(std::vector<int>& num)
	{
		collection.clear();
		this->permuteUnique_impl(num, 0);

		return this->collection;
	}

	void permuteUnique_impl(std::vector<int>& num, uint pos)
	{
		if (pos >= num.size()-1) {
			this->collection.push_back(num);

			return;
		}

		permuteUnique_impl(num, pos+1);
		std::set<int> numSet;
		numSet.insert(num[pos]);
		for (int i = pos+1; i < num.size(); ++i) {
			if (numSet.find(num[i]) != numSet.end()) continue;

			numSet.insert(num[i]);
			std::swap(num[pos], num[i]);
			permuteUnique_impl(num, pos+1);
			std::swap(num[pos], num[i]);
		}
	}

private:
	std::vector<std::vector<int>> collection;
};
