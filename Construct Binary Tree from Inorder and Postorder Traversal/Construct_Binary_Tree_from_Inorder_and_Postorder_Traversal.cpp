/******************************************

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

******************************************/

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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		this->traverse(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
	}

	TreeNode* traverse(vector<int>& postorder, int post_s, int post_e,
		vector<int>& inorder, int in_s, int in_e)
	{
		if (in_s > in_e || post_s > post_e) return 0;

		TreeNode* pRoot = new TreeNode(postorder[post_e]);
		if (in_s == in_e) {
			return pRoot;
		}

		int mid = in_s;
		for (; mid <= in_e; ++mid) {
			if (pRoot->val == inorder[mid])
				break;
		}

		if (mid > in_e) return 0;

		pRoot->left = traverse(postorder, post_s, post_s+mid-in_s-1,
			inorder, in_s, mid-1);

		pRoot->right = traverse(postorder, post_s+mid-in_s, post_e-1,
			inorder, mid+1, in_e);

		return pRoot;
	}

};
