/****************

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

****************/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <map>

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
    int maxPathSum(TreeNode *root) 
	{
		if (root == 0) return 0;

		int gmax = INT_MIN;
        dp(root, gmax);

		return gmax;
    }

	int dp(TreeNode* node, int& gmax)
	{
		
		int maxPath = node->val;
		int max = node->val;
		int retNum;
		if (node->left) {
			retNum = dp(node->left, gmax);
			if (retNum > 0) {
				maxPath += retNum;
				max += retNum;
			}
		}

		if (node->right) {
			retNum = dp(node->right, gmax);
			if (retNum > 0) {
				maxPath = std::max(maxPath, retNum + node->val);
				max += retNum;
			}
		}

		gmax = std::max(gmax, max);

		return maxPath;
	}
};


int main()
{
	TreeNode* pNode = new TreeNode(-2);
	TreeNode* pNode2 = new TreeNode(1);
	pNode->left = pNode2;


	Solution solve;
	int cnt = solve.maxPathSum(pNode);

	std::cout <<"NUM == " <<cnt <<'\n';

	getchar();
	return 0;
}

