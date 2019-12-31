/**
 *  Given a binary tree, find its maximum depth.
 *  (= the number of nodes along the longest path from the root node down to the farthest leaf node)
 * 
 *  Solution: (1) DFS: O(n) time, O(log n) space
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) DFS (== recursion)
*/
int maxDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}