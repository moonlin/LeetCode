/************************************************************************

Given two words (start and end), and a dictionary, 
find all shortest transformation sequence(s) from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:

    All words have the same length.
    All words contain only lowercase alphabetic characters.

************************************************************************/

class Solution {
	typedef std::vector<std::vector<std::string>> RetVec;
	typedef std::pair<std::string, int> Pair;
	typedef std::unordered_map<std::string, std::unordered_set<std::string>> AdiacencyMap;
public:
	RetVec findLadders(std::string& start, std::string& end, std::unordered_set<std::string>& dict)
	{
		if (dict.count(start) == 0) dict.insert(start);
		if (dict.count(end) == 0) dict.insert(end);

		AdiacencyMap adjacency;
		buildAdjacency(dict, adjacency);

		backtrace_.clear();
		visited_.clear();
		visited_.insert(start);
		std::queue<std::string> bsfQue;
		bsfQue.push(start);
		int levelCnt = 1;
		int levels = 0;
		bool finished = false;
		while (!bsfQue.empty() && !finished) {
			int loopCnt = levelCnt;
			levelCnt = 0;
			++levels;
			for (int i = 0; i < loopCnt; ++i) {
				std::string elem = bsfQue.front();
				bsfQue.pop();
				if (valid(elem, end)) {
					backtrace_[end].insert(Pair(elem, levels));
					finished = true;
					continue;
				}

				auto iter = adjacency.find(elem);
				if (iter == adjacency.end()) continue;

				for (auto iterSet = iter->second.begin();
					iterSet != iter->second.end(); ++iterSet)
				{
					if (visited_.find(*iterSet) == visited_.end()) {
						visited_.insert(*iterSet);
						bsfQue.push(*iterSet);
						++levelCnt;
					}

					backtrace_[*iterSet].insert(Pair(elem, levels));
				}
			}
		}

		++levels;
		RetVec ret;
		std::list<std::string> oneSolution;
		oneSolution.push_front(end);
		buildPath(ret, oneSolution, start, end, levels);

		return ret;
	}

	void buildPath(RetVec& ret, std::list<std::string>& oneSolution,
		const std::string& start, const std::string& end, int levels)
	{
		if (start == end) {
			std::vector<std::string> tmpSolution(oneSolution.begin(), oneSolution.end());
			ret.push_back(tmpSolution);
			return;
		}

		--levels;
		if (levels < 0) return;
		for (auto iter = backtrace_[end].begin(); iter != backtrace_[end].end(); ++iter) {
			if (iter->second == levels) {
				oneSolution.push_front(iter->first);
				buildPath(ret, oneSolution, start, iter->first, iter->second);
				oneSolution.pop_front();
			}
		}
	}

	void buildAdjacency(std::unordered_set<std::string>& dict, AdiacencyMap& adjacency)
	{
		for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
			std::string elem = *iter;
			for (uint i = 0; i < elem.size(); ++i) {
				for (char cc = 'a'; cc <= 'z'; ++cc) {
					if (elem[i] != cc) {
						std::string tmpElem(elem);
						tmpElem[i] = cc;
						if (dict.count(tmpElem)) adjacency[elem].insert(tmpElem);
					}
				}
			}
		}
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

	struct hashValue {
		size_t operator() (const Pair& pair) const {
			size_t seed = 0;
			std::hash<std::string> hasher;
			seed ^= hasher(pair.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			// seed = std::hash<std::string>()(pair.first);
			return seed;                       
		}
	};

	struct keyEqual {
		bool operator() (const Pair& lhs, const Pair& rhs) const {
			return lhs.first == rhs.first;
		}
	};

private:
	std::unordered_set<string> visited_;
	std::unordered_map<std::string, std::unordered_set<Pair, hashValue, keyEqual>> backtrace_;
};
