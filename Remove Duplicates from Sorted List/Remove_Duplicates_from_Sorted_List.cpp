/***************************************

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

***************************************/

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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == 0) return 0;

		ListNode* pre = head;
		ListNode* pNode = head->next? head->next: 0;
		if (pNode == 0) return head;

		while (pre) {
			while (pNode && pre->val != pNode->val) {
				pre = pNode;
				pNode = pNode->next;
			}

			if (pNode == 0) return head;
			for (; pNode->next && pNode->val == pNode->next->val; pNode = pNode->next);

			pre->next = pNode->next;
			delete pNode;
			pNode = pre->next;
		}
	}

};

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(1);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(3);
	ListNode* node5 = new ListNode(3);
	ListNode* node6 = new ListNode(4);
	ListNode* node7 = new ListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;

	Solution solve;
	solve.deleteDuplicates(node1);

	getchar();
	return 0;
}
