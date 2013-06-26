/***************************************

Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity.

***************************************/

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
	ListNode* mergeKLists(const vector<ListNode*>& lists) 
	{
		if (lists.empty()) return 0;

		return mergeKLists_impl(lists, 0, lists.size()-1);
	}          

	ListNode* mergeKLists_impl(const vector<ListNode *>& lists, int l, int r)
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

int main()
{
	ListNode* head1 = new ListNode(1);
	ListNode* node11 = new ListNode(2);
	ListNode* node12 = new ListNode(3);
	head1->next = node11;
	node11->next = node12;

	ListNode* head2 = new ListNode(4);
	ListNode* node21 = new ListNode(5);
	ListNode* node22 = new ListNode(6);
	ListNode* node23 = new ListNode(7);
	head2->next = node21;
	node21->next = node22;
	node22->next = node23;

	ListNode* head3 = new ListNode(3);
	ListNode* node31 = new ListNode(4);
	ListNode* node32 = new ListNode(11);
	head3->next = node31;
	node31->next = node32;

	vector<ListNode *> lists;
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(head3);

	Solution solve;
	ListNode* ret = solve.mergeKLists(lists);

	getchar();
	return 0;
}
