/**********************************************************

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

**********************************************************/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) 
	{
		if (root == 0) return 0;

		int gmax = INT_MIN;
        this->dfs(root, gmax);

		return gmax;
    }

	int dfs(TreeNode* node, int& gmax)
	{
		int maxPath = node->val;
		int max = node->val;
		int retNum;
		if (node->left) {
			retNum = dfs(node->left, gmax);
			if (retNum > 0) {
				maxPath += retNum;
				max += retNum;
			}
		}

		if (node->right) {
			retNum = dfs(node->right, gmax);
			if (retNum > 0) {
				maxPath = std::max(maxPath, retNum + node->val);
				max += retNum;
			}
		}

		gmax = std::max(gmax, max);

		return maxPath;
	}
};

