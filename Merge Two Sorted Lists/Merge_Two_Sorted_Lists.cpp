/********************************************

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

********************************************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == 0) return l2;
		if (l2 == 0) return l1;

		ListNode* head = l1->val<=l2->val? l1: l2;
		ListNode* pre = head;
		ListNode* pLink = head->next;
		ListNode* ptr = head==l1? l2: l1;
		while (pLink && ptr) {
			while (pLink && pLink->val <= ptr->val) {
				pre = pLink;
				pLink = pLink->next;
			}

			if (pLink == 0) break;
			while (ptr && pLink->val > ptr->val) {
				ListNode* ptmp = ptr;
				ptr = ptr->next;
				ptmp->next = pLink;
				pre->next = ptmp;
				pre = ptmp;
			}
		}

		if (ptr) pre->next = ptr;
		
		return head;
	}        
};
