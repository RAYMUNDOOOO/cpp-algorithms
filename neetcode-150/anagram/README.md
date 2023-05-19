# Overview
**Link: ** https://leetcode.com/problems/valid-anagram/description/
**Difficulty: ** Easy
**Time complexity: **  
**Space complexity: **  

The goal of this particular problem is to determine if both strings are
anagrams of one another. As in, **using the letters of string t, you can create
string s**.

** For exampple:** s = cat; t = atc; result = true

# Method
Before using any of these methods, it is advised to **check if both strings are 
the same size**. It *cannot* be an anagram otherwise.

## Using an unordered map
Create an unordered map with the amount of occurrences of each particular character
in a given string. 

Then, for each character in the second string, see if you can find it in the map
and then decrement the value associated with it. If you cannot find it, or the value
associated with the key is less than 0, return false as that means you do not
have the letters necessary to construct the string or you have too many.

## Sorting first
Another way you can do this is by sorting both strings. Using their respective ASCII
values, you can compare if one character is "greater" than another. 

Once sorted, if both strings are equal, then it is an anagram and you can return true.

# References
- https://en.cppreference.com/w/cpp/container/unordered_map/find
- https://www.youtube.com/watch?v=9UtInBqnCgA
