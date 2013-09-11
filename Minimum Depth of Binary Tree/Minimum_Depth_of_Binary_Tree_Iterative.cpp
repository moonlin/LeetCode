/**********************************************************************Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.**********************************************************************/struct TreeNode {	int val;	TreeNode *left;	TreeNode *right;	TreeNode(int x) : val(x), left(NULL), right(NULL) {}};class Solution {public:	int minDepth(TreeNode* root)	{		if (root == 0) return 0;		std::queue<TreeNode*> treeQue;		treeQue.push(root);		int path = 0;		int levelCnt = 1;		while (!treeQue.empty()) {			++path;			int loopCnt = levelCnt;			levelCnt = 0;			for (int i = 0; i < loopCnt; ++i) {				TreeNode* pNode = treeQue.front();				treeQue.pop();				if (pNode->left == 0 && pNode->right == 0) {					return path;				}				if (pNode->left) {					++levelCnt;					treeQue.push(pNode->left);				}				if (pNode->right) {					++levelCnt;					treeQue.push(pNode->right);				}			}		}		return 0;	}};