/*******************************

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

*******************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) 
	{
		if (root == 0) return vector<int> ();

		TreeNode* pNode = root;
		std::vector<int> treeNode;
		std::stack<TreeNode*> treeStack;

		do {
			treeStack.push(pNode);
		} while (pNode = pNode->left);

		while (!treeStack.empty()) {
			pNode = treeStack.top();
			treeStack.pop();
			treeNode.push_back(pNode->val);
			if (pNode->right) {
				pNode = pNode->right;
				treeStack.push(pNode);
				while (pNode->left) {
					pNode = pNode->left;
					treeStack.push(pNode);
				}
			}
		}

		return treeNode;
	}
};


TreeNode* makeTree(const string& str);

int main()
{	
	string str("1,#,2,3");
	TreeNode* pRoot = makeTree(str);

	Solution solve;
	vector<int> ret = solve.inorderTraversal(pRoot);

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

