/* GOAL: Determine whether the given ransom_note can be constructed out of the characters
 * available in the magazine.
 *
 * EXAMPLE: ransom_note = aab; magazine = baa; expected_result = true;
 *
 * METHOD: 
 * 	1. Create an array of integers specifically of size 128 and initialise all values to 0. This size is used because it 
 * 		covers the entire ASCII range and will be used later to determine if any characters are available in the magazine 
 * 		to contruct the ransom_note.
 *
 * 	2. For each letter in the ransom_note, check if there is an occurence of it in the array we previously initialised.
 * 		By passing in the character as an index to the array of integers, the character is converted to its ASCII code
 * 		and therefore, we can determine how many letters have been counted at that specific index.
 *
 * 		In the case of this example, using 'a' as an index evaluates to 97, so therefore we are searching in letter_occurrences[97].
 * 		Pretty awesome, right?
 *
 * 	3. If the value at that index is a 0, then we return false because there are no characters available in the magazine.
 * 		If the value is not 0, then we decrement the value at that index to indicate that we have retrieved one letter from the magazine.
 *
 * 	4. Return true if we haven't returned false from any of the previous conditions.
 */
#include <string>

class Solution {
	public:
		bool can_construct(std::string ransom_note, std::string magazine) {
			int letter_occurences[128] = {0};
			for (char magazine_letter : magazine) {
				letter_occurences[magazine_letter]++;
			}

			for (char ransom_letter : ransom_note) {
				if (letter_occurences[ransom_letter] == 0) {
					return false;
				} else {
					letter_occurences[ransom_letter]--;
				}
			}

			return true;
		}
};
