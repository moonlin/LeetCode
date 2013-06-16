/******************************************

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
	 
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

******************************************/


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
    void flatten(TreeNode *root) 
	{
		if (root == 0) return;
		
		preNode(root);
    }

	TreeNode* preNode(TreeNode* node)
	{		
		TreeNode* root = node;
		while (node->left == 0 && node->right) node = node->right;

		if (node->left == 0 && node->right == 0) return root;

		TreeNode* pLeft = preNode(node->left);

		TreeNode* pRight = 0;
		if (node->right) {
			pRight = preNode(node->right);
		}

		node->left = 0;
		node->right = pLeft;
		while (pLeft->right) pLeft = pLeft->right;

		pLeft->right = pRight;

		return root;
	}

};


int main()
{	
	TreeNode* root;

	TreeNode* node1 = new TreeNode(4);
	TreeNode* node2 = new TreeNode(1);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(2);

	node1->left = node2;
	node2->right = node3;
	node3->left = node4;

	root = node1;

	Solution solve;
	solve.flatten(root);

	//std::cout <<"ret == " <<ret <<'\n';

	getchar();
	return 0;
}

