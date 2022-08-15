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
	TreeNode *first, *last, *pre = new TreeNode(INT_MIN);
	void recoverTree(TreeNode *root)
	{
		inorder(root);
		swap(first->val, last->val);
	}
	void inorder(TreeNode *root)
	{
		if (!root)
			return;

		inorder(root->left);

		if (!first && root->val < pre->val)
			first = pre;
		if (first && root->val < pre->val)
			last = root;
		pre = root;

		inorder(root->right);
	}
};