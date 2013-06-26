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

// change only two element, not all the elements...

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
		for (int i = 1; i < k-1 && pNode->next; ++i, pNode = pNode->next);
		if (pNode->next == 0) return head;
		ListNode* pswap = pNode->next;

		ListNode* pNext = reverseKGroup_impl(pswap->next, k);


		if (head == pNode) {
			head->next = pNext;
			pswap->next = head;

		} else {
			pswap->next = head->next;
			pNode->next = head;
			head->next = pNext;
		}

		return head = pswap;
	}

};
