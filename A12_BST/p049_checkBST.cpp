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
	bool validate(TreeNode *root, TreeNode *low, TreeNode *high)
	{
		if (root == nullptr)
			return true;
		if ((high && root->val >= high->val) || (low && root->val <= low->val))
			return false;
		return validate(root->left, low, root) and validate(root->right, root, high);
	}

	bool isValidBST(TreeNode *root)
	{
		return validate(root, nullptr, nullptr);
	}
};