/***********************************

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

{1,2,3,4,5}, 0	{1,2,3,4,5}
 
{1,2,3,4,5}, 1	{5,1,2,3,4}
 
{1,2,3,4,5}, 2	{4,5,1,2,3}
 
{1,2,3,4,5}, 3	{3,4,5,1,2}
 
{1,2,3,4,5}, 4	{2,3,4,5,1}
 
{1,2,3,4,5}, 5	{1,2,3,4,5}
 
{1,2,3,4,5}, 6	{5,1,2,3,4}
 
{1,2,3,4,5}, 7	{4,5,1,2,3}
 
{1,2,3,4,5}, 8	{3,4,5,1,2}
 
{1,2,3,4,5}, 9	{2,3,4,5,1}
 
{1,2,3,4,5}, 10	{1,2,3,4,5}

***********************************/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
	{
		if (head == 0) return head;

		ListNode* pre = 0;
		ListNode* pstart = head;
		ListNode* plast = head;

		int num = 0;
		for (; pstart; pstart = pstart->next, ++num);
		k = k%num;
		if (k == 0) return head;

		pstart = head;
		for (int i = 1; i < k && plast; ++i, plast = plast->next);
		if (plast == 0 || plast->next == 0) return head;

		while (plast->next) {
			pre = pstart;
			pstart = pstart->next;
			plast = plast->next;
		}

		pre->next = 0;
		plast->next = head;
		head = pstart;

		return head;
	}
};
