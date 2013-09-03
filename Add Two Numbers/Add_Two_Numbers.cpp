/*****************************************

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (1 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 6 -> 0 -> 8

*****************************************/

class Solution {
public:
    ListNode* addTwoNumbers(const ListNode* a, const ListNode* b)
	{
		ListNode* pLink = 0;
		ListNode* head = 0;
		int carry = 0;
		while (a && b) {
			carry = a->val + b->val + carry;
			ListNode* ptmp = new ListNode(carry%10);
			carry /= 10;

			!pLink? (pLink = ptmp, head = pLink): (pLink->next = ptmp, pLink = ptmp);
			a = a->next;
			b = b->next;
		}

		const ListNode* ptr = a? a: b;
		while (ptr) {
			carry = ptr->val + carry;
			ListNode* ptmp = new ListNode(carry%10);
			carry /= 10;
			!pLink? (pLink = ptmp, head = pLink): (pLink->next = ptmp, pLink = ptmp);
			ptr = ptr->next;
		}

		if (carry) {
			ListNode* ptmp = new ListNode(carry);
			pLink->next = ptmp;
		}

		return head;
	}

};
