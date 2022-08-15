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
	TreeNode *invertTree(TreeNode *root)
	{
		if (root == NULL)
			return root;
		queue<TreeNode *> q;
		q.push(root);
		while (q.size())
		{
			TreeNode *cur = q.front(), *temp;
			q.pop();
			if (cur == NULL || (cur->left == NULL && cur->right == NULL))
				continue;
			temp = cur->left;
			cur->left = cur->right;
			cur->right = temp;
			q.push(cur->left);
			q.push(cur->right);
		}
		return root;
	}
};