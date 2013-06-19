/*****************************************

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (head == 0) return 0;

		ListNode* pre = 0;
		ListNode* pNode = head;
		if (pNode == 0) return head;

		while (pNode) {
			while (pNode->next && pNode->val != pNode->next->val) {
				pre = pNode;
				pNode = pNode->next;
			}

			if (pNode->next == 0) return head;

			for (; pNode->next && pNode->val == pNode->next->val; pNode = pNode->next);

			if (pre) {
				pre->next = pNode->next;
				pNode = pre->next;
			} else {
				head = pNode->next;
				pNode = head;
			}

		}

		return head;
	}

};

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(3);
	ListNode* node5 = new ListNode(4);
	ListNode* node6 = new ListNode(4);
	ListNode* node7 = new ListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;

	Solution solve;
	ListNode* ptr = solve.deleteDuplicates(node1);

	getchar();
	return 0;
}
