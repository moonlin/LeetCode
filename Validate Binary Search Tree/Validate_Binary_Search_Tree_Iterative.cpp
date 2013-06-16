/**********************************

 Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

**********************************/

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
	bool isValidBST(TreeNode* root)
	{
		if (root == 0) return true;

		std::stack<TreeNode*> treeStack;
		treeStack.push(root);
		TreeNode* pNode = root;
		while (pNode->left) {
			treeStack.push(pNode->left);
			pNode = pNode->left;
		}

		TreeNode mute(INT_MIN);
		TreeNode* preNode = &mute;
		while (!treeStack.empty()) {
			pNode = treeStack.top();
			treeStack.pop();
			if (preNode->val >= pNode->val) return false;

			preNode = pNode;
			if (pNode->right) {
				pNode = pNode->right;
				while (pNode) {
					treeStack.push(pNode);
					pNode = pNode->left;
				}
			}
		}

		return true;
	}

};

TreeNode* makeTree(const string& str);

int main()
{	
	string str("1");
	TreeNode* pRoot = makeTree(str);

	Solution solve;
	bool ret = solve.isValidBST(pRoot);

	getchar();
	return 0;
}

TreeNode* makeTree(const string& str)
{
	vector<int> tree;
	bool processing = false;
	int digit = 0;
	for (uint i = 0; i < str.size(); ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			processing = true;
			digit = digit * 10 + str[i] - '0';
			
		} else if (str[i] == '#') {
			tree.push_back((int)str[i]);
		} else {
			if (processing) {
				tree.push_back(digit);
				processing = false;
				digit = 0;
			}
			
		}
	}

	if (processing) {
		tree.push_back(digit);
	}
	
	if (tree.empty()) return 0;

	TreeNode* pRoot = new TreeNode(tree[0]);
	std::queue<std::pair<TreeNode*, int>> treeQue;
	treeQue.push(std::pair<TreeNode*, int> (pRoot, 0));
	char terminate = '#';
	int levelCnt = 1;
	int preLeveCnt = 0;
	int numCnt = 1;
	while (!treeQue.empty()) {
		int loopCnt = levelCnt;
		numCnt += preLeveCnt * 2;
		preLeveCnt = levelCnt;
		levelCnt = 0;
		for (int i = 0; i < loopCnt; ++i) {
			std::pair<TreeNode*, int> node = treeQue.front();
			treeQue.pop();
			uint index = (uint)(numCnt+i*2);
			if ((uint)(index) < tree.size() 
				&& tree[index] != (int)terminate)
			{
				TreeNode* pLeft = new TreeNode(tree[index]);
				node.first->left = pLeft;
				treeQue.push(std::pair<TreeNode*, int> (pLeft, index));
				++levelCnt;
			}

			index = (uint)(numCnt+i*2+1);
			if ((uint)(index) < tree.size() 
				&& tree[index] != (int)terminate)
			{
				TreeNode* pRight= new TreeNode(tree[index]);
				node.first->right = pRight;
				treeQue.push(std::pair<TreeNode*, int> (pRight, index));
				++levelCnt;
			}

		}
		
	}

	return pRoot;
}
