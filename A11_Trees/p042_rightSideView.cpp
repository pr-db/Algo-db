#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct TreeNode
{
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
	vector<int> ans;

	void rightside(TreeNode *node, int level)
	{
		if (!node)
			return;
		if (ans.size() < level)
			ans.push_back(node->val);
		rightside(node->right, level + 1);
		rightside(node->left, level + 1);
	}

	vector<int> rightSideView(TreeNode *root)
	{

		if (!root)
			return ans;
		ans.push_back(root->val);
		rightside(root->right, 2);
		rightside(root->left, 2);
		return ans;
	}
};