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

        std::stack<TreeNode*> traversal_stack;
        traversal_stack.push(root);

        while (traversal_stack.size() > 0) {
            TreeNode* current = traversal_stack.top();
            traversal_stack.pop();

            // Swap the nodes
			std::swap(current->left, current->right);

            // Push these into the stack
            if (current->right) traversal_stack.push(current->right);
            if (current->left) traversal_stack.push(current->left);
        }

        return root;
    }
};
