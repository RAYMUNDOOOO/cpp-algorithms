#include <unordered_map>
#include <string>

class Solution {
	public:
		bool isAnagram(std::string s, std::string t) {
			std::unordered_map<char, int> umap; // I love unordered maps <3

			// Immediately checking if both strings are the same size
			if (s.size() != t.size()) return false;

			/*
			 * Initialise the umap with the characters in string s and count the occurrences 
			 * of each character.
			 *
			 * The idea behind this is that when we compare string t to the map and find the relevant 
			 * character, we can decrement the value! If they are anagrams, all the keys in the map
			 * will have a value of 0 associated with them.
			 */
			for (char letter : s) {
				umap[letter]++;
			}


			// Find the letter in the map and decrement it if found, then check if < 0
			for (char letter : t) {
				if (auto it = umap.find(letter); it != umap.end()) {
					it->second--;
					if (it->second < 0) return false;
				} else {
					return false;
				}
			}
			
			return true;
		}
};
