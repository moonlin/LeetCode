/****************************************Given two binary trees, write a function to check if they are equal or not.Two binary trees are considered equal if they are structurally identical and the nodes have the same value.****************************************/#include <vector>#include <string>#include <queue>#include <map>#include <stack>using namespace std;typedef unsigned int uint;struct TreeNode {	int val;	TreeNode *left;	TreeNode *right;	TreeNode(int x) : val(x), left(NULL), right(NULL) {}};class Solution {public:	bool isSameTree(TreeNode *p, TreeNode *q)	{		if (p && q) {			if (p->val != q->val) return  false;			return isSameTree(p->left, q->left) &&		\				isSameTree(p->right, q->right);		}				return (p == q);	}};TreeNode* makeTree(const string& str);int main(){		string str("1,#,2,3");	TreeNode* pRoot = makeTree(str);	string str2("1,#,3,3");	TreeNode* pRoot2 = makeTree(str2);	Solution solve;	bool ret = solve.isSameTree(pRoot, pRoot2);	getchar();	return 0;}TreeNode* makeTree(const string& str){	vector<int> tree;	bool processing = false;	int digit = 0;	for (uint i = 0; i < str.size(); ++i) {		if (str[i] >= '0' && str[i] <= '9') {			processing = true;			digit = digit * 10 + str[i] - '0';					} else if (str[i] == '#') {			tree.push_back((int)str[i]);		} else {			if (processing) {				tree.push_back(digit);				processing = false;				digit = 0;			}					}	}	if (processing) {		tree.push_back(digit);	}		if (tree.empty()) return 0;	TreeNode* pRoot = new TreeNode(tree[0]);	std::queue<std::pair<TreeNode*, int>> treeQue;	treeQue.push(std::pair<TreeNode*, int> (pRoot, 0));	char terminate = '#';	int levelCnt = 1;	int preLeveCnt = 0;	int numCnt = 1;	while (!treeQue.empty()) {		int loopCnt = levelCnt;		numCnt += preLeveCnt * 2;		preLeveCnt = levelCnt;		levelCnt = 0;		for (int i = 0; i < loopCnt; ++i) {			std::pair<TreeNode*, int> node = treeQue.front();			treeQue.pop();			uint index = (uint)(numCnt+i*2);			if ((uint)(index) < tree.size() 				&& tree[index] != (int)terminate)			{				TreeNode* pLeft = new TreeNode(tree[index]);				node.first->left = pLeft;				treeQue.push(std::pair<TreeNode*, int> (pLeft, index));				++levelCnt;			}			index = (uint)(numCnt+i*2+1);			if ((uint)(index) < tree.size() 				&& tree[index] != (int)terminate)			{				TreeNode* pRight= new TreeNode(tree[index]);				node.first->right = pRight;				treeQue.push(std::pair<TreeNode*, int> (pRight, index));				++levelCnt;			}		}			}	return pRoot;}