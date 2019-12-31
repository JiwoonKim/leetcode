/**
 *  Given two binary trees merge the tree nodes into a new binary tree.
 *  If two nodes overlap, the node in the resulting tree should have the sum of the two node values.
 * 
 *  Solution: (1) recursion: O(n) time, O(n) space
 * 
 *  Tip: dealing with 4 cases (OO, X0, 0X, XX)
 *       => if (one X) return two
 *          if (two X) return one
 *          return (OO case ...)
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) Recursion
*/
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    // if only one tree is valid or both trees are null
    if (!t1) return t2;
    if (!t2) return t1;
    /**
     * if both trees exist, sum the overlapping value
     * and merge the left and right sub-trees
     */ 
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}