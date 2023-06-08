
class Solution {
	public:
		int max_depth(TreeNode* root) {
			if (!root) return 0;

			return 1 + max(max_depth(root->left), max_depth(root->right));
		}
};
