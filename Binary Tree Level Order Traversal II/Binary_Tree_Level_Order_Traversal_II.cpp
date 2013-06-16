/*******************************Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).For example:Given binary tree {3,9,20,#,#,15,7},    3   / \  9  20    /  \   15   7return its bottom-up level order traversal as:[  [15,7]  [9,20],  [3],]*******************************/#include <iostream>#include <vector>#include <string>#include <queue>#include <map>#include <stack>using namespace std;typedef unsigned int uint;struct TreeNode {	int val;	TreeNode *left;	TreeNode *right;	TreeNode(int x) : val(x), left(NULL), right(NULL) {}};class Solution {public:	vector<vector<int>> levelOrderBottom(TreeNode *root)	{		if (root == 0) return vector<vector<int>> (); 		vector<vector<int>> tree;		queue<TreeNode*> treeQue;		treeQue.push(root);		int levelCnt = 1;		while (!treeQue.empty()) {			int loopCnt = levelCnt;			levelCnt = 0;			vector<int> levelNode;			for (int i = 0; i < loopCnt; ++i) {				TreeNode* pNode = treeQue.front();				treeQue.pop();				levelNode.push_back(pNode->val);				if (pNode->left) {					treeQue.push(pNode->left);					++levelCnt;				}				if (pNode->right) {					treeQue.push(pNode->right);					++levelCnt;				}			}			tree.insert(tree.begin(), levelNode);		}		return tree;	}};TreeNode* makeTree(const string& str);int main(){		string str("3,9,20,#,#,15,7");	TreeNode* root = makeTree(str);	Solution solve;	solve.levelOrderBottom(root);	getchar();	return 0;}TreeNode* makeTree(const string& str){	vector<int> tree;	bool processing = false;	int digit = 0;	for (uint i = 0; i < str.size(); ++i) {		if (str[i] >= '0' && str[i] <= '9') {			processing = true;			digit = digit * 10 + str[i] - '0';		} else if (str[i] == '#') {			tree.push_back((int)str[i]);		} else {			if (processing) {				tree.push_back(digit);				processing = false;				digit = 0;			}		}	}	if (processing) {		tree.push_back(digit);	}	if (tree.empty()) return 0;	TreeNode* root = new TreeNode(tree[0]);	std::queue<std::pair<TreeNode*, int>> treeQue;	treeQue.push(std::pair<TreeNode*, int> (root, 0));	char terminate = '#';	int levelCnt = 1;	int preLeveCnt = 0;	int numCnt = 1;	while (!treeQue.empty()) {		int loopCnt = levelCnt;		numCnt += preLeveCnt * 2;		preLeveCnt = levelCnt;		levelCnt = 0;		for (int i = 0; i < loopCnt; ++i) {			std::pair<TreeNode*, int> node = treeQue.front();			treeQue.pop();			uint index = (uint)(numCnt+i*2);			if ((uint)(index) < tree.size() 				&& tree[index] != (int)terminate)			{				TreeNode* pLeft = new TreeNode(tree[index]);				node.first->left = pLeft;				treeQue.push(std::pair<TreeNode*, int> (pLeft, index));				++levelCnt;			}			index = (uint)(numCnt+i*2+1);			if ((uint)(index) < tree.size() 				&& tree[index] != (int)terminate)			{				TreeNode* pRight= new TreeNode(tree[index]);				node.first->right = pRight;				treeQue.push(std::pair<TreeNode*, int> (pRight, index));				++levelCnt;			}		}	}	return root;}