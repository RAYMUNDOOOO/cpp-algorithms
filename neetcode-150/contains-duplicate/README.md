# Overview
**Difficulty:** Easy
**Time complexity:**
**Space complexity:**

The goal of this particular problem is to ascertain whether we have a duplicate
number in our input vector.

** For example:** [1, 2, 3, 3, 5, 6, 6] contains a duplicate.

# Method
## Using an unordered map
This was the first method that I used to solve this problem. The unordered map consists
of a key-pair value, where the **key** is the particular number and the **pair** is the
*number of occurrences* of that number.

I would iterate through the entire vector of `nums` and **add** it to the `unordered_map` as a key value,
and then **incrementing the value associated with it**. After incrementing, **check if the value is >= 2**
and if it is, return true.

Although this method works, **keeping track of the occurrences of a particular number is
unnecessary.** We only need to determine if a number exists in our new data container, and if 
it exists, then we return true; otherwise, we insert the new number into our data container.

*This is where the* `unordered_set` *method comes in.*

## Using an unordered set
Very similar to the method above in that we are attempting to iterate through the entire vector of `nums`.
For each number in the vector, we attempt to **find if it exists as a key** in the set, and if it does, return true.
Otherwise, we can **insert the new number into the set** so that it can be checked in the next iteration of the loop.

# References
- https://cplusplus.com/reference/unordered_set/unordered_set/
- https://en.cppreference.com/w/cpp/container/unordered_map

