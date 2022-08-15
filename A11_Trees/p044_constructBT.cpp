#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{

		map<int, int> in;
		int n = inorder.size();
		for (int i = 0; i < n; i++)
			in[inorder[i]] = i;

		TreeNode *root = myTree(preorder, inorder, in, 0, n - 1, 0, n - 1);
		return root;
	}

	TreeNode *myTree(vector<int> &pre, vector<int> &in, map<int, int> &inmap, int ps, int pe, int is, int ie)
	{
		if (ps > pe || is > ie)
			return NULL;
		TreeNode *root = new TreeNode(pre[ps]);
		int inroot = inmap[root->val];
		int numsleft = inroot - is;
		root->left = myTree(pre, in, inmap, ps + 1, ps + numsleft, is, inroot - 1);
		root->right = myTree(pre, in, inmap, ps + numsleft + 1, pe, inroot + 1, ie);
		return root;
	}
};