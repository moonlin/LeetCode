/*****************************************

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*****************************************/

#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* pNode = head;
		for (int i = 1; i < n && pNode; ++i, pNode = pNode->next);
		if (pNode == 0) return 0;

		ListNode* pre = head;
		ListNode* parent = 0;
		while (pNode->next) {
			pNode = pNode->next;
			parent = pre;
			pre = pre->next;
		}

		if (parent) parent->next = pre->next;
		else head = pre->next;

		return head;
	}

};

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	Solution solve;
	ListNode* ret = solve.removeNthFromEnd(node1, 2);

	getchar();
	return 0;
}
