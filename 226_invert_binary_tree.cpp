/**
 *  Invert a binary tree (flip )
 * 
 *  Solution: (1) Recursion: O(n) time, O(n) space
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) Recursion
*/

TreeNode *invertTree(TreeNode *root) {
    if (root) {
        TreeNode *newLeft = nullptr;
        TreeNode *newRight = nullptr;
        if (root->left) newLeft = invertTree(root->left);
        if (root->right) newRight = invertTree(root->right);
        root->left = newRight;
        root->right = newLeft;
    }
    return root;
}