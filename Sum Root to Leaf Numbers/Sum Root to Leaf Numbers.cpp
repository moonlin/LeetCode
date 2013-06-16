/***

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

***/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

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
    int sumNumbers(TreeNode *root) 
	{
		if (root == 0) return 0;    
        
		this->num = 0;
		vector<uint> vecNum;
		dfs(root, vecNum);
		return this->num;
    }

	void dfs(TreeNode* pNode, vector<uint>& vecNum)
	{
		vecNum.push_back(pNode->val);
		if (pNode->left) {
			dfs(pNode->left, vecNum);
		}

		if (pNode->right) {
			dfs(pNode->right, vecNum);
		}

		if (!pNode->left && !pNode->right) {
			int sum = vecNum[0];
			for (uint i = 1; i < vecNum.size(); ++i) {
				sum = 10 * sum + vecNum[i];
			}

			this->num += sum;
		}

		vecNum.pop_back();
	}

private:
	uint num;
};


int main()
{
	Solution solve;
	TreeNode* node = new TreeNode(4);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(0);
	TreeNode* node3 = new TreeNode(1);

	node->left = node1;
	node->right = node3;
	node1->left = node2;

	solve.sumNumbers(node);

	getchar();
	return 0;
}

