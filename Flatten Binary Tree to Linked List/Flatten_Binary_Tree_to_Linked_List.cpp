/**************************************************************************

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
If you notice carefully in the flattened tree, 
each node's right child points to the next node of a pre-order traversal.

**************************************************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) 
	{
		if (root == 0) return;
		
		preNode2(root);
    }

	TreeNode* preNode2(TreeNode* node)
	{
		if (node == 0) return 0;

		TreeNode* root = node;
		for (; node->left == 0 && node->right; node = node->right);

		if (node->left == 0 && node->right == 0) return root;

		TreeNode* pLeft = preNode2(node->left);
		TreeNode* pRight = preNode2(node->right);

		node->left = 0;
		node->right = pLeft;
		for (; node->right; node = node->right);

		node->right = pRight;

		return root;
	}

};
