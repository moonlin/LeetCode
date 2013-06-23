/*****************************************

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (1 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 6 -> 0 -> 8

*****************************************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(const ListNode* a, const ListNode* b)
	{
		return this->addTwoNumbers_Recursive(a, b, 0);
	}

	ListNode* addTwoNumbers_Recursive(const ListNode* a, const ListNode* b,
		int carry = 0)
	{
		if (!a && !b) {
			if (!carry) return 0;

			ListNode* pNode = new ListNode(carry);
			return pNode;
		}

		carry += a? a->val: 0;
		carry += b? b->val: 0;
		ListNode* pNode = new ListNode(carry % 10);
		ListNode* plast = addTwoNumbers_Recursive(a? a->next: 0, b? b->next: 0, carry/10);
		pNode->next = plast;

		return pNode;
	}

};
