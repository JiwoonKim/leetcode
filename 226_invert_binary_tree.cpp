/**
 *  Invert a binary tree (flip )
 * 
 *  Solution: (1) Recursive (preorder, DFS): O(n) time, O(n) space
 *            (2) Iterative (~= BFS): O(n) time, O(n) space
 *                - use stack data structure instead of call stack
 * 
*/
#include <bits/stdc++.h>
using namespace std;

/**
 *  (1) Recursive (preorder)
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

/**
 *  (2) Iterative
*/
TreeNode *invertTree(TreeNode *root) {
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty() && s.top()) {
        TreeNode *current = s.top();
        s.pop();
        if (current->left) s.push(current->left);
        if (current->right) s.push(current->right);
        TreeNode *temp = current->left;
        current->left = current->right;
        current->right = temp;
    }
    return root;
}