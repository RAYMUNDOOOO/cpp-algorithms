#include <vector>

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int>::iterator it_outer;
			vector<int>::iterator it_inner;
			vector<int> result;

			/*
			 * For each number in the vector, nums, check the sum of it with every other number
			 * to determine if it equals target.
			 * If the index of the outer iterator and the inner iterator are equal, skip that iteration 
			 * of the loop because we cannot add numbers at the same index together.
			 */
			for (it_out = nums.begin(); it_outer != nums.end(); it_outer++) {
				for (it_inner = nums.begin(); it_inner != nums.end(); it_inner++) {
					if (it_outer == it_inner) continue;

					if (*it_outer + *it_inner == target) {
						result.push_back(it_outer - nums.begin());
						result.push_back(it_inner - nums.begin());
						return result;
					}
				}
			}

			return result;
		}
};
