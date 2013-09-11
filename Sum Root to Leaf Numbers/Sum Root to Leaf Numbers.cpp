/***********************************************************************************

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

***********************************************************************************/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) 
	{
		if (root == 0) return 0;    
        
		this->num = 0;
		std::vector<uint> vecNum;
		this->dfs(root, vecNum);

		return this->num;
    }

	void dfs(TreeNode* pNode, vector<uint>& vecNum)
	{
		if (pNode == 0) return;

		if (!pNode->left && !pNode->right) {
			uint sum = 0;
			for (uint i = 0; i < vecNum.size(); ++i) {
				sum = sum*10 + vecNum[i];
			}

			sum = sum*10 + pNode->val;
			this->num += sum;
			return;
		}

		vecNum.push_back(pNode->val);
		dfs(pNode->left, vecNum);
		dfs(pNode->right, vecNum);
		vecNum.pop_back();
	}

private:
	uint num;
};
