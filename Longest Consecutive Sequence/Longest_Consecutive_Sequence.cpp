/****************************************************************************

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

****************************************************************************/

class Solution {
public:
	int longestConsecutive(std::vector<int>& num) 
	{
		if (num.empty()) return 0;

		std::map<int, int> statics;
		for (uint i = 0; i < num.size(); ++i) {
			statics[num[i]] = 1;
		}

		int gmax = 1;
		std::map<int, int>::iterator iter = statics.begin();
		for (; iter != statics.end(); ++iter) {
			std::map<int, int>::iterator iterPre = iter;
			std::map<int, int>::iterator iterTmp = iter;
			std::map<int, int>::iterator iterNext = ++iterTmp;
			
			if (iterNext == statics.end()) {
				return gmax;
			}

			while (iterNext != statics.end() && iterPre->first + 1 == iterNext->first) {
				iterNext->second += iterPre->second;
				iterPre = iterNext++;
			}

			gmax = std::max(gmax, iterPre->second);
			iter = iterPre;
		}

		return gmax;
	}

	int longestConsecutive(std::vector<int>& num)
	{

	}
	
};


int main()
{
	int a[] = {9,1,4,7,3,-1,0,5,8,-1,6};

	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));

	Solution solve;
	int cnt = solve.longestConsecutive(num);

	std::cout <<"NUM == " <<cnt <<'\n';

	getchar();
	return 0;
}

