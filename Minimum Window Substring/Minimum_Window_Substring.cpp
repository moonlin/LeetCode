/*****************************************************************

Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that 
there will always be only one unique minimum window in S.

*****************************************************************/

// "std::vector<char>" not "std::vector<int>" is a bull shit thing, which will overflow in some cases.

class Solution {
public:
    std::string minWindow(std::string& S, std::string& T)
	{
		if (S.empty() || T.empty()) return "";

		const uint maxChar = 256;
		std::vector<int> charAt(maxChar, 0);
		for (uint i = 0; i < T.size(); ++i) {
			++charAt[T[i]];
		}

		std::vector<int> charAtBak(maxChar, 0);
		int min_s = -1;
		uint minSize = INT_MAX;
		uint count = 0;
		uint beginPos = 0;
		for (uint i = 0; i < S.size(); ++i) {
			if (charAt[S[i]] == 0) continue;

			++charAtBak[S[i]];
			if (charAtBak[S[i]] <= charAt[S[i]]) ++count;

			if (count == T.size()) {
				while (charAt[S[beginPos]] == 0 || charAt[S[beginPos]] < charAtBak[S[beginPos]]) {
					if (charAt[S[beginPos]] < charAtBak[S[beginPos]]) --charAtBak[S[beginPos]];

					++beginPos;
				}

				if (minSize > i-beginPos+1) {
					min_s = beginPos;
					minSize = i-beginPos+1;
				}
			}
		}

		if (minSize == INT_MAX) return "";
			
		return S.substr(min_s, minSize);
	}
};
