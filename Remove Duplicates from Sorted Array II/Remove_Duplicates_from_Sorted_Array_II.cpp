/*******************************************

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*******************************************/

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

			if (i < n-1 && A[i] == A[i+1]) {
				if (index != -1) A[index++] = A[i];
				if (index == -1) index = ++i;
				for (++i; i < n && A[i] == A[i-1]; ++i);
				if (i < n) A[index++] = A[i];
				continue;
			} 

			if (index != -1) A[index++] = A[i];
		}

		return index==-1? n: index;
	} 

};

int main()
{
	int A[] = {1,2};
	Solution solve;
	int ret = solve.removeDuplicates(A, sizeof(A)/sizeof(A[0]));
	A[ret] = 0;

	getchar();
	return 0;
}
