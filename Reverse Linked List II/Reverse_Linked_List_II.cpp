/*****************************************Reverse a linked list from position m to n. Do it in-place and in one-pass.For example:Given 1->2->3->4->5->NULL, m = 2 and n = 4,return 1->4->3->2->5->NULL.Note:Given m, n satisfy the following condition:1 <= m <= n <= length of list.*****************************************/struct ListNode {	int val;	ListNode *next;	ListNode(int x) : val(x), next(NULL) {}};class Solution {public:	ListNode* reverseBetween(ListNode* head, int m, int n)	{		if (head == 0) return head;		ListNode* preM = 0;		ListNode* pNode = head;		for (int i = 0; i < m && pNode; ++i) {			preM = pNode;			pNode = pNode->next;		}		if (pNode == 0) return head;		ListNode* pEnd = pNode;		ListNode* preN = 0;		for (int i = 1; i < n-m && pNode; ++i) {			ListNode* pNext = pNode->next;			pNode->next = preN;			preN = pNode;			pNode = pNext;		}		if (pNode == 0) {			if (preM) preM->next = preN;			else head = preN;			return head;		}		ListNode* pTail = pNode->next;		if (preM) {			preM->next = pNode;		} else {			head = pNode;		}		pEnd->next = pTail;		return head;	}	};int main(){		ListNode* l1 = new ListNode(-1);	ListNode* l2 = new ListNode(-3);	ListNode* l3 = new ListNode(3);	l1->next = l2;	//l2->next = l3;	Solution solve;	ListNode* ret = solve.reverseBetween(l1, 1, 2);	getchar();	return 0;}