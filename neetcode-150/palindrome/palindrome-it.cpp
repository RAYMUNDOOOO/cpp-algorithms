#include <vector>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
		std::vector<char> converted_str;

        // Push only alphabet characters into the new vector and convert them to lowercase
        for (char letter : s) {
            if (isalnum(letter)) {
                converted_str.push_back(tolower(letter));
            }
        } 

		// Check the converted string is not empty before continuing
        if (converted_str.empty()) return true;

		// Using an iterator that starts at the beginning and one at the end, compare the values of these iterators
		// The string is considered a palindrome until the moment that the deferenced value of the iterators are not equal!
        for (auto it_start = converted_str.begin(), it_end = prev(converted_str.end()); it_start < it_end; it_start++, it_end--) {
            if (*it_start != *it_end) return false;
        }

        return true; 
    }
};
