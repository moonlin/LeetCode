/****************************************************************

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

****************************************************************/

// DFS: Time Limit Exceeded...

class Solution {
public:
    int ladderLength(string& start, string& end, unordered_set<string>& dict)
	{
		visited.clear();
		visited.insert(start);
		
		return dfs(start, end, dict);
	}

	int dfs(const string& start, const string& end, unordered_set<string>& dict)
	{
		if (valid(start, end)) return 2;

		unordered_set<string>::iterator iter = dict.begin();
		int min = INT_MAX;
		for (; iter != dict.end(); ++iter) {
			if (visited.find(*iter) == visited.end() && valid(start, *iter)) {
				visited.insert(*iter);
				int ret = dfs(*iter, end, dict);
				visited.erase(*iter);

				if (ret != -1) min = std::min(min, ret+1);
			}
		}

		return min==INT_MAX? 0: min;
	}

	bool valid(const string& start, const string& end)
	{
		if (start.size() != end.size()) return false;
		
		int diff = 0;
		for (int i = 0; i < start.size(); ++i) {
			if (start[i] != end[i]) ++diff;
			if (diff > 1) return false;
		}

		return diff == 1;
	}

private:
	unordered_set<string> visited;
};
