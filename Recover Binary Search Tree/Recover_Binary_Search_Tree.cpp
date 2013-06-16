/***************************************

 Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

***************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;
typedef unsigned int uint;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void recoverTree(TreeNode *root)
	{
		if (root == 0) return;

		TreeNode* pre = 0;
		TreeNode* pe1 = 0;
		TreeNode* pe2 = 0;
		traverse(root, pre, pe1, pe2);
		if (pe1 && pe2) {
			std::swap(pe1->val, pe2->val);
		}
	}

	void traverse(TreeNode* pNode, TreeNode*& pre, TreeNode*& pe1, TreeNode*& pe2)
	{
		if (pNode == 0)	return;

		traverse(pNode->left, pre, pe1, pe2);
		if (pre && pre->val >= pNode->val) {
			if (!pe1) {
				pe1 = pre;
				pe2 = pNode;
			} else { // we assume only two element was swaped...
				pe2 = pNode;
			}
		}

		pre = pNode;
		traverse(pNode->right, pre, pe1, pe2);
	}

};
