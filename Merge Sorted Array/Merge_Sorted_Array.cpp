/****************************************

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.

****************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

class Solution {
public:
	void merge(int A[], int m, int B[], int n)
	{
		int i = m-1;
		int j = n-1;
		int k = m+n-1;
		while (i >= 0 && j >= 0) {
			A[k--] = A[i]<B[j]? B[j--]: A[i--];
		}

		while (j >= 0) A[k--] = B[j--];
	}

};

int main()
{
	int A[] = {1, 3, 5, 6, 8, 0, 0, 0, 0, 0};
	int B[] = {2, 4, 7, 9, 11};
	Solution solve;
	solve.merge(A, 5, B, 5);

	getchar();
	return 0;
}
