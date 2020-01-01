/**
 *  Given a non-empty array of integers, every element appears twice except for one. 
 *  Find that single one.
 *  (solution must be linear runtime complexity without using extra memory)
 * 
 *  Solution: (1) XOR operation: O(n) time, O(1) space
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) XOR operation
*/
int singleNumber(vector<int> &nums) {
    int bit = 0;
    for (int num : nums) {
        bit ^= num;
    }
    return bit;
}