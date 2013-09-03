/*****************************************************

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

*****************************************************/

class Solution {
public:
	std::vector<std::string> anagrams(std::vector<std::string>& strs)
	{
		std::unordered_map<std::string, std::vector<std::string>> keyValue;
		for (uint i = 0; i < strs.size(); ++i) {
			std::string key = strs[i];
			std::sort(key.begin(), key.end());
			keyValue[key].push_back(strs[i]);
		}

		std::vector<std::string> retVec;
		std::unordered_map<std::string, std::vector<std::string>>::iterator iter;
		for (iter = keyValue.begin(); iter != keyValue.end(); ++iter) {
			if (iter->second.size() < 2) continue;
			
			retVec.insert(retVec.end(), iter->second.begin(), iter->second.end());
		}

		return retVec;
	}
};
