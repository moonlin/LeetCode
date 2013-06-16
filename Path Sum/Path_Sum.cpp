/**************************************

Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

**************************************/

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
    bool hasPathSum(TreeNode *pRoot, int sum)
	{
		if (pRoot == 0) return false;

		if (pRoot->left == 0 && pRoot->right == 0) {
			if (pRoot->val == sum) {
				return true;
			}
		}

		return hasPathSum(pRoot->left, sum - pRoot->val)? true: 
			hasPathSum(pRoot->right, sum - pRoot->val);
	}

};
