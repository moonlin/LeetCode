/**************************************************************************

Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.

**************************************************************************/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		if (head == 0) return 0;

		return mergeTree(head);
	}

	TreeNode* mergeTree(ListNode* head)
	{
		if (!head->next) {
			TreeNode* pRoot = new TreeNode(head->val);

			return pRoot;
		}

		uint numNode = 0;
		ListNode* pLeft = head;
		while (pLeft) {
			pLeft = pLeft->next;
			++numNode;
		}

		pLeft = head;
		for (uint i = 0; i < numNode/2 - 1; ++i) {
			pLeft = pLeft->next;
		}

		ListNode* pNode = pLeft->next;
		pLeft->next = 0;

		TreeNode* pRoot = new TreeNode(pNode->val);
		pRoot->left = mergeTree(head);
		if (pNode->next) {
			pRoot->right = mergeTree(pNode->next);
		}

		return pRoot;
	}

};

