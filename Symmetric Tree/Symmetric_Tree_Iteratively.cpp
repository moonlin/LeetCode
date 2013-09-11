/*******************************************
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

*******************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root)
	{
		if (root == 0) return true;

		return traverse(root->left, root->right);
	}

	bool traverse(TreeNode* p, TreeNode* q)
	{
		if (p && q) {
			std::queue<TreeNode*> treeQue;
			treeQue.push(p);
			std::deque<TreeNode*> treeQueMirror;
			treeQueMirror.push_front(q);
			int levelCnt = 1;
			while (!treeQue.empty() && !treeQueMirror.empty()) {
				int loopCnt = levelCnt;
				levelCnt = 0;
				for (int i = 0; i < loopCnt; ++i) {
					TreeNode* pNode = treeQue.front();
					treeQue.pop();
					TreeNode* pMirror = treeQueMirror.back();
					treeQueMirror.pop_back();
					if (pNode->val != pMirror->val) return false;

					if (pNode->left && pMirror->right) 
					{
						treeQue.push(pNode->left);
						treeQueMirror.push_front(pMirror->right);
						++levelCnt;
					} else {
						if (pNode->left != pMirror->right) return false;
					}

					if (pNode->right && pMirror->left) 
					{
						treeQue.push(pNode->right);
						treeQueMirror.push_front(pMirror->left);
						++levelCnt;
					} else {
						if (pNode->right != pMirror->left) return false;
					}
				}
			}

			return treeQue.empty() && treeQueMirror.empty();
		}

		return p == q;
	}

};
