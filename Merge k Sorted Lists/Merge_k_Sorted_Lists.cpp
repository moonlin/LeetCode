/***************************************

Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

***************************************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(const std::vector<ListNode*>& lists) 
	{
		if (lists.empty()) return 0;

		return mergeKLists_impl(lists, 0, lists.size()-1);
	}          

	ListNode* mergeKLists_impl(const std::vector<ListNode *>& lists, int l, int r)
	{
		if (l >= r) return lists[l];

		int mid = (l+r)/2;
		ListNode* left = mergeKLists_impl(lists, l, mid);
		ListNode* right = mergeKLists_impl(lists, mid+1, r);

		return merge(left, right);
	}

	ListNode* merge(ListNode* left, ListNode* right)
	{
		ListNode* head = 0;
		ListNode* pre = head;
		while (left && right) {
			ListNode*& ptmp = (left->val <= right->val)? left: right;
			if (head == 0) {
				head = ptmp, pre = head;
			} else {
				pre->next = ptmp;
				pre = ptmp;
			}

			ptmp = ptmp->next;
		}

		ListNode*& ptmp = left? left: right;
		if (pre == 0) return head = ptmp;

		while (ptmp) {
			pre->next = ptmp;
			pre = ptmp;
			ptmp = ptmp->next;
		}

		return head;
	}

};
