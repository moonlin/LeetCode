/********************************************************

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

********************************************************/

class Solution {
public:
    std::vector<int> getRow(int rowIndex)
	{
		std::vector<int> retVec;
		retVec.push_back(1);

		int index = 0;
		while (index < rowIndex) {
			for (uint i = retVec.size()-1; i > 0; --i)
				retVec[i] = retVec[i] + retVec[i-1];

			retVec.push_back(1);
			++index;
		}
		
		return retVec;
	}
};
