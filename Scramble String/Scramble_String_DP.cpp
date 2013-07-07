/****************************************************************************************

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.


*****************************************************************************************/

class Solution {
public:
    bool isScramble(std::string& s1, std::string& s2)
	{
		if (s1.size() != s2.size()) return false;
		uint len = s1.size();
		std::vector<std::vector<std::vector<bool>>> dp (
					len+1, std::vector<std::vector<bool>> (s1.size(), 
					std::vector<bool>(s1.size(), false)));

		for (uint i = 0; i < s1.size(); ++i) {
			for (uint j = 0; j < s2.size(); ++j) {
				dp[1][i][j] = (s1[i] == s2[j]);
			}
		}

		for (uint k = 2; k <= len; ++k) {
			for (uint i = 0; i <= s1.size()-k; ++i) {
				for (uint j = 0; j <= s2.size()-k; ++j) {
					bool retValue = false;
					for (uint idx = 1; idx < k; ++idx) {
						if ((dp[idx][i][j] && dp[k-idx][i+idx][j+idx])
							 || (dp[idx][i][j+k-idx] && dp[k-idx][i+idx][j]))
						{
							retValue = true;
							break;
						}
					}

					dp[k][i][j] = retValue;
				}
			}
		}

		return dp[len][0][0];
	}
};

