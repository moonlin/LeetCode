/*******************************************

Given a linked list and a value x, partition it such that all nodes 
less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*******************************************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int val)
	{
		if (head == 0) return 0;

		ListNode* pre = 0;
		ListNode* pIndex = head;
		while (pIndex && pIndex->val < val) {
			pre = pIndex;
			pIndex = pIndex->next;
		}

		if (pIndex == 0) return head;
		ListNode* preIndex = pIndex;
		pIndex = pIndex->next;

		while (pIndex) {
			for (; pIndex && pIndex->val >= val; preIndex = pIndex, 
				pIndex = pIndex->next);

				if (pIndex) {
					ListNode* tmp = pIndex->next;
					if (preIndex) preIndex->next = tmp;
					if (pre) {
						pIndex->next = pre->next;
						pre->next = pIndex;
						pre = pIndex;
					} else {
						pIndex->next = head;
						head = pIndex;
						pre = pIndex;
					}

					pIndex = tmp;
				}

		}

		return head;
	}

};

int main()
{
	ListNode* node1 = new ListNode(3);
	ListNode* node2 = new ListNode(1);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(2);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(2);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	Solution solve;
	ListNode* pNode = solve.partition(node1, 3);

	getchar();
	return 0;
}
