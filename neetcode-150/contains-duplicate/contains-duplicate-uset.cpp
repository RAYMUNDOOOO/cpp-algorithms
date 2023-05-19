#include <vector>
#include <unordered_set>

class Solution {
	public:
		bool containsDuplicate(std::vector<int>& nums) {
			std::unordered_set<int> uset;

			for (auto& num : nums) {
				if (uset.find(num) != uset.end()) return true;	
				uset.insert(num);	
			}

			return false;
		}
};

