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

		std::stack<TreeNode*> treeStack;
		TreeNode* pNode = root;
		treeStack.push(pNode);
		while (pNode->left) {
			treeStack.push(pNode->left);
			pNode = pNode->left;
		}

		TreeNode mute(INT_MIN);
		TreeNode* preNode = &mute;
		while (!treeStack.empty()) {
			pNode = treeStack.top();
			treeStack.pop();
			if (preNode->val >= pNode->val) return false;

			preNode = pNode;
			pNode = pNode->right;
			while (pNode) {
				treeStack.push(pNode);
				pNode = pNode->left;
			}
		}

		return true;
	}

};
