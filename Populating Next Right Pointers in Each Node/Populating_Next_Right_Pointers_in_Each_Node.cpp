/*********************************

 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL


*********************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>

using namespace std;
typedef unsigned int uint;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root)
	{
		if (root == 0) return;

		if (root->left) {
			root->left->next = root->right;
			traverse(root->left, root->right);
		}

	}

	// You may only use constant extra space.
	// so we may only dfs level by level, not bfs, because that may use extra space
	void traverse(TreeLinkNode* p, TreeLinkNode* q)
	{
		if (p->left == 0 || p->right == 0) return;

		p->left->next = p->right;
		p->right->next = q->left;
		q->left->next = q->right;
		q->right->next = q->next? q->next->left: 0;

		traverse(q->left, q->right);
		traverse(p->left, p->right);
	}
};
