/*************************************

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

*************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;
typedef unsigned int uint;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		this->traverse(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
	}

	TreeNode* traverse(vector<int>& preorder, int pre_s, int pre_e,
		vector<int>& inorder, int in_s, int in_e)
	{
		if (pre_s > pre_e || in_s > in_e) return 0;

		TreeNode* pRoot = new TreeNode(preorder[pre_s]);
		if (pre_s == pre_e) {
			return pRoot;
		}

		int mid = in_s;
		for (; mid <= in_e; ++mid) {
			if (pRoot->val == inorder[mid])
				break;
		}

		if (mid > in_e) return 0;

		pRoot->left = traverse(preorder, pre_s+1, pre_s+mid-in_s,
			inorder, in_s, mid-1);

		pRoot->right = traverse(preorder, pre_s+mid-in_s+1, pre_e,
			inorder, mid+1, in_e);

		return pRoot;
	}

};
