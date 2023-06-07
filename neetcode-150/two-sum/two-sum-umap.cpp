#include <unordered_map>
#include <vector>

class Solution {
	public:
		std::vector<int> two_sum(std::vector<int>& nums, int target) {
			/*
			 * Create a hash map and try to find the complement (target - nums[i]) in the map.
			 * If it can be found, push the index of that complement and i into a vector and return it.
			 * Otherwise, we can insert it into the map for the next iteration of the loop.
			 */
			std::unordered_map<int, int> umap;
			std::vector<int> result;

			for (int i = 0; i < nums.size(); i++) {
				int complement = target - nums[i];

				if (umap.find(complement) != umap.end()) {
					result.push_back(umap[complement]);
					result.push_back(i);
					return result;
				}

				// Otherwise we can insert the value at num[i] and i into the hash map
				umap.insert({nums[i], i});
			}

			return result;
		}
};
