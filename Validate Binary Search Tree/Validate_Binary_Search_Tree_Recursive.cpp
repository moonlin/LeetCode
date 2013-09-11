/**********************************
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

**********************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root)
	{
		if (root == 0) return true;

		return traverse(root, INT_MIN, INT_MAX);
	}

	bool traverse(TreeNode* pNode, int min, int max)
	{
		if (pNode == 0) return true;
		if (pNode->val <= min || pNode->val >= max) return false;

		return traverse(pNode->left, min, pNode->val) && \
				traverse(pNode->right, pNode->val, max);
	}

};
