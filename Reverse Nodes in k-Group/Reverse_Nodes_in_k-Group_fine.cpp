/*************************************

 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*************************************/

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
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (head == 0 || k == 1) return head;
		
		return this->reverseKGroup_impl(head, k);
	}          

	ListNode* reverseKGroup_impl(ListNode* head, int k)
	{
		if (head == 0) return head;

		ListNode* pNode = head;
		for (int i = 0; i < k; ++i) {
			if (pNode == 0) return head;
			pNode = pNode->next;
		}

		pNode = head;
		ListNode* pNext = 0;
		ListNode* pPre = 0;
		int index;
		for (int index = 0; index < k && pNode; ++index) {
			pNext = pNode->next;
			pNode->next = pPre;
			pPre = pNode;
			pNode = pNext;
		}

		head->next = reverseKGroup_impl(pNext, k);

		return head = pPre;
	}

};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);
	ListNode* node4 = new ListNode(5);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	Solution solve;
	ListNode* ret = solve.reverseKGroup(head, 3);

	getchar();
	return 0;
}

