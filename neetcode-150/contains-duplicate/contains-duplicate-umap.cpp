#include <unordered_map>
#include <vector>

class Solution {
	public:
		bool containsDuplicate(std::vector<int>& nums) {
			std::unordered_map<int, int> umap;

			for (auto& num : nums) {
				umap[num]++;
				if (umap[num] >= 2) return true;
			}

			return false;
		}
};
