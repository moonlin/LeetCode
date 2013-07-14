/******************************************************************

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

******************************************************************/

class Solution {
public:
    std::vector<int> findSubstring(std::string& str, std::vector<std::string>& lst)
	{
		std::vector<int> ret;
		if (str.empty() || lst.empty()) return ret;

		uint keySize = lst[0].size();
		if (lst.size()*keySize > str.size()) return ret;

		std::unordered_map<std::string, int> keyMap;
		for (uint i = 0; i < lst.size(); ++i) {
			if (keyMap.find(lst[i]) != keyMap.end()) ++keyMap[lst[i]];
			else keyMap[lst[i]] = 1;
		}

		for (uint i = 0; i <= str.size()-lst.size()*keySize; ++i) {
			std::unordered_map<std::string, int> tmpKeyMap(keyMap);
			for (uint j = i, k = 0; k < lst.size(); j += keySize, ++k) {
				std::string key(str.substr(j, keySize));
				std::unordered_map<std::string, int>::iterator iter = tmpKeyMap.find(key);
				if (iter == tmpKeyMap.end()) break;

				if (--(iter->second) == 0) 
					tmpKeyMap.erase(iter);

			}

			if (tmpKeyMap.empty()) ret.push_back(i);
		}

		return ret;
	}
};
