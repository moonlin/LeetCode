/**********************************

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).

**********************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		vector<int> a(A, A + m);
		vector<int> b(B, B + n);
		if (m == 0) return getMedian(b);
		if (n == 0) return getMedian(a);

		return findMedianSortedArrays_impl(a, b);
	}

	double findMedianSortedArrays_impl(vector<int>& a, vector<int>& b)
	{
		uint i = 0;
		uint j = 0;
		vector<int> vec;
		while (i < a.size() && j < b.size()) {
			if (a[i] <= b[j]) vec.push_back(a[i++]);
			else vec.push_back(b[j++]);
		}

		while (i < a.size()) vec.push_back(a[i++]);
		while (j < b.size()) vec.push_back(b[j++]);

		return getMedian(vec);
	}

	double getMedian(vector<int>& vec)
	{
		int n = vec.size();
		return (n%2)? vec[n/2]: (vec[n/2-1] + vec[n/2]) / 2.0;
	}
};

int main()
{
	int A[]={1,3,6,7};
	int B[]={2,4,5,8};  
	int sizeA = sizeof(A)/sizeof(int); 
	int sizeB = sizeof(B)/sizeof(int);

	Solution solve;
	double ret = solve.findMedianSortedArrays(A, sizeA, B, sizeB);

	getchar();
	return 0;
}

