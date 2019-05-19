/**
 *  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *  (You may assume that each input would have exactly one solution, 
 *   and you may not use the same element twice)
 * 
 *  Solution: (1) brute-force method: O(n^2) time, O(1) space
 *            (2) two-pass hash table: O(n) time, O(n) space
 *            (3) one-pass hash table: O(n) time, O(n) space
 *  => try to solve s/ one-pass hash table
*/

#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) Brute-force Method
*/
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // iterate over each number in nums 
        for (int i = 0, n = nums.size(); i < n; i++) {

            int match = target - nums[i];

            // to find match in other numbers in nums
            for (int j = i + 1; j < n; j++) {
                if (match == nums[j]) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

/**
 *  (2) Two-pass Hash Table
*/
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // create a map to hold (number, index)
        unordered_map<int, int> check;

        // first store all nums into map -> to improve lookup to O(1)
        for (int i = 0, n = nums.size(); i < n; i++) {
            check.insert(make_pair(nums[i], i));
        }

        // iterate over all nums to find match
        for (int i = 0, n = nums.size(); i < n; i++) {

            int match = target - nums[i];

            // check for match and make sure match is not itself
            if (check.count(match) > 0 && check[match] != i) {
                return {i, check[match]};
            }
        }
        return {};
    }
};

/**
 *  (3) One-pass Hash Table
*/
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // create a map to hold (number, index)
        unordered_map<int, int> prevNums;

        // iterate over each element
        for (int i = 0, n = nums.size(); i < n; i++) {

            /* check if there is a match in previously stored elements
               (ensures that match is not itself)                      
            */
            int match = target - nums[i];
            if (prevNums.count(match) > 0) {
                return {i, prevNums[match]};
            }
            // if not match, store into prevNums hash map to check later
            prevNums[nums[i]] = i; 
        }
        return {};
    }
};