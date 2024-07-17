/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <stack>
// #include <queue>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;

class Solution {
private:
    int traverse(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = traverse(root->left);
        int rightHeight = traverse(root->right);
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }
        if (leftHeight - rightHeight > 1 || leftHeight - rightHeight < -1) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        int height = traverse(root);
        if (height == -1) return false;
        return true;
    }
};
// @lc code=end

