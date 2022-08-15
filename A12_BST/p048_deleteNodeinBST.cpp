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
	TreeNode *deleteNode(TreeNode *root, int val)
	{
		if (!root)
			return root;
		if (root->val == val)
			return shift(root);

		TreeNode *node = root;

		while (node)
		{
			if (node->val > val)
			{
				if (node->left && node->left->val == val)
				{
					node->left = shift(node->left);
					break;
				}
				else
					node = node->left;
			}
			else
			{
				if (node->right && node->right->val == val)
				{
					node->right = shift(node->right);
					break;
				}
				else
					node = node->right;
			}
		}
		return root;
	}

	TreeNode *shift(TreeNode *root)
	{
		if (!root->right)
			return root->left;
		if (!root->left)
			return root->right;

		TreeNode *rightChild = root->right;
		TreeNode *rightMost = findRight(root->left);
		rightMost->right = rightChild;

		return root->left;
	}

	TreeNode *findRight(TreeNode *root)
	{
		if (!root->right)
			return root;
		return findRight(root->right);
	}
};