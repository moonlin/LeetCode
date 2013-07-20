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

class Solution {
public:
    int ladderLength(std::string& start, std::string& end, std::unordered_set<std::string>& dict)
	{
		visited.clear();
		visited.insert(start);
		
		std::queue<std::string> ladderQue;
		ladderQue.push(start);
		int levels = 0;
		int levelCnt = 1;
		while (!ladderQue.empty()) {
			int loopCnt = levelCnt;
			levelCnt = 0;
			++levels;
			for (int i = 0; i < loopCnt; ++i) {
				std::string elem = ladderQue.front();
				ladderQue.pop();
				if (valid(elem, end)) return ++levels;

				// Traversal the hash set is a bad ideal,
				// search in hash set is O(1), but we traversal the whole hash set is O(n)
				
				/***
				unordered_set<string>::iterator iter = dict.begin();
				for (; iter != dict.end(); ++iter) {
					if (visited.find(*iter) == visited.end() && valid(elem, *iter)) {
						ladderQue.push(*iter);
						visited.insert(*iter);
						++levelCnt;
					}
				} ***/

				for (uint i = 0; i < elem.size(); ++i) {
					std::string tmpElem(elem);
					for (int j = 0; j < 'z'-'a' + 1; ++j) {
						tmpElem[i] = 'a' + j;
						if (dict.find(tmpElem) != dict.end()
										&& visited.find(tmpElem) == visited.end()) 
						{
							visited.insert(tmpElem);
							ladderQue.push(tmpElem);
							++levelCnt;
						}
					}
				}

			}
		}

		return 0;
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
	std::unordered_set<string> visited;
};
