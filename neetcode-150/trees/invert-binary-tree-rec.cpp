#include <stack>

// NOTE: This is the iterative approach to inverting the binary tree

 // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if (!root) return root;

		std::swap(root->left, root->right);

		invertTree(root->left);
		invertTree(root->right);

		return root;
    }
};
