#include <stack>
#include <unordered_map>
#include <string>

/*
 * For every parentheses in the string, see if we can find it in the map. If we can find it,
 * this means that we have hit a closing bracket. We can then check if the stack is empty and then check if the
 * top of the stack matches with the value in the map using the clothing parentheses as the key.
 *
 * If the parentheses is an opening bracket, lets add it to the stack so we can look for it in the next iteration.
 * 
 * Return p_stack.empty() because the stack should be empty if we had all valid parentheses.
 */
class Solution {
	public:
		bool is_valid(std::string s) {
			if (s.size() <= 1) return false;

			std::stack<char> p_stack;
			std::unordered_map<char, char> p_map {
				{')', '('},
				{'}', '{'},
				{']', '['},
			};

			for (auto parentheses : s) {
				if (p_map.find(parentheses) != p_map.end()) {
					if (p_stack.empty()) return false;
					if (p_stack.top() != p_map[parentheses]) return false;
					p_stack.pop();
				} else {
					p_stack.push(parentheses);
				}
			}

			return p_stack.empty();
		}
};
