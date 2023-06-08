#include <queue>

class Solution {
	public:
		int max_depth(TreeNode* root) {
			if (!root) return 0;

			// Create a queue for us to traverse the tree using BFT
			std::queue<TreeNode*> t_queue;
			t_queue.push(root);

			// Results
			int max_depth = 0;
			int nodes_in_row = 0; // To keep track of each level we're traversing
		
			while (t_queue.size() > 0) {
				nodes_in_row = t_queue.size();

				for (int i = 0; i < nodes_in_row; i++) {
					TreeNode* current = t_queue.front();
					t_queue.pop();

					if (current->left) t_queue.push(current->left);
					if (current->right) t_queue.push(curret->right);
				}

				max_depth++;
			}

			return max_depth;
		}
};
