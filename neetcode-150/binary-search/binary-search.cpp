#include <vector>

/*
 * Think of this like trying to look for a name in an address book. You wouldn't 
 * start from the beginning and then go through every name in the book in alphabetical order, would you?
 */

class Solution {
	public:
		int search(std::vector<int>& nums, int target) {
			std::vector<int>::iterator low = nums.begin();
			std::vector<int>::iterator high = std::prev(nums.end());

			while (low <= high) {
				std::vector<int>::iterator mid = low + (high - low) / 2;
				
				if (*mid < target) {
					low = mid + 1;
				} else if (*mid > target) {
					high = mid - 1;
				}

				return mid - nums.begin();
			}
		
			return -1;
		}
};
