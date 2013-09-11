/*********************************************************************************

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.

*********************************************************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode *root)
	{
		if (!root) {
			return true;
		}

		long depth;
		return traverse(root, depth);
	}

	bool traverse(TreeNode* node, long& height) 
	{
		if (!node->left && !node->right) {
			height = 1;
			return true;
		}

		long lHeight = 0;
		if (node->left) {
			if (!traverse(node->left, lHeight)) {
				return false;
			}
		}

		long rHeight = 0;
		if (node->right) {
			if (!traverse(node->right, rHeight)) {
				return false;
			}
		}

		height = std::max(lHeight, rHeight) + 1;
		return abs(lHeight-rHeight) < 2;
	}
};
