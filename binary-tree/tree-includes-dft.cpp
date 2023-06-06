#include <string>
#include <stack>

class Node {
	public:
		std::string val;
		Node* left;
		Node* right;

		Node(std::string initial_val) {
			val = initial_val;
			left = nullptr;
			right = nullptr;
		}
};

// ITERATIVE APPROACH
bool tree_includes_it(Node* root, std::string target_val) {
	if (!root) return false;

	// Create a stack to keep track of traversal
	std::stack<Node*> n_stack;
	n_stack.push(root);

	// While the stack isn't empty we can keep traversing
	while (n_stack.size() > 0) {
		Node* current = n_stack.top();
		n_stack.pop();
		if (current->val == target_val) return true; // If current matches the target_val, return true
	
		if (current->right) n_stack.push(current->right);
		if (current->left) n_stack.push(current->left);
	}

	return false;
}

// RECURSIVE APPROACH
bool tree_includes_rec(Node* root, std::string target_val) {
	if (!root) return false;
	if (root->val == target_val) return true;

	return tree_includes_rec(root->left, target_val) || tree_includes_rec(root->right, target_val);
}	
