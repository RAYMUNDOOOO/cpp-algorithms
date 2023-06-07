#include <algorithm>
#include <vector>

/*
 * Create a sliding window by having two iterators pointing to the left of the "window" and another one 
 * pointing to the right. So long as the right one is lower than the left, you can calculate what the profit 
 * would be for that given range, starting from when you bought the stock (left) and when you could potentially
 * sell it (right).
 *
 * In the event that the value of right is lower than left, shift the window by moving left up to the position
 * of right. This will start the process again to find the max_profit at a new date for when you bought the stock.
 */

class Solution {
	public:
		int max_profit(std::vector<int>& prices) {
			int max_profit = 0;
			std::vector<int>::iterator left;
			std::vector<int>::iterator right;

			while (right != prices.end()) {
				if (*left < *right) max_profit = std::max(max_profit, *right - *left);
				else {
					left = right;
				}

				std::advance(right, 1);
			}

			return max_profit;
		}
};

