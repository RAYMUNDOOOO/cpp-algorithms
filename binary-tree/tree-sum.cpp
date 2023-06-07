#include <string>
#include <stack>

class Node {
	public:
		int  val;
		Node* left;
		Node* right;

		Node(int initial_val) {
			val = initial_val;
			left = nullptr;
			right = nullptr;
		}
};

// ITERATIVE APPROACH
int tree_sum_it(Node* root) {
	if (!root) return 0;

	int sum = 0;
	std::stack<Node*> n_stack;
	n_stack.push(root);

	while (n_stack.size() > 0) {
		Node* current = n_stack.top();
		n_stack.pop();

		sum += current->val;

		if (current->right) n_stack.push(current->right);
		if (current->left) n_stack.push(current->left);
	}

	return sum;
}

// RECURSIVE APPROACH
int tree_sum_rec(Node* root) {
	if (!root) return 0;

	return root->val + tree_sum_rec(root->left) + tree_sum_rec(root->right); // Returns val of root plus some of values in left and right branches
}
