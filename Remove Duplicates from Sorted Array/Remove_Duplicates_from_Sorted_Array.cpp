/*****************************************

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

*****************************************/

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int removeDuplicates(int A[], int n)
	{
		int index = -1;
		for (int i = 1; i < n; ++i) {
			if (A[i] != A[i-1]) {
				if (index != -1) A[index++] = A[i];
				continue;
			}

			if (index == -1) index = i;
			for (++i; i < n && A[i] == A[i-1]; ++i);
			if (i >= n) return index;
			A[index++] = A[i];
		}

		return index==-1? n: index;
	} 

};

int main()
{
	int A[] = {1,1,2,2,3,4,5,6,7,7,7,7,8,9,9,9};
	Solution solve;
	int ret = solve.removeDuplicates(A, sizeof(A)/sizeof(A[0]));

	getchar();
	return 0;
}
