/************************************************************

Given an array where elements are sorted in ascending order, 
convert it to a height balanced BST.

************************************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* sortedArrayToBST(std::vector<int>& num)
	{
		if (num.empty()) {
			return 0;
		}

		return mergeTree(num, 0, num.size()-1);
	}

	TreeNode* mergeTree(std::vector<int>& num, int i, int j)
	{
		if (i > j) return 0;
		if (i == j)	{
			TreeNode* pRoot = new TreeNode(num[i]);

			return pRoot;
		}

		int mid = (i + j) / 2;
		TreeNode* pRoot = new TreeNode(num[mid]);
		pRoot->left = mergeTree(num, i, mid-1);
		pRoot->right = mergeTree(num, mid+1, j);

		return pRoot;
	}

};

int main()
{	
	Solution solve;
	vector<int> num;
	for (int i = 0; i < 8; ++i) {
		num.push_back(i+1);
	}

	TreeNode* root = solve.sortedArrayToBST(num);

	getchar();
	return 0;
}
