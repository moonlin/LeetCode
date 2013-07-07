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

// Time Limit Exceeded...

class Solution {
public:
    bool isScramble(std::string& s1, std::string& s2)
	{
		return this->isScramble_impl(s1, s2, 0, s1.size()-1, 0, s2.size()-1);
	}

	bool isScramble_impl(std::string& s1, std::string& s2, 
								uint l1, uint r1, uint l2, uint r2)
	{
		if (l1 == r1 && l2 == r2) return s1[l1] == s2[l2]? true: false;
		if (l1+1 == r1 && l2+1 == r2) {
			if (s1[l1] == s2[r2] && s1[r1] == s2[l2]) return true;
			if (s1[l1] == s2[l2] && s1[r1] == s2[r2]) return true;
			
			return false;
		}

		std::string tmp1(s1);
		std::string tmp2(s2);
		std::sort(tmp1.begin(), tmp1.end());
		std::sort(tmp2.begin(), tmp2.end());
		if (tmp1 != tmp2) return false;

		for (uint i = l1; i < r1; ++i) {
			if (isScramble_impl(s1, s2, l1, i, l2, l2+(i-l1)) 
						&& isScramble_impl(s1, s2, i+1, r1, r2-(r1-i-1), r2)) 
			{
				return true;
			}

			if (isScramble_impl(s1, s2, l1, i, r2-(i-l1), r2) 
						&& isScramble_impl(s1, s2, i+1, r1, l2, l2+(r1-i-1))) 
			{
				return true;
			}
		}

		return false;
	}
};
